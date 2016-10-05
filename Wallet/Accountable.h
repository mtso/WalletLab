
#ifndef ACCOUNTABLE_H
#define ACCOUNTABLE_H

#include <string>
#include "CurrencyType.h"

using namespace std;

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
		Error(int code)
			: code(code), description("ERROR: Attempted to operate on input from a different currency type.") { }
	};

	Accountable(CurrencyType, int, int, int);
	Accountable(const Accountable &);
	virtual ~Accountable();

	// Copy assignment constructor
	virtual Accountable& operator= (const Accountable&);

	// Operator Overloads
	virtual Accountable& operator+= (const Accountable&);
	virtual Accountable& operator-= (const Accountable&);
};

Accountable operator+ (Accountable, const Accountable&);
Accountable operator- (Accountable, const Accountable&);

#endif