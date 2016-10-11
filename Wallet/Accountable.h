/*
 * Accountable
 * Provides a base class for monetary accounting objects
 * Must have a main value
 * Must have a subunit value
 * Must have a subunit base for calculating subunit overflows
 */


#ifndef ACCOUNTABLE_H
#define ACCOUNTABLE_H

/**
 * Accountable is an interface that requires an object to store monetary values
 * so that accounting operations can be performed on it.
 */
class Accountable
{
protected:
	int wholeValue;
	int fractionalValue;

	// Increments whole value if fractional overflowed or 
	// decrements whole value if fractional underflowed;
	// then returns self object
	virtual Accountable& normalized(const int &, int &, int &) = 0;

public:
	// Initialize with base, main, and subunit value
	Accountable(const int initialWhole, const int initialFractional);
	// Copy constructor
	Accountable(const Accountable& source);
	virtual ~Accountable() {}

	// Copy assignment constructor
	virtual Accountable& operator= (const Accountable&);

	// Operator Overloads
	virtual Accountable& operator+= (const Accountable& right);
	virtual Accountable& operator-= (const Accountable& right);

	virtual bool operator> (const Accountable& right);
	virtual bool operator< (const Accountable& right);
	virtual bool operator== (const Accountable& right);

	virtual int getWholeValue() const { return wholeValue; }
	virtual int getFractionalValue() const { return fractionalValue; }
};

#endif