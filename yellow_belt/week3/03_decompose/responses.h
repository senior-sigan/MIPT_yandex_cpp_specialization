#pragma once

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

struct BusesForStopResponse {
  std::vector<std::string> buses;
};

std::ostream& operator<<(std::ostream&, const BusesForStopResponse&);

struct StopsForBusResponse {
  std::vector<std::pair<std::string, std::vector<std::string>>> routes;  // stop and vector of buses
};

std::ostream& operator<<(std::ostream&, const StopsForBusResponse&);

struct AllBusesResponse {
  std::map<std::string, std::vector<std::string>> buses;
};

std::ostream& operator<<(std::ostream&, const AllBusesResponse&);