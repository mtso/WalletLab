
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
		delete currencies[i];
	}
}



int Wallet::contains(CurrencyType type) const
{
	for (int i = 0; i < MAX_WALLET_SIZE && i < currencyCount; i++)
	{
		if (currencies[i] != nullptr && currencies[i]->type == type)
		{
			return i;
		}
	}
	return -1;
}

void Wallet::add(const Currency &currency)
{
	int index = contains(currency.type);
	std::cout << index << std::endl;
	if (index >= 0)
	{
		*currencies[index] += currency;
	}
	else if (currencyCount < MAX_WALLET_SIZE)
	{
		switch (currency.type)
		{
		case USD:
			currencies[currencyCount] = new USDCurrency(currency.getMainValue(), currency.getSubunitValue());
			break;
		case GBP:
			currencies[currencyCount] = new GBPCurrency(currency.getMainValue(), currency.getSubunitValue());
			break;
		default:
			break;
		}

		currencyCount++;
	}
	else
	{
		std::cout << "Wallet is full" << std::endl;
	}
}

void Wallet::deposit(CurrencyType type, int depositMain, int depositSub)
{
	switch (type)
	{
	case USD:
		add(USDCurrency(depositMain, depositSub));
		break;
	case GBP:
		add(GBPCurrency(depositMain, depositSub));
		break;
	default:
		break;
	}
}

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