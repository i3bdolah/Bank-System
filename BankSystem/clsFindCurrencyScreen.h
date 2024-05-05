#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Screen.h"
#include "clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen : protected Screen
{
private:

	static void _PrintShortCurrency(clsCurrency Obj) {
		cout << "Currency Details" << endl;
		cout << "___________________________" << endl;
		cout << "Country        : " << Obj.Country() << endl;
		cout << "Currency Code  : " << Obj.CurrencyCode() << endl;
		cout << "Currency Name  : " << Obj.CurrencyName() << endl;
		cout << "Rate In USD    : " << Obj.RateInUSD() << endl;
		cout << "___________________________\n\n";
	}

public:

	static void ShowFindCurrency() {
		_DrawScreenHeader("Find Currency");
		enum enFindBy {eCurrncyCode = 1, eCountry};

		short Choice;
		cout << "Find Currency By \n[Currency Code = 1] or [Country = 2] : " << endl;
		cin >> Choice;
		while (Choice != eCurrncyCode && Choice != eCountry)
		{
			cout << "Find Currency By \n[Currency Code = 1] or [Country = 2] : " << endl;
			cin >> Choice;
		}

		switch (Choice)
		{
		case enFindBy::eCurrncyCode:
			break;
		case enFindBy::eCountry:
			break;
		}
	}
};

