#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
#include "../generate_data.cpp"
using namespace std;

int min_free(vector<int>::iterator begin, vector<int>::iterator end, int l,
             int u) {
  int m = (l + u) / 2;
  if (begin == end) {
    return l;
  }
  auto it = partition(begin, end, [m](int i) { return i <= m; });
  if (it - begin == m - l + 1) {
    return min_free(it, end, m + 1, u);
  } else {
    return min_free(begin, it, l, m);
  }
}

int min_free_(vector<int> &lst) {
  int l = 0;
  int u = lst.size() - 1;
  auto begin = lst.begin();
  auto end = lst.end();
  while (end - begin) {
    int m = (l + u) / 2;
    auto left = partition(begin, end, [m](int i) { return i <= m; });
    if (left - begin == m - l + 1) {
      begin = left;
      l = m + 1;
    } else {
      end = left;
      u = m;
    }
  }
  return l;
}

int main() {
  // int hundred_thousand = 100000;
  int million = 1000000;
  clock_t total = 0;
  size_t loop_times = 10;
  for (size_t i = 0; i < loop_times; i++) {
    auto lst = generate_data(million, loop_times);
    clock_t start_time = clock();
    int v1 = min_free(lst.begin(), lst.end(), 0, lst.size() - 1);
    cout << "result 1: " << v1 << endl;
    int v2 = min_free_(lst);
    cout << "result 2: " << v2 << endl;
    total += clock() - start_time;
  }
  cout << static_cast<double>(total) / loop_times / CLOCKS_PER_SEC << endl;
}
