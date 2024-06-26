#pragma once
#include <iostream>
#include <iomanip>
#include "InputValidation.h"
#include "Screen.h"
#include "BankUser.h"
#include "DepositScreen.h"
#include "WithdrawScreen.h"
#include "TotalBalancesScreen.h"
#include "TransferScreen.h"
#include "TransferLogScreen.h"
using namespace std;

class TransactionsMenuScreen : protected Screen {
private:

	enum enTransactionsMenuOptions
	{
		eDeposit = 1, 
		eWithdraw = 2, 
		eShowTotalBalances = 3, 
		eTransfer = 4, 
		eTransferLog = 5,
		eShowMainMenu = 6
	};

	static short _ReadTransactionsMenuOption() {
		cout << "Choose What Do You Want To Do [1 to 6] : ";
		short Choice = InputValidation::ReadShortBetween(1, 6, "Enter Number Between 1 to 6 : ");
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

	static void _ShowTransferScreen() { // enum 4
		//cout << endl << "Show Transfer Screen" << endl;
		TransferScreen::ShowTransferScreen();
	};

	static void _ShowTransferLogScreen() { // enum 4
		//cout << endl << "Show Transfer Log Screen" << endl;
		TransferLogScreen::ShowTransferLogScreen();
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
		case enTransactionsMenuOptions::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
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
		cout << "[4] Transfer\n";
		cout << "[5] Transfer Log\n";
		cout << "[6] Main Menu\n\n";
		cout << "===========================================\n";

		_PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}

};

