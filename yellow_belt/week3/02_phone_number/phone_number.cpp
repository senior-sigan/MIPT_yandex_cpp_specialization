#include "phone_number.h"
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

namespace inner {
struct Context {
  std::string country;
  std::string city;
  std::string number;
};

class Handler {
 public:
  virtual void act(char ch, Context& ctx) const = 0;
};

class CountryHandler : public Handler {
 public:
  void act(char ch, Context& ctx) const {
    ctx.country += ch;
  }
};
class CityHandler : public Handler {
 public:
  void act(char ch, Context& ctx) const {
    ctx.city += ch;
  }
};
class NumberHandler : public Handler {
 public:
  void act(char ch, Context& ctx) const {
    ctx.number += ch;
  }
};
class SkipHandler : public Handler {
 public:
  void act(char ch, Context& ctx) const {
    // nothing to do
  }
};
class FailHandler : public Handler {
 public:
  void act(char ch, Context& ctx) const {
    throw std::invalid_argument("");
  }
};

struct Transition {
  const std::string next;
  const Handler* handler;
};

class Automata {
  std::string state = "read";

  std::string Convert(char ch) {
    if (ch == '-') return "-";
    if (ch == '+') return "+";
    return "num";  // Проверять, что номер содержит только цифры, не нужно.
  }

  CountryHandler countryHandler;
  CityHandler cityHandler;
  NumberHandler numberHandler;
  SkipHandler skipHandler;
  FailHandler failHandler;

  const map<string, map<string, Transition>> table = {
      {"read", {{"+", {"read_country", &skipHandler}}}},
      {"read_country", {{"num", {"read_country+", &countryHandler}}}},
      {"read_country+", {{"num", {"read_country+", &countryHandler}}, {"-", {"read_city", &skipHandler}}}},
      {"read_city", {{"num", {"read_city+", &cityHandler}}}},
      {"read_city+", {{"num", {"read_city+", &cityHandler}}, {"-", {"read_number", &skipHandler}}}},
      {"read_number", {{"num", {"read_number", &numberHandler}}, {"-", {"read_number", &numberHandler}}}}
      //
  };

 public:
  Context Run(const string& str) {
    Context ctx;
    for (const auto& ch : str) {
      if (table.count(state) == 0) failHandler.act(ch, ctx);
      auto t1 = table.at(state);
      auto symbol = Convert(ch);
      if (t1.count(symbol) == 0) failHandler.act(ch, ctx);
      auto transition = t1.at(symbol);
      state = transition.next;
      transition.handler->act(ch, ctx);
    }
    if (ctx.city.empty() || ctx.country.empty() || ctx.number.empty()) {
      failHandler.act(0, ctx);
    }
    return ctx;
  }
};
}

PhoneNumber::PhoneNumber(const string& international_number) {
  inner::Automata a;
  auto ctx = a.Run(international_number);
  country_code_ = ctx.country;
  city_code_ = ctx.city;
  local_number_ = ctx.number;
}

string PhoneNumber::GetCountryCode() const {
  return country_code_;
}
string PhoneNumber::GetCityCode() const {
  return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
  return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
  return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
// ostream& operator<<(ostream& stream, const Context& ctx) {
//   return stream << "+" << ctx.country << "-" << ctx.city << "-" << ctx.number;
// }
// void parse(const string& num) {
//   inner::Automata a;
//   try {
//     auto c = a.Run(num);
//     std::cout << c << std::endl;
//   } catch (exception& e) {
//     std::cerr << e.what() << std::endl;
//   }
// }

// int main(int argc, char const* argv[]) {
//   parse("+7-495-1112233");
//   parse("+7-495-111-22-33");
//   parse("+323-22-460002");
//   parse("+1-2-coursera-cpp");
//   parse("1-2-333");
//   parse("+7-1233");
//   return 0;
// }