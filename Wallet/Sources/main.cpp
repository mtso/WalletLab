
#include <iostream>

#include "../Headers/CurrencyType.h"
#include "../Headers/Currency.h"
#include "../Headers/CurrencyUSD.h"

using namespace std;

int main() {

	for (int i = USD; i < 5 && i <= EUR; i++)
	{
		cout << i << endl;
	}
	
	Currency *usd = new CurrencyUSD(20, 20);

	cout << usd->getMainunitName() << endl;
	cout << usd->base << endl;

	delete usd;

	usd = new CurrencyUSD(30, 30);

	cout << usd->getMainunitName() << endl;
	cout << usd->base << endl;
	cout << usd->getSubunitName() << endl;

	delete usd;


	system("pause");

	return 0;
}