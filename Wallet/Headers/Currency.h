
#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

#include "CurrencyType.h"

using namespace std;

class Currency {
protected:
	struct MonetaryValue {
		int main;
		int subunit;
	};

	MonetaryValue value;

	const int base;
	const string name;
	const string subunitName;

	void normalize(const int &, int &, int &);

public:
	const CurrencyType type;

	MonetaryValue getValue();

	// Constructor and Deconstructor
	Currency(CurrencyType, int, string, string);
	virtual ~Currency();

	// Copy assignment constructor
	Currency& operator= (const Currency&);

<<<<<<< HEAD
	Currency operator- (Currency& right) {
		
	}
=======
	// Operator Overloads
	Currency& operator+= (const Currency &);
	Currency& operator-= (const Currency &);
>>>>>>> 2acf373986cbe33a6f069b07cfa2b78afc127db3
};

Currency operator+ (Currency, const Currency&);


#endif