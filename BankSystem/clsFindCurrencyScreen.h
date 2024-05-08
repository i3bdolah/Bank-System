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
		cout << "\n\n___________________________" << endl;
		cout << "Currency Details" << endl;
		cout << "___________________________" << endl;
		cout << "Country        : " << Obj.Country() << endl;
		cout << "Currency Code  : " << Obj.CurrencyCode() << endl;
		cout << "Currency Name  : " << Obj.CurrencyName() << endl;
		cout << "Rate In USD    : " << Obj.RateInUSD() << endl;
		cout << "___________________________\n\n";
	}

	static void _ShowResult(clsCurrency Obj) {
		if (!Obj.IsEmpty())
		{
			cout << "\nCurrency Found :-)" << endl;
			_PrintShortCurrency(Obj);
		}
		else
		{
			cout << "\nCurrency NOT Found :-(" << endl;
		}
	}

public:

	static void ShowFindCurrency() {
		_DrawScreenHeader("Find Currency");
		enum enFindBy { eCurrncyCode = 1, eCountry };

		short Choice;
		cout << "\nFind Currency By \n[Currency Code = 1] or [Country = 2] : ";
		cin >> Choice;
		while (Choice != eCurrncyCode && Choice != eCountry)
		{
			cout << "\nFind Currency By \n[Currency Code = 1] or [Country = 2] : ";
			Choice = InputValidation::ReadShortBetween(1,2);
		}

		string enteredValue = "";
		clsCurrency Currency;
		switch (Choice)
		{
		case enFindBy::eCurrncyCode:
			cout << "\nEnter The Currency Code : ";
			enteredValue = InputValidation::ReadString();
			Currency = clsCurrency::FindByCode(enteredValue);
			break;
		case enFindBy::eCountry:
			cout << "\nEnter The Country : ";
			enteredValue = InputValidation::ReadString();
			Currency = clsCurrency::FindByCountry(enteredValue);
			break;
		}

		_ShowResult(Currency);

	}
};

