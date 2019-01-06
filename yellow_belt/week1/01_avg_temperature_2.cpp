/**
 * Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
 * Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.
 *
 * Гарантируется, что среднее арифметическое значений температуры является целым числом.
 *
 * Формат ввода
 * Вводится число N, затем N неотрицательных целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.
 *
 * Формат вывода
 * Первое число K — количество дней, значение температуры в которых выше среднего арифметического.
 * Затем K целых чисел — номера этих дней.
 **/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int32_t n;
  cin >> n;
  vector<int32_t> temperatures(n);
  int64_t sum = 0;
  for (auto& temperature : temperatures) {
    cin >> temperature;
    sum += temperature;
  }

  int64_t average = sum / n;
  vector<int32_t> result_indices;
  int32_t i = 0;
  for (auto tmp : temperatures) {
    if (tmp > average) {
      result_indices.push_back(i);
    }
    i++;
  }

  cout << result_indices.size() << endl;
  for (auto result_index : result_indices) {
    cout << result_index << " ";
  }
  cout << endl;

  return 0;
}