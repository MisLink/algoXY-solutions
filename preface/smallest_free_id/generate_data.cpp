#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

std::vector<int> generate_data(int amount, int offset) {
  std::vector<int> lst = std::vector<int>();
  lst.reserve(amount + offset);
  for (int i = 0; i < amount + offset; i++) {
    lst.push_back(i);
  }
  std::random_shuffle(lst.begin(), lst.end());
  return std::vector<int>(lst.begin(), lst.end() - offset);
}
