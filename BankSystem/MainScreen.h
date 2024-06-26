#pragma once
#include <iostream>
#include "Screen.h"
#include "InputValidation.h"
#include "ListClientsScreen.h"
#include "AddNewClientScreen.h"
#include "DeleteClientScreen.h"
#include "UpdateClientScreen.h"
#include "FindClientScreen.h"
#include "TransactionsMenuScreen.h"
#include "ManageUsersScreen.h"
#include "LoginRegisterScreen.h"
#include "clsCurrencyMenuScreen.h"
#include "Global.h"
using namespace std;

class MainScreen : protected Screen
{
	enum enMainMenuOptions {
		eListClient = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrency = 9, eLogout = 10
	};

	static short _ReadMainMenuOption() {
		cout << "Choose What Do You Want To Do [1 to 10] : ";
		short Choice = InputValidation::ReadShortBetween(1, 10, "Enter Number Between 1 to 10 : ");
		return Choice;
	}

	static void  _GoBackToMainMenu() {
		cout << "\n\n";
		cout << "Press Any Key To Go Back To Main Menu...\n";

		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowListClientsScreen() { // enum = 1
		//cout << endl << "List Clients Screen" << endl;
		ListClientsScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen() { // enum = 2
		//cout << endl << "Add New Clients Screen" << endl;
		AddNewClientScreen::ShowAddNewClient();
	}

	static void _ShowDeleteClientsScreen() { // enum = 3
		//cout << endl << "Delete Clients Screen" << endl;
		DeleteClientScreen::ShowDeleteClient();
	}

	static void _ShowUpdateClientsScreen() { // enum = 4
		//cout << endl << "Update Clients Screen" << endl;
		UpdateClientScreen::ShowUpdateClient();
	}

	static void _ShowFindClientsScreen() { // enum = 5
		//cout << endl << "Find Clients Screen" << endl;
		FindClientScreen::ShowFindClient();
	}

	static void _ShowTransactionsMenuScreen() { // enum = 6
		//cout << endl << "Transactions Menu Screen" << endl;
		TransactionsMenuScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersScreen() { // enum = 7
		//cout << endl << "Manage Users Screen" << endl;
		ManageUsersScreen::ShowManageUsers();
	}

	static void _ShowLoginRegisterScreen() { // enum 8 
		//cout << endl << "Login Register Screen" << endl;
		LoginRegisterScreen::ShowLoginRegister();
	}

	static void _ShowCurrencyMenuScreen() { // enum 8 
		//cout << endl << "Show Currency Menu Screen" << endl;
		clsCurrencyMenuScreen::ShowCurrencyMenu();
	}

	static void _Logout() {
		GlobalUser = BankUser::Find("", "");
	}

	static void _PerformMainMenuOption(enMainMenuOptions Option) {
		switch (Option)
		{
		case enMainMenuOptions::eListClient:
			system("cls");
			_ShowListClientsScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientsScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientsScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eFindClient:
			system("cls");
			_ShowFindClientsScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eShowTransactionsMenue:
			system("cls");
			_ShowTransactionsMenuScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eCurrency:
			system("cls");
			_ShowCurrencyMenuScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eLogout:
			system("cls");
			_Logout();
			break;
		}
	}

public:
	static void ShowMainMenu()
	{

		system("cls");
		_DrawScreenHeader("Main Screen");

		cout << "[1]  List Clients \n";
		cout << "[2]  Add New Client\n";
		cout << "[3]  Delete Client\n";
		cout << "[4]  Update Client\n";
		cout << "[5]  Find Client\n";
		cout << "[6]  Transactions\n";
		cout << "[7]  Manage Users\n";
		cout << "[8]  Login Register\n";
		cout << "[9]  Currency Exchange\n";
		cout << "[10] Logout\n\n";
		cout << "===========================================\n";

		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}
};

