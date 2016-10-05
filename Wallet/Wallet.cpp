
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

int Wallet::contains(CurrencyType type)
{
	for (int i = 0; i < MAX_WALLET_SIZE; i++)
	{
		if (currencies[i] != nullptr && currencies[i]->getType() == type)
		{
			return i;
		}
	}
	return -1;
}

void Wallet::add(Currency currency)
{
	int index = contains(currency.getType());
	if (index >= 0)
	{
		*currencies[index] += currency;
	}
	else if (currencyCount < MAX_WALLET_SIZE)
	{
		switch (currency.getType())
		{
		case USD:
			currencies[currencyCount] = new USDCurrency(currency.getMainValue(), currency.getSubunitValue());
			break;
		case GBP:
			currencies[currencyCount] = new GBPCurrency(currency.getMainValue(), currency.getSubunitValue());
			break;
		case JPY:
			//currencies[currencyCount] = new JPYCurrency(deposit.getMainValue(), deposit.getSubunitValue());
			break;
		case CHF:
			//currencies[currencyCount] = new USDCurrency(deposit.getMainValue(), deposit.getSubunitValue());
			break;
		case AUD:
			//currencies[currencyCount] = new USDCurrency(deposit.getMainValue(), deposit.getSubunitValue());
			break;
		default:
			break;
		}

		currencyCount++;
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
	case JPY:
		//currencies[currencyCount] = new JPYCurrency(deposit.getMainValue(), deposit.getSubunitValue());
		break;
	case CHF:
		//currencies[currencyCount] = new USDCurrency(deposit.getMainValue(), deposit.getSubunitValue());
		break;
	case AUD:
		//currencies[currencyCount] = new USDCurrency(deposit.getMainValue(), deposit.getSubunitValue());
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
		Currency toRemove = *currencies[toRemoveIndex];
		*currencies[toRemoveIndex] = *currencies[currencyCount];
		delete currencies[currencyCount];
		currencyCount--;
		return true;
	}
	else
	{
		return false;
	}
}

bool Wallet::withdraw(CurrencyType type, int withdrawMain, int withdrawSub)
{
	int withdrawIndex = contains(type);
	if (withdrawIndex >= 0)
	{
		switch (type)
		{
		case USD:
			*currencies[withdrawIndex] -= USDCurrency(withdrawMain, withdrawSub);
			break;

		case GBP:
			*currencies[withdrawIndex] -= GBPCurrency(withdrawMain, withdrawSub);
			break;

		//case JPY:
		//	*currencies[withdrawIndex] -= JPYCurrency(withdrawMain, withdrawSub);
		//case CHF:
		//	*currencies[withdrawIndex] -= CHFCurrency(withdrawMain, withdrawSub);
		//case AUD:
		//	*currencies[withdrawIndex] -= AUDCurrency(withdrawMain, withdrawSub);
		default:
			break;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void Wallet::printBalance(ostream &out)
{
	for (int i = 0; i < currencyCount; i++)
	{
		out << *currencies[i] << currencies[i]->getName() << endl;
	}
}