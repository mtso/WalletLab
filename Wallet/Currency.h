
#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

#include "Accountable.h"
#include "CurrencyType.h"

using namespace std;

class Currency : public Accountable {
protected:
	const string name;
	const string subunitName;

	void normalize(const int &, int &, int &);

public:
	// Constructor and Deconstructor
	Currency(CurrencyType, int, string, string, int, int);
	virtual ~Currency();

	// Copy assignment constructor
	Currency& operator= (const Currency&);

	// Operator Overloads
	Currency& operator+= (const Currency &);
	Currency& operator-= (const Currency &);

	friend ostream& operator<< (ostream&, const Currency&);
	friend istream& operator>> (istream&, Currency&);

	int getSubunitValue() { return subunitValue; }
	int getMainValue() { return mainValue; }

	string getName() { return name; }
};

Currency operator+ (Currency, const Currency&);


#endif