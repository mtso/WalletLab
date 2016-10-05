
#include <iostream>

//#include "CurrencyType.h"
#include "GBPCurrency.h"
#include "USDCurrency.h"
#include "Accountable.h"

using namespace std;

int main() {

	for (int i = USD; i < 5 && i <= AUD; i++)
	{
		cout << i << endl;
	}
	USDCurrency usd1 = USDCurrency(20, 60);
	GBPCurrency gbp = GBPCurrency(5, 5);
	Currency broad = usd1;

	Currency *usd = new USDCurrency(20, 20);

	*usd += *usd;

	broad = usd1 + usd1;
	broad += usd1;

	cout << broad.getValue().main << '.' << broad.getValue().subunit << endl;

	broad += gbp;

	cout << broad.getValue().main << '.' << broad.getValue().subunit << endl;

	delete usd;


	Currency sub1 = USDCurrency(1, 1);
	Currency sub2 = USDCurrency(0, 20);

	sub1 -= sub2;

	cout << sub1.getValue().main << '.' << sub1.getValue().subunit << endl;

	Accountable acct = Accountable(100, 10, 10);

	acct = acct + acct;
	acct += acct;

	system("pause");

	return 0;
}