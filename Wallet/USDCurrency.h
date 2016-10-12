
#ifndef USDCURRENCY_H
#define USDCURRENCY_H

#include "Currency.h"
#include "CurrencyBase.h"

/**
 * USD specific currency that defines its own base number.
 */
class USDCurrency : public Currency {
private:
	const CurrencyBase base = BASE_100;

	virtual Accountable& normalized(int& wholeValue, int& fractionalValue);

public:
	USDCurrency(int initialWhole = 0, int initialFractional = 0);
	USDCurrency(const USDCurrency& source);
	~USDCurrency() { }

	virtual USDCurrency& operator= (const USDCurrency& right);

	friend USDCurrency& operator+ (USDCurrency& left, const USDCurrency& right);
	friend USDCurrency& operator- (USDCurrency& left, const USDCurrency& right);

	Currency* clone() const;
};

#endif
