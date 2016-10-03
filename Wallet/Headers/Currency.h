
#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

#include "./CurrencyType.h"

using namespace std;

template<typename CurrencyType>
class Currency {
public:
	const string name;
	const int base;

	Currency(string, int);
private:
	int mainunitValue;
	int subunitValue;

	struct value {
		int mainunit;
		int subunit;
	};
};

#endif