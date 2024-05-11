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

	static float _AmountInUSD(float Amount, clsCurrency FromCurrency) {

	}

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
		float Amount = InputValidation::ReadFloat();

		// Conversion
		float Result = 0;
		clsCurrency USD = clsCurrency::FindByCode("USD");
		Amount = Amount / FromCurrency.RateInUSD();


		if (FromCurrency.RateInUSD() < ToCurrency.RateInUSD())
		{
			Result = Amount * ToCurrency.RateInUSD();
			cout << "FROM Currency is Less than TO Currency" << endl;
			cout << Result << " (" << ToCurrency.CurrencyCode() << ")" << endl;
		}
		else if (FromCurrency.RateInUSD() > ToCurrency.RateInUSD())
		{
			Result = Amount / ToCurrency.RateInUSD();
			cout << "FROM Currency is More than TO Currency" << endl;
			cout << Result << " (" << ToCurrency.CurrencyCode() << ")" << endl;
		}
		else if (FromCurrency.RateInUSD() == ToCurrency.RateInUSD())
		{
			Result = Amount * USD.RateInUSD();
			cout << "FROM Currency is Equals TO Currency" << endl;
			cout << Result << " (" << ToCurrency.CurrencyCode() << ")" << endl;
		}

	}

};

