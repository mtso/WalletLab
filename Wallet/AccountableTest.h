
#ifndef ACCOUNTABLETEST_H
#define ACCOUNTABLETEST_H

#include "Accountable.h"
#include "Test.h"

namespace AccountableTest
{

	void constructAccountable()
	{
		Accountable accountableObject = Accountable(100, 10, 10);
		Test::check<int>(10, accountableObject.getMainValue(), __FILE__, __LINE__);
		Test::check<int>(10, accountableObject.getSubunitValue(), __FILE__, __LINE__);
	}

	void runAccountableTests()
	{
		constructAccountable();
	}
}

#endif