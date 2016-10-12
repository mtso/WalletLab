
#include <iostream>

#include "Wallet.h"

using namespace std;

// Methods for generating random-ish currencies of random-ish amounts.
int randomValue();
CurrencyType randomType();
Currency* randomMonetaryAmount();

// Wallet main method runs the wallet object and uses different the features of the wallet.
int main() 
{
	cout << "Welcome to Wallet.ai, your personal wallet assistant powered by the latest AI technology. "
		<< "A new wallet will be created for you with initial amounts of 500 in USD, GBP, JPY, CHF, and AUD, "
		<< "which are the top five traded currencies in the foreign exchange market." << endl << endl;

	Wallet wallet = Wallet();
	wallet.deposit(USDCurrency(500));
	wallet.deposit(GBPCurrency(500));
	wallet.deposit(JPYCurrency(500));
	wallet.deposit(CHFCurrency(500));
	wallet.deposit(AUDCurrency(500));

	cout << endl << "We will now attempt to trade your currencies in the exchange market." << endl;

	for (int i = 0; i < 20; i++)
	{
		wallet.withdraw(*randomMonetaryAmount());
		wallet.deposit(*randomMonetaryAmount());
	}

	cout << "\nYour wallet's final balance is:\n" << wallet << endl;

	wallet.removeAll();

	cout << endl;
	system("pause");
	return 0;
}


int randomValue()
{
	return rand() % 100;
}

CurrencyType randomType()
{
	int type = rand() % (AUD + 1);
	return static_cast<CurrencyType>(type);
}

Currency* randomMonetaryAmount()
{
	switch (randomType())
	{
	case USD:
		return new USDCurrency(randomValue(), randomValue());

	case GBP:
		return new GBPCurrency(randomValue(), randomValue());

	case JPY:
		return new JPYCurrency(randomValue(), randomValue());

	case CHF:
		return new CHFCurrency(randomValue(), randomValue());

	case AUD:
		return new AUDCurrency(randomValue(), randomValue());

	default:
		return new USDCurrency(randomValue(), randomValue());
	}
}