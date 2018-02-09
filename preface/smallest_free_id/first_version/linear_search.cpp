#include <ctime>
#include <iostream>
#include <vector>
#include "../generate_data.cpp"
using namespace std;

bool not_in(int &n, vector<int> &lst) {
  for (auto &i : lst) {
    if (i == n) {
      return false;
    }
  }
  return true;
}

int brute_force(vector<int> lst) {
  int i = 0;
  while (true) {
    if (not_in(i, lst)) {
      return i;
    }
    i++;
  }
}

int main() {
  int hundred_thousand = 100000;
  // int million = 1000000;
  clock_t total = 0;
  size_t loop_times = 10;
  for (size_t i = 0; i < loop_times; i++) {
    auto lst = generate_data(hundred_thousand, loop_times);
    clock_t start_time = clock();
    int v = brute_force(lst);
    cout << "result: " << v << endl;
    total += clock() - start_time;
  }
  cout << static_cast<double>(total) / loop_times / CLOCKS_PER_SEC << endl;
}
