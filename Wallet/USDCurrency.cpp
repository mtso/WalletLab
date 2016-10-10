
#include "USDCurrency.h"

USDCurrency& USDCurrency::normalized(int& wholeValue, int& fractionalValue)
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

USDCurrency::USDCurrency(int initialWhole, int initialFractional) 
: Currency("dollars", "cents", initialWhole, initialWhole)
{
	normalized(wholeValue, fractionalValue);
}

USDCurrency::USDCurrency(const USDCurrency& source) : Currency(source)
{
}

USDCurrency& USDCurrency::operator= (const USDCurrency& right)
{
	Currency::operator= (right);
	return *this;
}

Accountable& USDCurrency::operator+= (const Accountable& right)
{
	wholeValue += right.getWholeValue();
	fractionalValue += right.getFractionalValue();
	return normalized(wholeValue, fractionalValue);
}

Accountable& USDCurrency::operator-= (const Accountable& right)
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

USDCurrency& operator+ (USDCurrency& left, const USDCurrency& right)
{
	left += right;
	return left;
}

USDCurrency& operator- (USDCurrency& left, const USDCurrency& right)
{
	left -= right;
	return left;
}