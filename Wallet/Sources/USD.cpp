

//#include "../Headers/CurrencyType.h"
#include "../Headers/USD.h"

USD::USD(int initialMainValue, int initialSubValue) : Currency(CurrencyType::USD, 100) {
	value = { initialMainValue, initialSubValue };
}