
#ifndef CHFCURRENCY_H
#define CHFCURRENCY_H

#include "Currency.h"
#include "CurrencyBase.h"

class CHFCurrency : public Currency {
private:
	const CurrencyBase base = BASE_100;

	virtual Accountable& normalized(int& wholeValue, int& fractionalValue);

public:
	CHFCurrency(int initialWhole = 0, int initialFractional = 0);
	CHFCurrency(const CHFCurrency& source);
	~CHFCurrency() { }

	virtual CHFCurrency& operator= (const CHFCurrency& right);

	friend CHFCurrency& operator+ (CHFCurrency& left, const CHFCurrency& right);
	friend CHFCurrency& operator- (CHFCurrency& left, const CHFCurrency& right);

	Currency* clone() const;
};

#endif
