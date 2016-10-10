
#include "Currency.h"

Currency::Currency(string wholeName, string fracName, int initialMain, int initialFractional)
: wholeName(wholeName), fractionalName(fracName), Accountable(initialMain, initialFractional)
{
}

Currency::Currency(const Currency& source) : Accountable(source)
{
}

Currency& Currency::operator= (const Currency& right)
{
	Accountable::operator= (right);
	return *this;
}