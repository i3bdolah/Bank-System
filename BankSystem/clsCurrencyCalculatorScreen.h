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

	//static void _PrintResult(clsCurrency FromCurrency, clsCurrency ToCurrency) {
	//	cout << Amount << " (" << FromCurrency.CurrencyCode() << ") = ";
	//	cout << AmountInUsd << " (" << ToCurrency.CurrencyCode() << ")" << endl;
	//}

public:

	static void ShowCurrencyCalculator() {
		_DrawScreenHeader("Currency Calculator");


		// FROM
		cout << "\nEnter The (FROM) Currency Code : ";
		string enteredValue = InputValidation::ReadString();
		clsCurrency FromCurrency = clsCurrency::FindByCode(enteredValue);

		while (FromCurrency.IsEmpty())
		{
			cout << "\nPlease Re-Enter The (FROM) Currency Code : ";
			enteredValue = InputValidation::ReadString();
			FromCurrency = clsCurrency::FindByCode(enteredValue);
		}
		_PrintShortCurrency(FromCurrency);


		// TO
		cout << "\nEnter The (TO) Currency Code : ";
		enteredValue = InputValidation::ReadString();
		clsCurrency ToCurrency = clsCurrency::FindByCode(enteredValue);

		while (ToCurrency.IsEmpty())
		{
			cout << "\nPlease Re-Enter The (TO) Currency Code : ";
			enteredValue = InputValidation::ReadString();
			ToCurrency = clsCurrency::FindByCode(enteredValue);
		}
		_PrintShortCurrency(ToCurrency);


		// AMOUNT
		cout << "\nEnter The Amount in (" << FromCurrency.CurrencyCode() << ") : ";
		float FromAmount = InputValidation::ReadFloat();

		// Conversion
		clsCurrency USD = clsCurrency::FindByCode("USD");
		float UsdAmount = 0;
		float ToAmount = 0;

		if (USD.RateInUSD() > ToCurrency.RateInUSD())
		{
			UsdAmount = FromAmount / FromCurrency.RateInUSD();
			ToAmount = UsdAmount / ToCurrency.RateInUSD();
		}
		else if (USD.RateInUSD() <= ToCurrency.RateInUSD())
		{
			UsdAmount = FromAmount * FromCurrency.RateInUSD();
			ToAmount = UsdAmount * ToCurrency.RateInUSD();
		}

		cout << "\n\n";
		cout << FromAmount << " (" << FromCurrency.CurrencyCode() << ") = ";
		cout << UsdAmount << " (" << USD.CurrencyCode() << ") = ";
		cout << ToAmount << " (" << ToCurrency.CurrencyCode() << ")" << endl;
	}

};

