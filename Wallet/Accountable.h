/*
 * Accountable
 * Provides a base class for monetary accounting objects
 * Must have a main value
 * Must have a subunit value
 * Must have a subunit base for calculating subunit overflows
 */


#ifndef ACCOUNTABLE_H
#define ACCOUNTABLE_H

class Accountable
{
protected:
	const int base;
	int mainValue;
	int subunitValue;

	// Explicitly passing in all inputs for clarity
	Accountable& normalize(const int &, int &, int &);

public:
	Accountable(const int, const int, const int);
	Accountable(const Accountable&);
	virtual ~Accountable() {}

	// Copy assignment constructor
	Accountable& operator= (const Accountable&);

	// Operator Overloads
	Accountable& operator+= (const Accountable&);
	Accountable& operator-= (const Accountable&);
};

Accountable operator+ (const Accountable&, const Accountable&);
Accountable operator- (const Accountable&, const Accountable&);

#endif