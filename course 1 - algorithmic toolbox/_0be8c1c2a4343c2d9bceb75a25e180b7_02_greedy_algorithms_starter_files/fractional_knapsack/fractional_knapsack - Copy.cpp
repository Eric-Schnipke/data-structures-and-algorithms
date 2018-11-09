#include <iostream>
#include <vector>

using std::vector;


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<int> amounts(weights.size());
  int amount;

  for (int n = 0; n < weights.size(); n++) {
	  if (capacity == 0) {
		  return value;
	  }
	  else {
		  int largest_vw = 0;
		  int largest_i = 0;
		  for (int i = 0; i < weights.size(); i++) {
			  if (  ( weights[i] > 0 )
				 && ( ((double)values[i] / (double)weights[i]) > largest_vw )
			     )
              {
				  largest_vw = ((double)values[i] / (double)weights[i]);
				  largest_i = i;
			  }
		  }

		  if (weights[largest_i] <= capacity) {
			  amount = weights[largest_i];
		  }
		  else {
			  amount = capacity;
		  }

		  value += (double)amount * ((double)values[largest_i]) / ((double)weights[largest_i]);

		  weights[largest_i] -= amount;
		  amounts[largest_i] += amount;
		  capacity -= amount;
	  }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
