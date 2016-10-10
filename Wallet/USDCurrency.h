
#ifndef USDCURRENCY_H
#define USDCURRENCY_H

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

	virtual Accountable& operator+= (const Accountable& right);
	virtual Accountable& operator-= (const Accountable& right);
	
	friend USDCurrency& operator+ (USDCurrency& left, const USDCurrency& right);
	friend USDCurrency& operator- (USDCurrency& left, const USDCurrency& right);


};

#endif
