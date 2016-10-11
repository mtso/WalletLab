
#include "GBPCurrency.h"

Currency& GBPCurrency::normalized(int& wholeValue, int& fractionalValue)
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

GBPCurrency::GBPCurrency(int initialWhole, int initialFractional)
: Currency(GBP, "pounds", "pence", initialWhole, initialFractional)
{
	normalized(wholeValue, fractionalValue);
}

GBPCurrency::GBPCurrency(const GBPCurrency& source) : Currency(source)
{
	wholeName = source.getWholeName();
	fractionalName = source.getFractionalName();
}

GBPCurrency& GBPCurrency::operator= (const GBPCurrency& right)
{
	Currency::operator= (right);
	return *this;
}

GBPCurrency& operator+ (GBPCurrency& left, const GBPCurrency& right)
{
	left += right;
	return left;
}

GBPCurrency& operator- (GBPCurrency& left, const GBPCurrency& right)
{
	left -= right;
	return left;
}

Currency* GBPCurrency::clone() const
{
	return new GBPCurrency(*this);
}