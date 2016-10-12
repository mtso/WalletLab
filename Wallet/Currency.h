
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
	 * General Constructor
	 * @param string main unit's name
	 * @param string subunit name
	 * @param int main unit's value
	 * @param int subunit's value
	 */
	Currency(CurrencyType type, string wholeName, string fractionalName, int initialWhole, int initialFractional);
	
	/**
	 * Copy constructor
	 */
	Currency(const Currency& source);
	
	/**
	 * Nothing to delete
	 */
	virtual ~Currency() {}

	/**
	 * assignment constructor
	 */
	virtual Currency& operator= (const Currency& right);

	/**
	 * Checks the objects' types before allowing the Accountable's += operation.
	 */
	virtual Currency& operator+= (const Currency& right);

	/**
	 * Checks the objects' types before allowing the Accountable's -= operation.
	 */
	virtual Currency& operator-= (const Currency& right);

	/**
	 * Allows the currency object to print its name and value to an ostream object.
	 * @param ostream object
	 * @param right-hand side currency object
	 */
	friend ostream& operator<< (ostream& outStream, const Currency& right);

	/**
	 * Takes in two integers from the user as input for the currency's value.
	 */
	friend istream& operator>> (istream& inStream, Currency& right);

	/**
	 * Returns the name of the whole part of the currency.
	 */
	virtual string getWholeName() const { return wholeName; }

	/**
	 * Returns the name of the fractional part of the currency
	 */
	virtual string getFractionalName() const { return fractionalName; }

	/**
	 * Returns the currency's type
	 */
	CurrencyType getType() const { return type; }

	/**
	 * Returns a new instance of the currency
	 */
	virtual Currency* clone() const = 0;
};

#endif