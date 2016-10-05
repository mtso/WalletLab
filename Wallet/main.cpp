
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

	wallet.withdraw(USD, randomValue(), randomValue());

	wallet.printBalance(cout);

	
	system("pause");

	return 0;
}
