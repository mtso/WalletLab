
#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

#include "Accountable.h"
#include "CurrencyType.h"

using namespace std;

class Currency : public Accountable {
protected:
	string wholeName;
	string fractionalName;
	CurrencyType type;

	virtual Accountable& normalized(int& wholeValue, int& fractionalValue);

public:
	/**
	 * Constructor
	 * Parameters:
	 * - string main unit's name
	 * - string subunit name
	 * - int main unit's value
	 * - int subunit's value
	 */
	Currency(CurrencyType type, string wholeName, string fractionalName, int initialWhole, int initialFractional);
	Currency(const Currency& source);
	virtual ~Currency() {}

	// Copy assignment constructor
	virtual Currency& operator= (const Currency& right);

	virtual Currency& operator+= (const Currency& right);
	virtual Currency& operator-= (const Currency& right);

	/**
	 * Allows the currency object to print its name and value to an ostream object.
	 * @param ostream object
	 * @param right-hand side currency object
	 */
	friend ostream& operator<< (ostream& outStream, const Currency& right);
	friend istream& operator>> (istream& inStream, Currency& right);

	virtual string getWholeName() const { return wholeName; }
	virtual string getFractionalName() const { return fractionalName; }

	CurrencyType getType() const { return type; }

	virtual Currency* clone() const = 0;


	friend Currency& operator+ (Currency& left, const Currency& right);
	friend Currency& operator- (Currency& left, const Currency& right);

};

#endif