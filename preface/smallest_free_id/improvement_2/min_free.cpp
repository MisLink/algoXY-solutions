#include <algorithm>
#include <iostream>
#include <vector>
#include "../generate_data.cpp"
using namespace std;

int min_free(vector<int>& lst, int l, int u) {
  int m = (l + u) / 2;
  if (lst.empty()) {
    return l;
  }
  auto it = partition(lst.begin(), lst.end(), [m](int i) { return i <= m; });
  auto left = vector<int>(lst.begin(), it);
  auto right = vector<int>(it, lst.end());
  if (left.size() == m - l + 1) {
    return min_free(right, m + 1, u);
  } else {
    return min_free(left, l, m);
  }
}

int min_free_(vector<int> lst) {
  int l = 0;
  int n = lst.size();
  int u = n - 1;
  while (n > 0) {
    int m = (l + u) / 2;
    int left = 0;
    for (int right = 0; right < n; right++) {
      if (lst[right] <= m) {
        swap(lst[left], lst[right]);
        left++;
      }
    }
    if (left == m - l + 1) {
      lst.erase(lst.begin(), lst.begin() + left);  // complexity: linear
      n = n - left;
      l = m + 1;
    } else {
      n = left;
      u = m;
    }
  }
  return l;
}

int main() {
  int hundred_thousand = 100000;
  int million = 1000000;
  clock_t total = 0;
  size_t loop_times = 10;
  for (size_t i = 0; i < loop_times; i++) {
    auto lst = generate_data(million, loop_times);
    clock_t start_time = clock();
    int v1 = min_free(lst, 0, lst.size() - 1);
    cout << "result 1: " << v1 << endl;
    int v2 = min_free_(lst);
    cout << "result 2: " << v2 << endl;
    total += clock() - start_time;
  }
  cout << static_cast<double>(total) / loop_times / CLOCKS_PER_SEC << endl;
}
