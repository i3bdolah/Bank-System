#pragma once
#include <iostream>
#include <iomanip>
#include "InputValidation.h"
#include "BankUser.h"
#include "Screen.h"
#include "clsListCurrencyScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;

class clsCurrencyMenuScreen : protected Screen
{
	enum enCurrencysMenuOptions { eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4 , eShowMainMenu = 5
	};

	static short _ReadCurrencyMenuOption() {
		cout << "Choose What Do You Want To Do [1 to 5] : ";
		short Choice = InputValidation::ReadShortBetween(1, 5, "Enter Number Between 1 to 5 : ");
		return Choice;
	}

	static void  _GoBackToTransactionsMenu() {
		cout << "\n\n";
		cout << "Press Any Key To Go Back To Transactions Menu...\n";

		system("pause>0");
		ShowCurrencyMenu();
	}

	static void _ShowListCurrency() {
		//cout << "ListCurrency" << endl;
		clsListCurrencyScreen::ShowListCurrency();
	}

	static void _ShowFindCurrency() {
		//cout << "FindCurrency" << endl;
		 clsFindCurrencyScreen::ShowFindCurrency();
	}

	static void _ShowUpdateRate() {
		//cout << "UpdateRate" << endl;
		 clsUpdateRateScreen::ShowUpdateRate();
	}

	static void _ShowCurrencyCalculator() {
		//cout << "CurrencyCalculator" << endl;
		 clsCurrencyCalculatorScreen::ShowCurrencyCalculator();
	}

	static void _PerformTransactionsMenuOption(enCurrencysMenuOptions Option) {
		switch (Option)
		{	
		case clsCurrencyMenuScreen::eListCurrency:
			system("cls");
			_ShowListCurrency();
			_GoBackToTransactionsMenu();
			break;
		case clsCurrencyMenuScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrency();
			_GoBackToTransactionsMenu();
			break;
		case clsCurrencyMenuScreen::eUpdateRate:
			system("cls");
			_ShowUpdateRate();
			_GoBackToTransactionsMenu();
			break;
		case clsCurrencyMenuScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToTransactionsMenu();
			break;
		case clsCurrencyMenuScreen::eShowMainMenu:
			break;
		}
	}

public:

	static void ShowCurrencyMenu() {
		system("cls");
		_DrawScreenHeader("Currency Exchange Menu");
		cout << "[1] List Currencies\n";
		cout << "[2] Find Currency\n";
		cout << "[3] Update Rate\n";
		cout << "[4] Currency Calculator\n";
		cout << "[5] Main Menu\n\n";
		cout << "===========================================\n";

		_PerformTransactionsMenuOption((enCurrencysMenuOptions)_ReadCurrencyMenuOption());

	}
};

