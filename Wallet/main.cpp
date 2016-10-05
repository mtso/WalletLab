
#include <iostream>
#include <cstdlib>

#include "Wallet.h"

using namespace std;

int randomValue()
{
	return rand() % 100;
}

int main() {

	Wallet wallet = Wallet();
	wallet.deposit(USD, randomValue(), randomValue());
	wallet.deposit(USD, randomValue(), randomValue());
	wallet.deposit(USD, randomValue(), randomValue());
	wallet.deposit(USD, randomValue(), randomValue());
	wallet.deposit(GBP, randomValue(), randomValue());
	wallet.deposit(GBP, randomValue(), randomValue());

	wallet.printBalance(cout);

	for (int i = USD; i < 5 && i <= AUD; i++)
	{
		cout << i << endl;

		cout << rand() % 100 << endl;
	}
	
	system("pause");

	return 0;
}
