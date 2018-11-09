#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

bool descSort(int i, int j) { return i > j; }

signed long long min_dot_product(vector<int> a, vector<int> b) {
  // write your code here
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end(), descSort);


  signed long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += (signed long long)a[i] * (signed long long)b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << min_dot_product(a, b) << std::endl;
}
