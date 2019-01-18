#include "bus_manager.h"
#include <utility>

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
  for (auto stop : stops) {
    stops_[stop].push_back(bus);
    buses_[bus].push_back(stop);
  }
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
  if (stops_.count(stop) == 0) {
    return {};
  }

  return {stops_.at(stop)};
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
  if (buses_.count(bus) == 0) {
    return {};
  }

  std::vector<std::pair<std::string, std::vector<std::string>>> route;
  for (auto stop : buses_.at(bus)) {
    std::vector<std::string> buses;
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

AllBusesResponse BusManager::GetAllBuses() const {
  return {buses_};
}