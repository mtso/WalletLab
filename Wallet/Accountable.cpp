
#include "Accountable.h"

Accountable::Accountable(CurrencyType type, int base, int main, int sub) : type(type), base(base)
{
	mainValue = main;
	subunitValue = sub;
}

Accountable::Accountable(const Accountable &source) : type(source.type), base(source.base)
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
	if (type != source.type) 
		{ throw Error(0); }

	mainValue = source.mainValue;
	subunitValue = source.subunitValue;

	normalize(base, mainValue, subunitValue);
	return *this;
}

// Operator Overloads

Accountable& Accountable::operator+= (const Accountable &right)
{
	if (type != right.type) 
		{ throw Error(1); }

	mainValue += right.mainValue;
	subunitValue += right.subunitValue;

	normalize(base, mainValue, subunitValue);
	return *this;
}

Accountable& Accountable::operator-= (const Accountable &right)
{
	if (type != right.type) 
		{ throw Error(2); }

	if (mainValue > right.mainValue ||
		(mainValue == right.mainValue && subunitValue >= right.subunitValue))
	{
		mainValue -= right.mainValue;
		subunitValue -= right.subunitValue;

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

Accountable operator- (Accountable left, const Accountable &right)
{
	left -= right;
	return left;
}