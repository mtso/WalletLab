
#include "CHFCurrency.h"

Accountable& CHFCurrency::normalized(int& wholeValue, int& fractionalValue)
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

CHFCurrency::CHFCurrency(int initialWhole, int initialFractional)
: Currency(CHF, "francs", "rappen", initialWhole, initialFractional)
{
	normalized(wholeValue, fractionalValue);
}

CHFCurrency::CHFCurrency(const CHFCurrency& source) : Currency(source)
{
	wholeName = source.getWholeName();
	fractionalName = source.getFractionalName();
}

CHFCurrency& CHFCurrency::operator= (const CHFCurrency& right)
{
	if (this != &right)
	{
		Currency::operator= (right);
	}
	return *this;
}

CHFCurrency& operator+ (CHFCurrency& left, const CHFCurrency& right)
{
	left += right;
	return left;
}

CHFCurrency& operator- (CHFCurrency& left, const CHFCurrency& right)
{
	left -= right;
	return left;
}

Currency* CHFCurrency::clone() const
{
	return new CHFCurrency(*this);
}