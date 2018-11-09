#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

int main() {
	uint32_t n;
	std::cin >> n;
	vector<uint64_t> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	//randomized_quick_sort2(a, 0, a.size() - 1);
	std::sort(a.begin(), a.end());
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}
}
