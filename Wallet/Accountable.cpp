
#include "Accountable.h"

Accountable::Accountable(int base, int main, int sub) : base(base)
{
	mainValue = main;
	subunitValue = sub;
}

Accountable::Accountable(const Accountable &source) : base(source.base)
{
	mainValue = source.mainValue;
	subunitValue = source.subunitValue;
}

Accountable::~Accountable()
{

}

// Universal normalize method
void Accountable::normalize(const int &base, int &main, int &sub)
{
	if (sub >= base)
	{
		main += sub / base;
		sub %= base;
	}
	else if (sub < 0) {
		main--;
		sub += base;
	}
}


Accountable& Accountable::operator= (const Accountable &source)
{
	mainValue = source.mainValue;
	subunitValue = source.subunitValue;

	normalize(base, mainValue, subunitValue);
	return *this;
}

// Operator Overloads

Accountable& Accountable::operator+= (const Accountable &rhs)
{
	mainValue += rhs.mainValue;
	subunitValue += rhs.subunitValue;

	normalize(base, mainValue, subunitValue);
	return *this;	
}

Accountable& Accountable::operator-= (const Accountable &rhs)
{

	if (mainValue > rhs.mainValue ||
		(mainValue == rhs.mainValue && subunitValue >= rhs.subunitValue))
	{
		mainValue -= rhs.mainValue;
		subunitValue -= rhs.subunitValue;

		normalize(base, mainValue, subunitValue);
		return *this;
	}
	else
	{
		return *this;
	}
}

Accountable operator+ (Accountable left, const Accountable &right)
{
	left += right;
	return left;
}
