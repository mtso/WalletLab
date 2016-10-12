
#include "Currency.h"

Accountable& Currency::normalized(int& wholeValue, int& fractionalValue)
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
	if (type != right.getType()) { throw "operator= attempt on incompatible types"; }

	if (this != &right)
	{
		wholeName = right.getWholeName();
		fractionalName = right.getFractionalName();
		type = right.getType();
	}
	return *this;
}

Currency& Currency::operator+= (const Currency& right)
{
	if (type != right.getType()) { throw "operator+= attempt on incompatible types"; }

	Accountable::operator+=(right);
	return *this;
}


Currency& Currency::operator-= (const Currency& right)
{
	if (type != right.getType()) { throw "operator-= attempt on incompatible types"; }
	if (*this < right) { throw "operator-= attempt on insufficient balance"; }

	Accountable::operator-=(right);
	return *this;
}

ostream& operator<< (ostream& outStream, const Currency& right)
{
	outStream
		<< right.getWholeValue()
		<< ' ' << right.getWholeName() << " and "
		<< right.getFractionalValue()
		<< ' ' << right.getFractionalName();
	return outStream;
}

istream& operator>> (istream& inStream, Currency& right)
{
	inStream >> right.wholeValue;
	inStream >> right.fractionalValue;
	right.normalized(right.wholeValue, right.fractionalValue);
	return inStream;
}
