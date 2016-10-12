
#ifndef JPYCURRENCY_H
#define JPYCURRENCY_H

#include "Currency.h"
#include "CurrencyBase.h"

/**
 * JPY specific currency that defines its own base number (only currency to have a base of 1000).
 */
class JPYCurrency : public Currency {
private:
	const CurrencyBase base = BASE_1000;

	virtual Accountable& normalized(int& wholeValue, int& fractionalValue);

public:
	JPYCurrency(int initialWhole = 0, int initialFractional = 0);
	JPYCurrency(const JPYCurrency& source);
	~JPYCurrency() { }

	virtual JPYCurrency& operator= (const JPYCurrency& right);

	friend JPYCurrency& operator+ (JPYCurrency& left, const JPYCurrency& right);
	friend JPYCurrency& operator- (JPYCurrency& left, const JPYCurrency& right);

	Currency* clone() const;
};

#endif
