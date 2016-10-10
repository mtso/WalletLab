
#include <iostream>
#include <string>

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
}

USDCurrency& USDCurrency::operator+= (const USDCurrency& right)
{
	wholeValue += right.getWholeValue();
	fractionalValue += right.getFractionalValue();
	return normalized(wholeValue, fractionalValue);
}

USDCurrency& USDCurrency::operator-= (const USDCurrency& right)
{
	wholeValue -= right.getWholeValue();
	fractionalValue -= right.getFractionalValue();
	return normalized(wholeValue, fractionalValue);
}

friend USDCurrency& USDCurrency::operator+ (USDCurrency& left, const USDCurrency& right)
{
	left += right;
	return left;
}