
#ifndef AUDCURRENCY_H
#define AUDCURRENCY_H

#include "Currency.h"
#include "CurrencyBase.h"

class AUDCurrency : public Currency {
private:
	const CurrencyBase base = BASE_100;

	virtual Accountable& normalized(int& wholeValue, int& fractionalValue);

public:
	AUDCurrency(int initialWhole = 0, int initialFractional = 0);
	AUDCurrency(const AUDCurrency& source);
	~AUDCurrency() { }

	virtual AUDCurrency& operator= (const AUDCurrency& right);
	
	friend AUDCurrency& operator+ (AUDCurrency& left, const AUDCurrency& right);
	friend AUDCurrency& operator- (AUDCurrency& left, const AUDCurrency& right);

	Currency* clone() const;
};

#endif
