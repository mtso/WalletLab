
#include <iostream>

#include "Wallet.h"

using namespace std;

int randomValue()
{
	return rand() % 100;
}

int main() 
{
	Currency *usd = new USDCurrency(10, 60);
	GBPCurrency gbp(5, 5);
	USDCurrency usd2(6, 65);

	cout << gbp.getWholeValue() << endl;
	try
	{
		*usd += usd2;
	}
	catch (char* error)
	{
		cout << error << endl;
	}

	cout << usd->getWholeValue() << endl;
	cout << usd->getFractionalValue() << endl;
	cout << usd->getWholeName() << endl;
	cout << usd->getFractionalName() << endl;

	system("pause");
	return 0;
}
