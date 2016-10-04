
#ifndef USD_H
#define USD_H

#include <iostream>

#include "CurrencyType.h"
#include "Currency.h"

class CurrencyUSD : public Currency {
public:
	CurrencyUSD(int, int);
	~CurrencyUSD();
};

#endif
