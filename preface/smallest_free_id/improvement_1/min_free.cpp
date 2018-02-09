#include <ctime>
#include <iostream>
#include <vector>
#include "../generate_data.cpp"
using namespace std;

int min_free(vector<int> &lst, int n) {
  vector<int> flags = vector<int>(n + 1, 0);
  for (auto &i : lst) {
    if (i < n) {
      flags[i] = 1;
    }
  }
  for (size_t i = 0; i < flags.size(); i++) {
    if (flags[i] == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  // int hundred_thousand = 100000;
  int million = 1000000;
  clock_t total = 0;
  size_t loop_times = 10;
  for (size_t i = 0; i < loop_times; i++) {
    auto lst = generate_data(million, loop_times);
    clock_t start_time = clock();
    int v = min_free(lst, lst.size());
    cout << "result: " << v << endl;
    total += clock() - start_time;
  }
  cout << static_cast<double>(total) / loop_times / CLOCKS_PER_SEC << endl;
}
