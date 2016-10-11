
#include "AUDCurrency.h"

Accountable& AUDCurrency::normalized(int& wholeValue, int& fractionalValue)
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

AUDCurrency::AUDCurrency(int initialWhole, int initialFractional)
: Currency(AUD, "Australian dollars", "cents", initialWhole, initialFractional)
{
	normalized(wholeValue, fractionalValue);
}

AUDCurrency::AUDCurrency(const AUDCurrency& source) : Currency(source)
{
	wholeName = source.getWholeName();
	fractionalName = source.getFractionalName();
}

AUDCurrency& AUDCurrency::operator= (const AUDCurrency& right)
{
	if (this != &right)
	{
		Currency::operator= (right);
	}
	return *this;
}

AUDCurrency& operator+ (AUDCurrency& left, const AUDCurrency& right)
{
	left += right;
	return left;
}

AUDCurrency& operator- (AUDCurrency& left, const AUDCurrency& right)
{
	left -= right;
	return left;
}

Currency* AUDCurrency::clone() const
{
	return new AUDCurrency(*this);
}