
#ifndef USD_H
#define USD_H

#include <iostream>
#include <string>

#include "CurrencyType.h"
#include "Currency.h"

class USDCurrency : public Currency {
public:
	USDCurrency(int, int);
	~USDCurrency();
};

#endif
