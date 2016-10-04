
#include <iostream>
#include <string>

#include "../Headers/USDCurrency.h"

USDCurrency::USDCurrency(int initialMainValue, int initialSubValue) 
			: Currency(USD, 100, "dollars", "cents") 
{
	
	value = { initialMainValue, initialSubValue };
}

USDCurrency::~USDCurrency() {
	std::cout << "Calling USD destructor\n";
}
