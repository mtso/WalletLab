

#include "../Headers/Currency.h"

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

Currency::MonetaryValue Currency::getValue()
{
	return value;
}

Currency::Currency(CurrencyType type, int base, string name, string subName)
: type(type), base(base), name(name), subunitName(subName)
{
	value = { 0, 0 };
	normalize(base, value.main, value.subunit);
}

Currency::~Currency()
{

}

Currency& Currency::operator= (const Currency &source)
{
	if (type == source.type)
	{
		value.main = source.value.main;
		value.subunit = source.value.subunit;
		return *this;
	}
}

// Operator Overloads

Currency& Currency::operator+= (const Currency &rhs)
{
	if (type == rhs.type)
	{
		value.main += rhs.value.main;
		value.subunit += rhs.value.subunit;

		normalize(base, value.main, value.subunit);
		return *this;
	}
}

Currency& Currency::operator-= (const Currency &rhs)
{
	if (type == rhs.type)
	{
		if (value.main > rhs.value.main
			|| (value.main == rhs.value.main 
				&& value.subunit >= rhs.value.subunit))
		{
			value.main -= rhs.value.main;
			value.subunit -= rhs.value.subunit;

			normalize(base, value.main, value.subunit);
			return *this;
		}
	}
}

Currency operator+ (Currency lhs, const Currency &rhs)
{
	return lhs += rhs;
}

