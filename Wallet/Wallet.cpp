
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
	}
}

bool Wallet::contains(CurrencyType ofType) const
{
	return currency[ofType] != nullptr;
}

void Wallet::deposit(const Currency& deposit)
{
	if (contains(deposit.getType()))
	{
		*currency[deposit.getType()] += deposit;
	}
	else
	{
		currency[deposit.getType()] = deposit.clone();
	}
	cout << "Deposited " << deposit << endl;
}

Currency& Wallet::withdraw(Currency& withdrawal)
{
	const CurrencyType toWithdraw = withdrawal.getType();
	if (contains(toWithdraw))
	{
		try
		{
			*currency[toWithdraw] -= withdrawal;
			cout << "Withdrew  " << withdrawal << endl;
			return withdrawal;
		}
		catch (...)
		{
			cout << "Insufficient balance of " << withdrawal.getWholeName() << endl;
		}
	}
	else
	{
		cout << "no currency of that type to withdraw" << endl;
	}
	return withdrawal -= withdrawal;
}

bool Wallet::remove(CurrencyType toRemove)
{
	if (contains(toRemove))
	{
		delete currency[toRemove];
		currency[toRemove] = nullptr;
		cout << "Removed a currency at position " << toRemove << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Wallet::removeAll()
{
	for (int i = USD; i < AUD + 1; i++)
	{
		remove(static_cast<CurrencyType>(i));
	}
	cout << "Wallet is now empty." << endl;
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

ostream& operator<< (ostream& outStream, const Wallet& wallet)
{
	for (int i = 0; i < MAX_WALLET_SIZE; i++)
	{
		if (wallet.currency[i] != nullptr)
		{
			outStream << *(wallet.currency[i]) << endl;
		}
	}
	return outStream;
}
