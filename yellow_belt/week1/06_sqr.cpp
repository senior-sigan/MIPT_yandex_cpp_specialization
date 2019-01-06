#include <map>
#include <utility>
#include <vector>

using namespace std;

template<typename T>
T Sqr(const T& value);

template<typename K, typename V>
map<K, V> Sqr(const map<K, V>&);

template<typename K, typename V>
pair<K, V> Sqr(const pair<K, V>&);

template<typename T>
vector<T> Sqr(const vector<T>&);

template<typename T>
T Sqr(const T& value) {
  return value * value;
}

template<typename K, typename V>
map<K, V> Sqr(const map<K, V>& container) {
  map<K, V> res;
  for (const auto& kv : container) {
    res[kv.first] = Sqr(kv.second);
  }
  return res;
}

template<typename K, typename V>
pair<K, V> Sqr(const pair<K, V>& container) {
  return make_pair(Sqr(container.first), Sqr(container.second));
}

template<typename T>
vector<T> Sqr(const vector<T>& container) {
  vector<T> res(container.size());
  for (int i = 0; i < container.size(); i++) {
    res[i] = Sqr(container[i]);
  }
  return res;
}

// #include <iostream>

// int main() {
//   // Пример вызова функции
//   vector<int> v = {1, 2, 3};
//   cout << "vector:";
//   for (int x : Sqr(v)) {
//     cout << ' ' << x;
//   }
//   cout << endl;

//   map<int, pair<int, int>> map_of_pairs = {{4, {2, 2}}, {7, {4, 3}}};
//   cout << "map of pairs:" << endl;
//   for (const auto& x : Sqr(map_of_pairs)) {
//     cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
//   }

//   return 0;
// }