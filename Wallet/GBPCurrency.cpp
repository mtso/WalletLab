
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

GBPCurrency::GBPCurrency() : Currency(GBP, "pounds", "pence", 0, 0)
{}

GBPCurrency::GBPCurrency(int initialWhole, int initialFractional)
: Currency(GBP, "dollars", "cents", initialWhole, initialFractional)
{
	normalized(wholeValue, fractionalValue);
}

GBPCurrency::GBPCurrency(const GBPCurrency& source) : Currency(source)
{
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