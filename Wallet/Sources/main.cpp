
#include <iostream>

#include "../Headers/CurrencyType.h"
#include "../Headers/Currency.h"

using namespace std;

int main() {

	Currency usd = Currency(CurrencyType::USD, 100);

	cout << usd.getName() << endl;
	cout << usd.base << endl;


	system("pause");

	return 0;
}