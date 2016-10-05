

#include "Currency.h"

// Universal normalize method
void Currency::normalize(const int &base, int &main, int &sub)
{
	if (sub >= base)
	{
		main += sub / base;
		sub %= base;
	}
	else if (sub < 0) {
		main--;
		sub += base;
	}
}

Currency::Currency(CurrencyType type, int base, string name, string subName, int mainVal, int subVal)
: name(name), subunitName(subName), Accountable(type, base, mainVal, subVal)
{
	normalize(base, mainValue, subunitValue);
}

Currency::~Currency()
{

}

Currency& Currency::operator= (const Currency &source)
{
	if (type != source.type) { throw Error(0); }
	
	mainValue = source.mainValue;
	subunitValue = source.subunitValue;
	return *this;
}

//// Operator Overloads
//
Currency& Currency::operator+= (const Currency &right)
{
	if (type != right.type) { throw Error(1); }
	mainValue += right.mainValue;
	subunitValue += right.subunitValue;

	normalize(base, mainValue, subunitValue);
	return *this;
}
//
Currency& Currency::operator-= (const Currency &right)
{
	if (type != right.type) { throw Error(2); }

	if (mainValue > right.mainValue || (mainValue == right.mainValue && subunitValue >= right.subunitValue))
	{
		mainValue -= right.mainValue;
		subunitValue -= right.subunitValue;

		normalize(base, mainValue, subunitValue);
		return *this;
	}
	else
	{
		throw Error(3, -1);
	}

}
//
//Currency operator+ (Currency lhs, const Currency &rhs)
//{
//	return lhs += rhs;
//}

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