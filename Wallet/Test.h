
#ifndef TEST_H
#define TEST_H

#include <iostream>

using namespace std;

namespace Test
{
	template<typename T>
	void check(T expectedValue, T actualValue, string filename, double lineNumber)
	{
		if (expectedValue == actualValue) 
		{
			cout << filename << "\\" << lineNumber << " Success" << endl;
		}
		else 
		{
			cout << filename << "\\" << lineNumber << " Failure" << endl;
		}
	}
};

#endif