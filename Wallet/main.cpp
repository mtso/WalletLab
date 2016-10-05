
#include <iostream>

//#include "CurrencyType.h"
#include "GBPCurrency.h"
#include "USDCurrency.h"

using namespace std;

int main() {

	for (int i = USD; i < 5 && i <= AUD; i++)
	{
		cout << i << endl;
	}
	
	Currency *money = new USDCurrency(3, 55);
	GBPCurrency gbp = GBPCurrency(3, 55);

	try
	{
		*money += *money;
		cout << money->getSubunitValue() << endl;
	}
	catch (Accountable::Error err)
	{
		cout << err.description << endl;
	}
	
	cin >> *money;
	cout << *money << endl;

	system("pause");

	return 0;
}