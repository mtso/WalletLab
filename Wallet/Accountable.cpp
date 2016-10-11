
#include "Accountable.h"

Accountable::Accountable(const int wholeInput, const int fractionalInput)
{
	wholeValue = wholeInput;
	fractionalValue = fractionalInput;
}

Accountable::Accountable(const Accountable &source) : wholeValue(source.getWholeValue()), fractionalValue(source.getFractionalValue())
{
}

Accountable& Accountable::operator= (const Accountable& right)
{
	*this = right;
	return *this;
}

Accountable& Accountable::operator+= (const Accountable& right)
{
	wholeValue += right.getWholeValue();
	fractionalValue += right.getFractionalValue();
	return *this;
}

Accountable& Accountable::operator-= (const Accountable& right)
{
	wholeValue -= right.getWholeValue();
	fractionalValue -= right.getFractionalValue();
	return *this;
}

bool Accountable::operator> (const Accountable& right)
{
	if (wholeValue > right.getWholeValue())
	{
		return true;
	}
	else if (wholeValue == right.getWholeValue() && fractionalValue > right.getFractionalValue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Accountable::operator< (const Accountable& right)
{
	if (wholeValue < right.getWholeValue())
	{
		return true;
	}
	else if (wholeValue == right.getWholeValue() && fractionalValue < right.getFractionalValue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Accountable::operator== (const Accountable& right)
{
	if (wholeValue == right.getWholeValue() && fractionalValue == right.getFractionalValue())
	{
		return true;
	}
	else
	{
		return false;
	}
}