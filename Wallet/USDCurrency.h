
#ifndef USD_H
#define USD_H

#include "Currency.h"

class USDCurrency : public Currency {
public:
	USDCurrency(int initialWhole, int initialFractional);
	USDCurrency(const USDCurrency& source);
	~USDCurrency() {}

	virtual USDCurrency& operator= (const USDCurrency& right);
	virtual USDCurrency& operator+= (const USDCurrency& right);
	virtual USDCurrency& operator-= (const USDCurrency& right);


};

#endif
