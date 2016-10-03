
#include <iostream>

#include "../Headers/CurrencyType.h"
#include "../Headers/Currency.h"

using namespace std;

int main() {

	Currency<CurrencyType> usd = Currency<CurrencyType>("usd", 100);

	cout << usd.name << endl;
	cout << usd.base << endl;


	system("pause");

	return 0;
}