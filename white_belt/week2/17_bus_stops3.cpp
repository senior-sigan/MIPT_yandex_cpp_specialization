/**
В этой задаче вам нужно присваивать номера автобусным маршрутам.

А именно, для каждого маршрута, заданного множеством названий остановок,
нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.),
либо вернуть номер существующего маршрута, которому соответствует такое множество остановок.

В отличие от задачи «Автобусные остановки — 2», наборы остановок,
которые можно получить друг из друга перестановкой элементов или добавлением/удалением повторяющихся,
следует считать одинаковыми.

Формат ввода
Сначала вводится количество запросов Q, затем Q описаний запросов.

Каждый запрос представляет собой положительное количество остановок N,
за которым следуют разделённые пробелом N названий остановок соответствующего маршрута (не обязательно различных).
Названия остановок состоят лишь из латинских букв и символов подчёркивания.

Формат вывода
Выведите ответ на каждый запрос в отдельной строке.

Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i,
где i — номер маршрута с таким набором остановок.
В противном случае нужно выделить введённому набору остановок новый номер i и вывести его в формате New bus i.

Пример
Ввод
```
5
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
2 Kokoshkino Kokoshkino
```

Вывод
```
New bus 1
New bus 2
Already exists for 1
Already exists for 1
Already exists for 2
```
**/

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class BusStops3 {
  map<set<string>, int> buses;

 public:
  void add(vector<string> stops) {
    set<string> stops_key(begin(stops), end(stops));
    if (buses.count(stops_key) == 0) {
      int number = buses.size() + 1;
      buses[stops_key] = number;
      cout << "New bus " << number << endl;
    } else {
      cout << "Already exists for " << buses[stops_key] << endl;
    }
  }
};

void handle(BusStops3& busStops) {
  int n;
  cin >> n;
  vector<string> stops(n);
  for (string& stop : stops) {
    cin >> stop;
  }
  busStops.add(stops);
}

int main(int argc, char const* argv[]) {
  BusStops3 busStops;
  int q;
  cin >> q;
  for (; q > 0; q--) {
    handle(busStops);
  }
  return 0;
}
