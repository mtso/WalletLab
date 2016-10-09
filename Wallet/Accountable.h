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

	// Explicitly pass in all inputs for clarity
	Accountable& normalized(const int &, int &, int &);

public:
	// Initialize with base, main, and subunit value
	Accountable(const int, const int, const int);
	// Copy constructor
	Accountable(const Accountable&);
	virtual ~Accountable() {}

	// Copy assignment constructor
	Accountable& operator= (const Accountable&);

	// Operator Overloads
	Accountable& operator+= (const Accountable&);
	Accountable& operator-= (const Accountable&);

	friend Accountable operator+ (const Accountable&, const Accountable&);
	friend Accountable operator- (const Accountable&, const Accountable&);

	int getMainValue() { return mainValue; }
	int getSubunitValue() { return subunitValue; }
};

#endif