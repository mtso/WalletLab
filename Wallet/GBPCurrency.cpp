
#include "GBPCurrency.h"

GBPCurrency& GBPCurrency::normalized(int& wholeValue, int& fractionalValue)
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
: Currency("dollars", "cents", initialWhole, initialWhole)
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

Accountable& GBPCurrency::operator+= (const Accountable& right)
{
	wholeValue += right.getWholeValue();
	fractionalValue += right.getFractionalValue();
	return normalized(wholeValue, fractionalValue);
}

Accountable& GBPCurrency::operator-= (const Accountable& right)
{
	if (*this > right)
	{
		wholeValue -= right.getWholeValue();
		fractionalValue -= right.getFractionalValue();
		return normalized(wholeValue, fractionalValue);
	}
	else
	{
		throw "Subtraction operation attempt on an insufficient balance";
	}
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