
#include <iostream>

#include "Wallet.h"

using namespace std;

int randomValue()
{
	return rand() % 100;
}

int main() 
{
	Wallet wallet = Wallet();

	cout << wallet.getCount() << endl;
	cout << wallet.contains(USD) << endl;

	wallet.deposit(*(new USDCurrency(10, 10)));

	cout << wallet.contains(USD) << endl;

	system("pause");
	return 0;
}
