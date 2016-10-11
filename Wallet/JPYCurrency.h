
#ifndef JPYCURRENCY_H
#define JPYCURRENCY_H

#include "Currency.h"
#include "CurrencyBase.h"

class JPYCurrency : public Currency {
private:
	const CurrencyBase base = BASE_1000;

	virtual Accountable& normalized(int& wholeValue, int& fractionalValue);

public:
	JPYCurrency(int initialWhole = 0, int initialFractional = 0);
	JPYCurrency(const JPYCurrency& source);
	~JPYCurrency() { }

	virtual JPYCurrency& operator= (const JPYCurrency& right);

	Currency* clone() const;
};

#endif
