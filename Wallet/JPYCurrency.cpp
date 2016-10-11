
#include "JPYCurrency.h"

Accountable& JPYCurrency::normalized(int& wholeValue, int& fractionalValue)
{
	if (fractionalValue >= base)
	{
		wholeValue += fractionalValue / base;
		fractionalValue %= base;
	}
	else if (fractionalValue < 0)
	{
		wholeValue -= fractionalValue / base - 1;
		fractionalValue = fractionalValue % base + base;
	}
	return *this;
}

JPYCurrency::JPYCurrency(int initialWhole, int initialFractional)
: Currency(JPY, "yen", "rin", initialWhole, initialFractional)
{
	normalized(wholeValue, fractionalValue);
}

JPYCurrency::JPYCurrency(const JPYCurrency& source) : Currency(source)
{
	wholeName = source.getWholeName();
	fractionalName = source.getFractionalName();
}

JPYCurrency& JPYCurrency::operator= (const JPYCurrency& right)
{
	if (this != &right)
	{
		Currency::operator= (right);
	}
	return *this;
}

JPYCurrency& operator+ (JPYCurrency& left, const JPYCurrency& right)
{
	left += right;
	return left;
}

JPYCurrency& operator- (JPYCurrency& left, const JPYCurrency& right)
{
	left -= right;
	return left;
}

Currency* JPYCurrency::clone() const
{
	return new JPYCurrency(*this);
}