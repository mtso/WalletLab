
#ifndef ACCOUNTABLE_H
#define ACCOUNTABLE_H

#include <string>
#include "CurrencyType.h"

using namespace std;

/* Struct Accountable "Description Text"
 *
 */
struct Accountable
{
protected:
	const CurrencyType type;
	const int base;
	int mainValue;
	int subunitValue;

	void normalize(const int &, int &, int &);

public:
	struct Error 
	{
		const int code;
		const string description;

		// Error code 0: =, 1: +=, 2: -=
		Error(int code)
			: code(code), description("ERROR: Attempted to operate on input from a different currency type.") { }
		Error(int code, int flag)
			: code(code), description( (flag < 0) ? "ERROR: Not enough value to subtract from" : "" ) { }

	};

	Accountable(CurrencyType, int, int, int);
	Accountable(const Accountable &);
	virtual ~Accountable();

	// Copy assignment constructor
	virtual Accountable& operator= (const Accountable&);

	// Operator Overloads
	virtual Accountable& operator+= (const Accountable&);
	virtual Accountable& operator-= (const Accountable&);

	// Returns this object's CurrencyType.
	CurrencyType getType() { return type; }
};

Accountable operator+ (Accountable, const Accountable&);
Accountable operator- (Accountable, const Accountable&);

#endif