// A3_P1_BinarySearch.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

signed int binary_search(const vector<uint64_t> &a, int low, int high, uint64_t key) {
	int mid = 0;
	//write your code here
	if (high < low) {
		return -1;
	}

	mid = low + ((high - low) / 2);

	if (key == a[mid]) {
		return mid;
	}
	else if (key < a[mid]) {
		return binary_search(a, low, mid - 1, key);
	}
	else {
		return binary_search(a, mid + 1, high, key);
	}
}

signed int linear_search(const vector<uint64_t> &a, uint64_t x) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] == x) return i;
	}
	return -1;
}

int main() {

#if 1
	/* manual data input */
	int n;
	std::cin >> n;
	vector<uint64_t> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	vector<uint64_t> b(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i];
	}
#else
	/* automated data input */
	int n = 1, m = 1;

	
	vector<uint64_t> a(n);
	vector<uint64_t> b(m);

	for (int i = 1; i < n; i++) {
		a[i] = rand() + a[i-1] + 1;
	}

	for (int j = 0; j < m; j++) {
		b[j] = rand() + 1;
	}
#endif
	for (int i = 0; i < m; ++i) {
		//replace with the call to binary_search when implemented
		// std::cout << linear_search(a, b[i]) << ' ';
		std::cout << binary_search(a, 0, a.size() - 1, b[i]) << ' ';
	}
}


