#include <iostream>

class Coin {
private:
	uint8_t value = 0;

public:
	void setValue(uint8_t v) {
		value = v;
	}

	uint8_t getValue() {
		return value;
	}
};

class ChangeAlgorithm {
private:
	uint16_t totalValue = 0;
	uint16_t coinCount = 0;

public:
	void setTotalValue(uint16_t money) {
		totalValue = money;
	}

	uint16_t getTotalValue() {
		return totalValue;
	}

	uint16_t getCoinCount() {
		return coinCount;
	}

	void incCoinCount() {
		coinCount++;
	}

	void calcCoinCount() {
		Coin dime, nickel, penny;
		dime.setValue(10);
		nickel.setValue(5);
		penny.setValue(1);

		while (getTotalValue() >= dime.getValue()) {
			setTotalValue(getTotalValue() - dime.getValue());
			incCoinCount();
		}

		while (getTotalValue() >= nickel.getValue()) {
			setTotalValue(getTotalValue() - nickel.getValue());
			incCoinCount();
		}

		while (getTotalValue() >= penny.getValue()) {
			setTotalValue(getTotalValue() - penny.getValue());
			incCoinCount();
		}
	}
};

int main() {
  int n;
  std::cin >> n;

  ChangeAlgorithm alg;

  alg.setTotalValue(n);
  alg.calcCoinCount();
  std::cout << alg.getCoinCount() << std::endl;
}
