#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Screen.h"
#include "clsCurrency.h"

using namespace std;

class clsListCurrencyScreen : protected Screen
{
private:

	static void _PrintCurrencyLine(clsCurrency Obj) {
		cout << "| " << left << setw(30) << Obj.Country();
		cout << "| " << left << setw(20) << Obj.CurrencyCode();
		cout << "| " << left << setw(40) << Obj.CurrencyName();
		cout << "| " << left << setw(15) << Obj.RateInUSD();
		cout << '\n';
	}

public:

	static void ShowListCurrency() {
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		string Title = "List Currencies";
		string Subtitle = "(" + to_string(vCurrencies.size()) + ") Currency(s).";

		_DrawScreenHeader(Title, Subtitle);
		cout << "\n__________________________________________________________";
		cout << "__________________________________________________________\n";
		cout << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(20) << "Currency Code";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << left << setw(15) << "Rate In USD";
		cout << "\n__________________________________________________________";
		cout << "__________________________________________________________\n";

		if (vCurrencies.size() == 0)
		{
			cout << "\n\t\t\t";
			cout << "Sorry, No Client Found in The Database.\n";
		}
		else
		{
			for (clsCurrency &C : vCurrencies)
			{
				_PrintCurrencyLine(C);
			}
		}

		cout << "\n__________________________________________________________";
		cout << "__________________________________________________________\n";
	}
};

