
#include <iostream>
#include <cstdlib>

#include "Wallet.h"

#include "AccountableTest.h"

using namespace std;

int randomValue()
{
	return rand() % 100;
}

int main() 
{
	AccountableTest::runAccountableTests();

	Wallet wallet = Wallet();
	
	wallet.deposit(USD, randomValue(), randomValue());
	wallet.deposit(USD, randomValue(), randomValue());
	wallet.deposit(USD, randomValue(), randomValue());
	wallet.withdraw(USD, randomValue(), randomValue());

	wallet.printBalanceTo(cout);

	system("pause");
	return 0;
}
