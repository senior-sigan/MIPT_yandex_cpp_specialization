#include "query.h"

using namespace std;

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