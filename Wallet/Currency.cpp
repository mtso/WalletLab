
#include "Currency.h"

Currency::Currency(CurrencyType type, int base, string mainName, string subName, int mainVal, int subVal)
: name(mainName), subunitName(subName), type(type), Accountable(base, mainVal, subVal)
{
	normalized(base, mainValue, subunitValue);
}

Currency& Currency::operator= (const Currency &source)
{
	if (type != source.type) { throw "operator= fails on incompatible types"; }
	
	*this = source;
	return *this;
}

// Operator Overloads

Currency& Currency::operator+= (const Currency &right)
{
	if (type != right.type) { throw "operator+= fails on incompatible types"; }
	
	*this += right;
	return *this;
}
//
Currency& Currency::operator-= (const Currency &right)
{
	if (type != right.type) { throw "operator-= fails on incompatible types"; }

	if (mainValue > right.mainValue || (mainValue == right.mainValue && subunitValue >= right.subunitValue))
	{
		*this -= right;
		return *this;
	}
	else
	{
		throw "Insufficient balance in currency type: " + type;
	}
}

ostream& operator<< (ostream &outstream, const Currency &source)
{
	outstream << source.mainValue << '.';
	if (source.subunitValue < 10) { outstream << '0'; }
	outstream << source.subunitValue;
	return outstream;
}

istream& operator>> (istream &instream, Currency &source)
{
	instream >> source.mainValue;
	instream >> source.subunitValue;

	return instream;
}