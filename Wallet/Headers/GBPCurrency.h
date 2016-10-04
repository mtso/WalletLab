
#ifndef GBPCURRENCY_H
#define GBPCURRENCY_H

#include "Currency.h"

class GBPCurrency : public Currency
{
public:
	GBPCurrency(int, int);
	~GBPCurrency();
};

#endif