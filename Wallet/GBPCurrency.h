#ifndef GBPCURRENCY_H
#define GBPCURRENCY_H

#include "Currency.h"
#include "CurrencyBase.h"

class GBPCurrency : public Currency {
private:
	const CurrencyBase base = BASE_100;
	
	virtual Currency& normalized(int& wholeValue, int& fractionalValue);

public:
	GBPCurrency(int initialWhole = 0, int initialFractional = 0);
	GBPCurrency(const GBPCurrency& source);
	~GBPCurrency() {}

	virtual GBPCurrency& operator= (const GBPCurrency& right);

	friend GBPCurrency& operator+ (GBPCurrency& left, const GBPCurrency& right);
	friend GBPCurrency& operator- (GBPCurrency& left, const GBPCurrency& right);

	Currency* clone() const;
};

#endif
