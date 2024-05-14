#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Screen.h"
#include "clsCurrency.h"
#include "InputValidation.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected Screen {
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

	static clsCurrency _GetCurrency(string Msg) {
		cout << "\n" << Msg;
		string enteredValue = InputValidation::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(enteredValue);

		while (Currency.IsEmpty())
		{
			cout << "\nPlease Re-" + Msg;
			enteredValue = InputValidation::ReadString();
			Currency = clsCurrency::FindByCode(enteredValue);
		}
		_PrintShortCurrency(Currency);

		return Currency;
	}

	static void _PrintCalculation(float Amount, clsCurrency FromCurrency, clsCurrency ToCurrency) {
		float AmountInUSD = FromCurrency.ConvertToUSD(Amount);

		cout << "\n\n" << Amount << " (" << FromCurrency.CurrencyCode() << ")";

		if (!(FromCurrency.CurrencyCode() == "USD" || ToCurrency.CurrencyCode() == "USD"))
		{
			cout << " = ";
			cout << AmountInUSD << " (USD)";
		}

		float AmountInToCurrency = FromCurrency.ConvertToOtherCurrency(Amount, ToCurrency);

		cout << " = ";
		cout << AmountInToCurrency << " (" << ToCurrency.CurrencyCode() << ")";
	}
public:

	static void ShowCurrencyCalculator() {
		_DrawScreenHeader("Currency Calculator");

		clsCurrency FromCurrency = _GetCurrency("Enter The (FROM) Currency Code : ");
		clsCurrency ToCurrency = _GetCurrency("Enter The (TO) Currency Code : ");

		cout << "\nEnter The Amount : ";
		float Amount = InputValidation::ReadFloat();

		_PrintCalculation(Amount, FromCurrency, ToCurrency);
	};
};