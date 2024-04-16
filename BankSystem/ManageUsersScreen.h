#pragma once
#include <iostream>
#include "InputValidation.h"
#include "Screen.h"
#include "ListUserScreen.h"
#include "AddNewUserScreen.h"
using namespace std;

class ManageUsersScreen : protected Screen {
private:

	enum enManageUsersOptions { eListUser = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eShowMainMenu = 6 };

	static short _ReadManageUsersOption() {
		cout << "Choose What Do You Want To Do [1 to 6] : ";
		short Choice = InputValidation::ReadShortBetween(1, 6, "Enter Number Between 1 to 6 : ");
		return Choice;
	}

	static void  _GoBackToManageUsers() {
		cout << "\n\n";
		cout << "Press Any Key To Go Back To Manage Users Menu...\n";

		system("pause>0");
		ShowManageUsers();
	}

	static void _ShowListUserScreen() { // enum = 1
		//cout << endl << "List User Screen" << endl;
		ListUserScreen::ShowListUserScreen();
	};
	
	static void _ShowAddNewUserScreen() { // enum = 2
		//cout << endl << "Add New User Screen" << endl;
		AddNewUserScreen::ShowAddNewUserScreen();
	};
	
	static void _ShowDeleteUserScreen() { // enum = 3
		cout << endl << "Delete User Screen" << endl;
	};
	
	static void _ShowUpdateUserScreen() { // enum = 4
		cout << endl << "Update User Screen" << endl;
	};
	
	static void _ShowFindUserScreen() { // enum = 5
		cout << endl << "Find User Screen" << endl;
	};
	
	static void _ShowMainMenuScreen() { // enum = 6
		cout << endl << "Main Menu Screen" << endl;
	};

	static void _PerformManageUsersOption(enManageUsersOptions Option) {
		switch (Option)
		{
		case enManageUsersOptions::eListUser:
			system("cls");
			_ShowListUserScreen();
			_GoBackToManageUsers();
			break;
		case enManageUsersOptions::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsers();
			break;
		case enManageUsersOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsers();
			break;
		case enManageUsersOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsers();
			break;
		case enManageUsersOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsers();
			break;
		case enManageUsersOptions::eShowMainMenu:
			//system("cls");
			// Will Get Back Directly.
			break;
		}
	}
public:

	static void ShowManageUsers() {
		system("cls");

		_DrawScreenHeader("Manage Users Screen");
		cout << "[1] List Users\n";
		cout << "[2] Add New User\n";
		cout << "[3] Delete User\n";
		cout << "[4] Update User\n";
		cout << "[5] Find User\n";
		cout << "[6] Main Menu\n\n";
		cout << "===========================================\n";

		_PerformManageUsersOption((enManageUsersOptions)_ReadManageUsersOption());
	}
};

