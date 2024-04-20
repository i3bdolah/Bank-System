#pragma once
#include <iostream>
#include <iomanip>
#include "InputValidation.h"
#include "Screen.h"
#include "BankUser.h"
#include "DepositScreen.h"
#include "WithdrawScreen.h"
#include "TotalBalancesScreen.h"
using namespace std;

class TransactionsMenuScreen : protected Screen {
private:

	enum enTransactionsMenuOptions
	{
		eDeposit = 1, eWithdraw = 2, eShowTotalBalances = 3, eShowMainMenu = 4
	};

	static short _ReadTransactionsMenuOption() {
		cout << "Choose What Do You Want To Do [1 to 4] : ";
		short Choice = InputValidation::ReadShortBetween(1, 4, "Enter Number Between 1 to 4 : ");
		return Choice;
	}

	static void  _GoBackToTransactionsMenu() {
		cout << "\n\n";
		cout << "Press Any Key To Go Back To Transactions Menu...\n";

		system("pause>0");
		ShowTransactionsMenu();
	}

	static void _ShowDepositScreen() { // enum 1
		//cout << endl << "Deposit Screen" << endl;
		DepositScreen::ShowDepositScreen();
	};

	static void _ShowWithdrawScreen() { // enum 2
		//cout << endl << "Withdraw Screen" << endl;
		WithdrawScreen::ShowWithdrawScreen();
	};

	static void _ShowShowTotalBalancesScreen() { // enum 3
		//cout << endl << "Show Total Balances Screen" << endl;
		TotalBalancesScreen::ShowTotalBalancesScreen();
	};

	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions Option) {
		switch (Option)
		{
		case enTransactionsMenuOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::eShowTotalBalances:
			system("cls");
			_ShowShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::eShowMainMenu:
			//system("cls");
			// Will Get Back Directly.
			break;
		}
	}

public:

	static void ShowTransactionsMenu()
	{

		if (!CheckPermission(BankUser::enPermissions::eTransactions))
		{
			return;
		}


		system("cls");
		_DrawScreenHeader("Transactions Screen");

		//cout << "===========================================\n";
		//cout << "Transactions Menu\n";
		//cout << "===========================================\n\n";
		cout << "[1] Deposit\n";
		cout << "[2] Withdraw\n";
		cout << "[3] Total Balances\n";
		cout << "[4] Main Menu\n\n";
		cout << "===========================================\n";

		_PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}

};

