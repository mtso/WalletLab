
#include <iostream>
#include <string>

#include "../Headers/Currency.h"
#include "../Headers/CurrencyType.h"

using namespace std;

Currency::Currency(CurrencyType type, int base) : type(type), base(base) {
	value = { 0, 0 };
}

Currency::~Currency() {
	std::cout << "Calling Currency destructor\n";
}

void Currency::normalize() {
	if (value.subunit >= base) {
		value.mainunit += value.subunit / base;
		value.subunit = value.subunit % base;
	}
}
