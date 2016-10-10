
#include <iostream>
#include <cstdlib>

#include "Wallet.h"

using namespace std;

int randomValue()
{
	return rand() % 100;
}

int main() 
{
	Currency *usd = new USDCurrency(10, 10);
	GBPCurrency gbp(5, 5);
	*usd += gbp;

	cout << usd->getWholeValue() << endl;
	cout << usd->getFractionalValue() << endl;
	cout << usd->getWholeName() << endl;
	cout << usd->getFractionalName() << endl;

	system("pause");
	return 0;
}
