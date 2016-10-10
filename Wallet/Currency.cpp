
#include "Currency.h"

Currency& Currency::normalized(int& wholeValue, int& fractionalValue)
{
	throw "normalized has not been implemented";
}

Currency::Currency(CurrencyType type, string wholeName, string fracName, int initialMain, int initialFractional)
: type(type), wholeName(wholeName), fractionalName(fracName), Accountable(initialMain, initialFractional)
{
}

Currency::Currency(const Currency& source) : type(source.getType()), Accountable(source)
{
}

Currency& Currency::operator= (const Currency& right)
{
	Accountable::operator= (right);
	return *this;
}

Currency& Currency::operator+= (const Currency& right)
{
	if (type != right.getType()) { throw "operator+= attempt on incompatible types"; }

	Accountable::operator+=(right);
	return normalized(wholeValue, fractionalValue);
}


Currency& Currency::operator-= (const Currency& right)
{
	if (type != right.getType()) { throw "operator-= attempt on incompatible types"; }
	if (*this < right) { throw "operator-= attempt on insufficient balance"; }

	Accountable::operator-=(right);
	return normalized(wholeValue, fractionalValue);
}