
#include "USDCurrency.h"

Accountable& USDCurrency::normalized(int& wholeValue, int& fractionalValue)
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
: Currency(USD, "dollars", "cents", initialWhole, initialFractional)
{
	normalized(wholeValue, fractionalValue);
}

USDCurrency::USDCurrency(const USDCurrency& source) : Currency(source)
{
	wholeName = source.getWholeName();
	fractionalName = source.getFractionalName();
}

USDCurrency& USDCurrency::operator= (const USDCurrency& right)
{
	if (this != &right)
	{
		Currency::operator= (right);
	}
	return *this;
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

Currency* USDCurrency::clone() const
{
	return new USDCurrency(*this);
}