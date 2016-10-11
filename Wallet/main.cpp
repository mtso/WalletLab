
#include <iostream>

#include "Wallet.h"

using namespace std;

int randomValue()
{
	return rand() % 100;
}

CurrencyType randomType()
{
	int type = rand() % (AUD + 1);
	return static_cast<CurrencyType>(type);
}

int main() 
{
	Wallet wallet = Wallet();

	cout << wallet.contains(USD) << endl;

	wallet.deposit(USDCurrency(10, 10));
	wallet.deposit(USDCurrency(10, 10));
	wallet.deposit(GBPCurrency(10, 10));

	wallet.printBalanceTo(cout);

	//wallet.remove(USD);
	//wallet.remove(GBP);

	//wallet.withdraw(USDCurrency(10, 10));
	cout << wallet.withdraw(USDCurrency(11, 10)).getWholeValue() << endl;

	cout << wallet.contains(USD) << endl;
	cout << wallet.contains(GBP) << endl;

	system("pause");
	return 0;
}
