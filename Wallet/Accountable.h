/*
 * Accountable
 * Provides a base class for monetary accounting objects
 * Must have a main value
 * Must have a subunit value
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

	/** 
	 * Increments whole value if fractional overflowed or 
	 * decrements whole value if fractional underflowed;
	 * then returns self object
	 * @param wholeValue by reference
	 * @param fractionalValue by reference
	 */
	virtual Accountable& normalized(int& wholeValue, int& fractionalValue);

public:
	/**
	 * Initialize with initial values for the whole and fractional parts.
	 */
	Accountable(const int initialWhole, const int initialFractional);
	
	/**
	 * Copy constructor
	 */
	Accountable(const Accountable& source);
	
	/**
	 * Virtual destructor
	 */
	virtual ~Accountable() {}

	/**
	 * Assignment operator
	 */
	virtual Accountable& operator= (const Accountable&);

	/**
	 * Adds value from the right hand side
	 * @returns this object after the operation
	 */
	virtual Accountable& operator+= (const Accountable& right);
	
	/**
	 * Subtracts the right hand side value from this
	 * This object can go negative.
	 * @returns this object after the operation
	 */
	virtual Accountable& operator-= (const Accountable& right);

	/**
	 * Compares two Accountable objects with Greater-Than operator
	 * @returns true if this object contains greater monetary value than the object on the right-hand side
	 */
	virtual bool operator> (const Accountable& right);
	
	/**
	 * Compares two Accountable objects with Less-Than operator
	 * @returns true if this object contains lesser monetary value than the object on the right-hand side
	 */
	virtual bool operator< (const Accountable& right);

	/**
	 * Compares two Accountable objects using equality operator
	 * @returns true if this object contains the same monetary value as the object on the right-hand side
	 */
	virtual bool operator== (const Accountable& right);

	/**
	 * @returns the whole value of the main unit
	 */
	virtual int getWholeValue() const { return wholeValue; }

	/**
	 * @returns the fractional value of the subunit
	 */
	virtual int getFractionalValue() const { return fractionalValue; }
};

#endif