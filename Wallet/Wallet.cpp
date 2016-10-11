
#include "Wallet.h"

Wallet::Wallet()
{
	for (int i = 0; i < MAX_WALLET_SIZE; i++)
	{
		currency[i] = nullptr;
	}
}

Wallet::~Wallet()
{
	for (int i = 0; i < MAX_WALLET_SIZE; i++)
	{
		delete currency[i];
		//currency[i] = nullptr;
	}
	//delete[] currency;
}

bool Wallet::contains(CurrencyType ofType) const
{
	return currency[ofType] != nullptr;
}

bool Wallet::deposit(const Currency& deposit)
{
	if (contains(deposit.getType()))
	{
		*currency[deposit.getType()] += deposit;
		return true;
	}
	else
	{
		switch (deposit.getType())
		{
		case USD:
			currency[deposit.getType()] = new USDCurrency(deposit.getWholeValue(), deposit.getFractionalValue());
			return true;

		case GBP:
			currency[deposit.getType()] = new GBPCurrency(deposit.getWholeValue(), deposit.getFractionalValue());
			return true;

		default:
			return false;
		}
	}
}

bool Wallet::remove(CurrencyType toRemove)
{
	if (contains(toRemove))
	{
		delete currency[toRemove];
		currency[toRemove] = nullptr;
		return true;
	}
	else
	{
		return false;
	}
}

Currency& Wallet::withdraw(Currency& withdrawal)
{
	const CurrencyType toWithdraw = withdrawal.getType();
	if (contains(toWithdraw))
	{
		try
		{
			*currency[toWithdraw] -= withdrawal;
			return withdrawal;
		}
		catch (char* error)
		{
			cout << error << endl;
		}
	}
	else
	{
		cout << "no currency of that type to withdraw" << endl;
	}
	return withdrawal -= withdrawal;
}

bool Wallet::isEmpty() const
{
	for (int i = 0; i < MAX_WALLET_SIZE; i++)
	{
		if (currency[i] != nullptr)
		{
			return false;
		}
	}
	return true;
}

void Wallet::printBalanceTo(std::ostream &outStream)
{
	for (int i = 0; i < MAX_WALLET_SIZE; i++)
	{
		if (currency[i] != nullptr)
		{
			outStream 
				<< currency[i]->getWholeValue()
				<< '.'
				<< currency[i]->getFractionalValue()
				<< ' '
				<< currency[i]->getWholeName() << endl;
		}
	}
}

//
//ostream& operator<< (ostream& outStream, const Wallet& wallet)
//{
//	for (int i = 0; i < MAX_WALLET_SIZE; i++)
//	{
//		if (wallet.currency[i] != nullptr)
//		{
//			outStream << *(wallet.currency[i]) << std::endl;
//		}
//	}
//	return outStream;
//}
