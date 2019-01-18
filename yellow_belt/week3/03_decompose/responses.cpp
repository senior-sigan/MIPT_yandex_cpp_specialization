#include "responses.h"

using namespace std;

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