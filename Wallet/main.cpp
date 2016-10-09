
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


	
	system("pause");
	return 0;
}
