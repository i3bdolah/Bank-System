#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Screen.h"
#include "clsCurrency.h"

using namespace std;

class clsUpdateRateScreen : protected Screen
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

public:

	static void ShowUpdateRate() {
		_DrawScreenHeader("Update Rate");
		string enteredValue = "";


		cout << "\nEnter The Currency Code : ";
		enteredValue = InputValidation::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(enteredValue);

		while (Currency.IsEmpty())
		{
			cout << "\nEnter The Currency Code : ";
			enteredValue = InputValidation::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(enteredValue);
		}

		_PrintShortCurrency(Currency);
		cout << "\nEnter The Updated Rate : ";
		float newRate = InputValidation::ReadFloat();

		char ConfirmationResponse = 'N';
		cout << "\nAre you sure, you still want to update [Y - N] : ";
		cin >> ConfirmationResponse;

		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			Currency.UpdateRate(newRate);
			cout << "\n\nRate Updated Successfully :-)";
			_PrintShortCurrency(Currency);
		}
	}
};

