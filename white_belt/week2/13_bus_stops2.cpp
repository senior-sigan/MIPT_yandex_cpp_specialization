/**
 *В этой задаче вам нужно присваивать номера автобусным маршрутам.
 *
 *А именно, для каждого маршрута, заданного набором названий остановок, нужно либо выдать новый номер (первому маршруту
 *— 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута, которому соответствует такой набор остановок.
 *
 *Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными (см. пример).
 *
 *Указание
 *В C++ ключом словаря может быть не только число или строка, но и другой контейнер, например, vector.
 *
 *Формат ввода
 *Сначала вводится количество запросов Q, затем Q описаний запросов.
 *
 *Каждый запрос представляет собой положительное количество остановок N,
 *за которым следуют разделённые пробелом N различных названий остановок соответствующего маршрута.
 *Названия остановок состоят лишь из латинских букв и символов подчёркивания.
 *
 *Формат вывода
 *Выведите ответ на каждый запрос в отдельной строке.
 *
 *Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for
 *i, где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок
 *новый номер i и вывести его в формате New bus i.
 *
 *Пример
 *Ввод
 *```
 *4
 *2 Marushkino Kokoshkino
 *1 Kokoshkino
 *2 Marushkino Kokoshkino
 *2 Kokoshkino Marushkino
 *```
 *
 *Вывод
 *```
 *New bus 1
 *New bus 2
 *Already exists for 1
 *New bus 3
 *```
 **/

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class BusStops2 {
  map<vector<string>, int> buses;

 public:
  void add(vector<string> stops) {
    if (buses.count(stops) == 0) {
      int number = buses.size() + 1;
      buses[stops] = number;
      cout << "New bus " << number << endl;
    } else {
      cout << "Already exists for " << buses[stops] << endl;
    }
  }
};

void handle(BusStops2& busStops) {
  int n;
  cin >> n;
  vector<string> stops(n);
  for (string& stop : stops) {
    cin >> stop;
  }
  busStops.add(stops);
}

int main(int argc, char const* argv[]) {
  BusStops2 busStops;
  int q;
  cin >> q;
  for (; q > 0; q--) {
    handle(busStops);
  }
  return 0;
}
