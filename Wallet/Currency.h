
#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

#include "Accountable.h"
#include "CurrencyType.h"

using namespace std;

class Currency : public Accountable {
protected:
	const string wholeName;
	const string fractionalName;
	const CurrencyType type;

	virtual Currency& normalized(int& wholeValue, int& fractionalValue);

public:
	/*
	  Constructor
	  Parameters:
	  - string main unit's name
	  - string subunit name
	  - int main unit's value
	  - int subunit's value
	 */
	Currency(CurrencyType type, string wholeName, string fractionalName, int initialWhole, int initialFractional);
	Currency(const Currency& source);
	virtual ~Currency() {}

	// Copy assignment constructor
	virtual Currency& operator= (const Currency& right);

	virtual Currency& operator+= (const Currency& right);
	virtual Currency& operator-= (const Currency& right);

	// TODO: Need to implement these operators
	friend ostream& operator<< (ostream& outStream, const Currency& right);
	friend istream& operator>> (istream& inStream, Currency& right);

	virtual string getWholeName() const { return wholeName; }
	virtual string getFractionalName() const { return fractionalName; }

	CurrencyType getType() const { return type; }
};

#endif