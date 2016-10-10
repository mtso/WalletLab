
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
