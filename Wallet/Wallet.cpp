
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


Currency& Wallet::withdraw(const Currency& withdrawal)
{
	if (contains(withdrawal))
	int withdrawIndex = contains(type);
	if (withdrawIndex >= 0)
	{
		switch (type)
		{
		case USD:
			*currency[withdrawIndex] -= USDCurrency(withdrawMain, withdrawSub);
			return USDCurrency(withdrawMain, withdrawSub);

		case GBP:
			*currency[withdrawIndex] -= GBPCurrency(withdrawMain, withdrawSub);
			return GBPCurrency(withdrawMain, withdrawSub);

		default:
			throw "no currency to withdraw of type " + type;
		}
	}
	else
	{
		throw "no currency in wallet of type " + type;
	}
}
/**/


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

/**/

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
