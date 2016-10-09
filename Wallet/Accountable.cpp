
#include "Accountable.h"

Accountable::Accountable(const int base, const int main, const int sub) : base(base)
{
	mainValue = main;
	subunitValue = sub;
}

Accountable::Accountable(const Accountable &source) : base(source.base)
{
	mainValue = source.mainValue;
	subunitValue = source.subunitValue;
}

// Universal normalize method
Accountable& Accountable::normalize(const int &base, int &main, int &sub)
{
	if (sub >= base)
	{
		main += sub / base;
		sub %= base;
	}
	else if (sub < 0) 
	{
		main--;
		sub += base;
	}
	return *this;
}

// Copy assignment

Accountable& Accountable::operator= (const Accountable &source)
{
	mainValue = source.mainValue;
	subunitValue = source.subunitValue;

	return normalize(base, mainValue, subunitValue);
}

// Operator Overloads

Accountable& Accountable::operator+= (const Accountable &right)
{
	mainValue += right.mainValue;
	subunitValue += right.subunitValue;

	return normalize(base, mainValue, subunitValue);
}

Accountable& Accountable::operator-= (const Accountable &right)
{
	mainValue -= right.mainValue;
	subunitValue -= right.subunitValue;

	return normalize(base, mainValue, subunitValue);
}

Accountable operator+ (Accountable left, const Accountable &right)
{
	left += right;
	return left;
}

Accountable operator- (Accountable left, const Accountable &right)
{
	left -= right;
	return left;
}