
#ifndef USD_H
#define USD_H

#include "Currency.h"

class USDCurrency : public Currency {
private:
	const int base = 100;
	USDCurrency& normalized(int& wholeValue, int& fractionalValue);

public:
	USDCurrency(int initialWhole, int initialFractional);
	USDCurrency(const USDCurrency& source);
	~USDCurrency() {}

	virtual USDCurrency& operator= (const USDCurrency& right);
	virtual USDCurrency& operator+= (const USDCurrency& right);
	virtual USDCurrency& operator-= (const USDCurrency& right);

	friend USDCurrency& operator+ (USDCurrency& left, const USDCurrency& right);
};

#endif
