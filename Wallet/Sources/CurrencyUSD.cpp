
#include <iostream>

//#include "../Headers/CurrencyType.h"
#include "../Headers/CurrencyUSD.h"

CurrencyUSD::CurrencyUSD(int initialMainValue, int initialSubValue) : Currency(CurrencyType::USD, 100) {
	value = { initialMainValue, initialSubValue };
}

CurrencyUSD::~CurrencyUSD() {
	std::cout << "Calling USD destructor\n";
}

string Currency::getSubunitName() {
	return "cents";
}