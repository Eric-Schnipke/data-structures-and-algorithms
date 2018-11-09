// A3_P2_MajorityElement.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

using std::vector;

#if 0
class bin_t {
public:
	void set_element(int n) {element = n;}

	int get_element(void) {return element;}

	void incr_count(void) {count++;}

	int get_count(void) {return count;}

private:
	int element = -1;
	int count = 0;
};


bool sortByCount(bin_t &a, bin_t &b) { return a.get_count() > b.get_count(); }

int get_majority_element_brute(vector<int> &a) {
	vector<bin_t> bins;

	// loop through vector to be tallied
	for (int i = 0; i < a.size(); i++) {
		bool found = false;
		// compare current element in vector-to-be-tallied to every element in bin vector. If found, increase element count; if not, create new element and set count to 1
		for (int j = 0; j < bins.size(); j++) {
			if (a[i] == bins[j].get_element()) {
				bins[j].incr_count();
				found = true;
				break;
			}
		}

		if(!found) {
			bin_t new_bin;
			new_bin.set_element(a[i]);
			new_bin.incr_count();
			bins.push_back(new_bin);
		}
	}

	std::sort(bins.begin(), bins.end(), sortByCount);
	if (bins[0].get_count() > (a.size() / 2)) {
		return 1;
	}
	else {
		return 0;
	}
	
}
#endif


int get_majority_element(vector<uint64_t> &a) {
	/* Implement Boyer-Moore Linear Time Majority Vote algorithm */
	uint32_t counter = 0;
	uint64_t current_candidate;
	uint64_t current_element;

	for (uint32_t i = 0; i < a.size(); i++) {
		current_element = a[i];
		if (counter == 0) {
			current_candidate = current_element;
			counter = 1;
		} else {
			if (current_candidate == current_element) {
				counter++;
			} else {
				counter--;
			}
		}
	}

	counter = 0;
	for (uint32_t j = 0; j < a.size(); j++) {
		if (a[j] == current_candidate) {
			counter++;
		}
	}

	if (counter > (a.size() / 2)) {
		return 1;
	}
	else {
		return 0;
	}

	return 0;
}

int main() {
	uint32_t n;
	std::cin >> n;
	vector<uint64_t> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << get_majority_element(a) << std::endl;
	// std::cout << get_majority_element_brute(a) << std::endl;
}


