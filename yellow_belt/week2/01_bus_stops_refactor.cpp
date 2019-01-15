#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

enum class QueryType { NewBus, BusesForStop, StopsForBus, AllBuses };

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator>>(istream& is, Query& q) {
  string query_type;
  is >> query_type;
  if (query_type == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  } else if (query_type == "NEW_BUS") {
    q.type = QueryType::NewBus;
    int stops_count;
    is >> q.bus >> stops_count;
    q.stops = vector<string>(stops_count);
    for (string& stop : q.stops) {
      is >> stop;
    }
  } else if (query_type == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (query_type == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  }
  return is;
}

struct BusesForStopResponse {
  vector<string> buses;
};

ostream& operator<<(ostream& os, const BusesForStopResponse& r) {
  if (r.buses.size() == 0) {
    os << "No stop";
    return os;
  }

  int i = r.buses.size();
  for (auto bus : r.buses) {
    os << bus;
    if (--i > 0) os << " ";
  }

  return os;
}

struct StopsForBusResponse {
  vector<pair<string, vector<string>>> routes;  // stop and vector of buses
};

ostream& operator<<(ostream& os, const StopsForBusResponse& r) {
  if (r.routes.size() == 0) {
    os << "No bus";
    return os;
  }

  int i = r.routes.size();
  for (auto kv : r.routes) {
    os << "Stop " << kv.first << ":";

    for (auto bus : kv.second) {
      os << " " << bus;
    }
    if (kv.second.size() == 0) {
      os << " no interchange";
    }
    if (--i > 0) os << endl;
  }
  return os;
}

struct AllBusesResponse {
  map<string, vector<string>> buses;
};

ostream& operator<<(ostream& os, const AllBusesResponse& r) {
  if (r.buses.empty()) {
    os << "No buses";
    return os;
  }

  int i = r.buses.size();
  for (auto bus : r.buses) {
    os << "Bus " << bus.first << ":";
    for (auto stop : bus.second) {
      os << " " << stop;
    }
    if (--i > 0) os << endl;
  }
  return os;
}

class BusManager {
 public:
  void AddBus(const string& bus, const vector<string>& stops) {
    for (auto stop : stops) {
      stops_[stop].push_back(bus);
      buses_[bus].push_back(stop);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    if (stops_.count(stop) == 0) {
      return {};
    }

    return {stops_.at(stop)};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    if (buses_.count(bus) == 0) {
      return {};
    }

    vector<pair<string, vector<string>>> route;
    for (auto stop : buses_.at(bus)) {
      vector<string> buses;
      if (stops_.count(stop) != 0) {
        for (auto b : stops_.at(stop)) {
          if (b == bus) continue;
          buses.push_back(b);
        }
      }
      route.push_back(make_pair(stop, buses));
    }

    return {route};
  }

  AllBusesResponse GetAllBuses() const {
    return {buses_};
  }

 private:
  map<string, vector<string>> buses_;
  map<string, vector<string>> stops_;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
      case QueryType::NewBus:
        bm.AddBus(q.bus, q.stops);
        break;
      case QueryType::BusesForStop:
        cout << bm.GetBusesForStop(q.stop) << endl;
        break;
      case QueryType::StopsForBus:
        cout << bm.GetStopsForBus(q.bus) << endl;
        break;
      case QueryType::AllBuses:
        cout << bm.GetAllBuses() << endl;
        break;
    }
  }

  return 0;
}
