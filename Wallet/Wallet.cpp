
#include "Wallet.h"

Wallet::Wallet()
{
	for (int i = 0; i < MAX_WALLET_SIZE; i++)
	{
		currencies[i] = nullptr;
	}
}

Wallet::~Wallet()
{
	for (int i = 0; i < MAX_WALLET_SIZE; i++)
	{
		if (currencies[i] != nullptr)
		{
			delete currencies[i];
		}
	}
}

bool Wallet::contains(CurrencyType type) const
{
	return currencies[type] != nullptr;
}


void Wallet::deposit(Currency& deposit)
{
	if (contains(deposit.getType()))
	{
		*currencies[deposit.getType()] += deposit;
	}
	else
	{
		// TODO: need to fix this, depositing should create a new object;
		// but it doesn't
		Currency *newCurrency = new Currency(&deposit);
		currencies[deposit.getType()] = &deposit;
	}
}
/*
bool Wallet::remove(CurrencyType type)
{
	int toRemoveIndex = contains(type);
	if (toRemoveIndex >= 0)
	{
		Currency *toRemove = currencies[toRemoveIndex];
		// Swap the last element with the element that needs to be removed
		currencies[toRemoveIndex] = currencies[currencyCount - 1];
		currencies[currencyCount - 1] = toRemove;
		// Delete the last element, which should be the element to be removed (after the swap)
		delete currencies[currencyCount - 1];
		currencies[currencyCount - 1] = nullptr;
		currencyCount--;
		return true;
	}
	else
	{
		return false;
	}
}

Currency Wallet::withdraw(CurrencyType type, int withdrawMain, int withdrawSub)
{
	int withdrawIndex = contains(type);
	if (withdrawIndex >= 0)
	{
		switch (type)
		{
		case USD:
			*currencies[withdrawIndex] -= USDCurrency(withdrawMain, withdrawSub);
			return USDCurrency(withdrawMain, withdrawSub);

		case GBP:
			*currencies[withdrawIndex] -= GBPCurrency(withdrawMain, withdrawSub);
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

void Wallet::printBalanceTo(ostream &out) const
{
	for (int i = 0; i < currencyCount; i++)
	{
		out << *currencies[i] << currencies[i]->getName() << endl;
	}
}

/**/