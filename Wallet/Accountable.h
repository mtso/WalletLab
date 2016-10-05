
#ifndef ACCOUNTABLE_H
#define ACCOUNTABLE_H

struct Accountable
{
protected:
	const int base;
	int mainValue;
	int subunitValue;

	void normalize(const int &, int &, int &);

public:
	Accountable(int, int, int);
	virtual ~Accountable();


	// Copy assignment constructor
	Accountable& operator= (const Accountable&);

	// Operator Overloads
	Accountable& operator+= (const Accountable &);
	Accountable& operator-= (const Accountable &);
};

Accountable operator+ (Accountable, const Accountable&);

#endif