#pragma once
#include <iostream>
#include <iomanip>
#include "Screen.h"
#include "InputValidation.h"
#include "ClientsListScreen.h"
#include "AddNewClientScreen.h"
#include "DeleteClientScreen.h"
#include "UpdateClientScreen.h"
#include "FindClientScreen.h"
#include "TransactionsMenuScreen.h"
using namespace std;

class MainScreen : protected Screen
{
	enum enMainMenuOptions {
		eListClient = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eExit = 8
	};

	static short _ReadMainMenuOption() {
		cout << "Choose What Do You Want To Do [1 to 8] : ";
		short Choice = InputValidation::ReadShortBetween(1, 8, "Enter Number Between 1 to 8 : ");
		return Choice;
	}

	static void  _GoBackToMainMenu() { // enum = 8
		cout << "\n\n";
		cout << "Press Any Key To Go Back To Main Menu...\n";

		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowListClientsScreen() { // enum = 1
		//cout << endl << "List Clients Screen" << endl;
		ClientsListScreen::ShowClientsList();
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
		cout << endl << "Manage Users Screen" << endl;
	}

	static void ShowEndScreen() {
		cout << endl << "End Screen Will Be Here..." << endl;
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
			//_GoBackToMainMenu();
			ShowMainMenu(); // I want to show the main menu directly when the user enters 4 in the transactions screen.
			break;
		case enMainMenuOptions::eManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eExit:
			system("cls");
			_GoBackToMainMenu();
			break;
		}
	}

public:
	static void ShowMainMenu()
	{

		system("cls");
		_DrawScreenHeader("Main Screen");

		//cout << "===========================================\n";
		//cout << "Main Menu\n";
		//cout << "===========================================\n\n";
		cout << "[1] List Clients \n";
		cout << "[2] Add New Client\n";
		cout << "[3] Delete Client\n";
		cout << "[4] Update Client\n";
		cout << "[5] Find Client\n";
		cout << "[6] Transactions\n";
		cout << "[7] Manage Users\n";
		cout << "[8] Logout\n\n";
		cout << "===========================================\n";

		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}
};

