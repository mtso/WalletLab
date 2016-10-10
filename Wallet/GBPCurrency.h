#ifndef GBPCURRENCY_H
#define GBPCURRENCY_H

#include "Currency.h"

class GBPCurrency : public Currency {
private:
	const int base = 100;
	
	virtual Currency& normalized(int& wholeValue, int& fractionalValue);

public:
	GBPCurrency();
	GBPCurrency(int initialWhole, int initialFractional);
	GBPCurrency(const GBPCurrency& source);
	~GBPCurrency() {}

	virtual GBPCurrency& operator= (const GBPCurrency& right);

	//virtual Accountable& operator+= (const Accountable& right);
	//virtual Accountable& operator-= (const Accountable& right);

	friend GBPCurrency& operator+ (GBPCurrency& left, const GBPCurrency& right);
	friend GBPCurrency& operator- (GBPCurrency& left, const GBPCurrency& right);


};

#endif
