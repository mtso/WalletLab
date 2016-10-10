
#include "Accountable.h"

Accountable::Accountable(const int wholeInput, const int fractionalInput)
{
	wholeValue = wholeInput;
	fractionalValue = fractionalInput;
}

Accountable::Accountable(const Accountable &source)
{
	*this = source;
}

Accountable& Accountable::operator= (const Accountable& right)
{
	*this = right;
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