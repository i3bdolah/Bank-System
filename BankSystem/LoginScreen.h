#pragma once
#include <iostream>
#include <iomanip>
#include "Screen.h"
#include "BankUser.h"
#include "MainScreen.h"
#include "InputValidation.h"
#include "Global.h"

class LoginScreen : protected Screen
{
private:

	static bool _Login() {
		bool LoginFailed = false;
		short LockCounter = 0;

		string Username, Password;

		do
		{
			if (LoginFailed)
			{
				LockCounter++;
				cout << "\nNot Found!\nPlease Re-Enter Your Username/Password";
				cout << "\n" << "Attempts Left (" << 3 - LockCounter << ").";
				if (LockCounter == 3)
				{
					system("cls");
					cout << "\n\n____________SYSTEM LOCKED____________\n\n";
					system("pause");
					return false;
				}
			}

			cout << "\n\nPlease Enter Username : ";
			cin >> Username;

			cout << "\nPlease Enter Password : ";
			cin >> Password;

			GlobalUser = BankUser::Find(Username, Password);

			LoginFailed = GlobalUser.IsEmpty();

		} while (LoginFailed);

		MainScreen::ShowMainMenu();
		return true;
	}


public:

	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("Login");
		return _Login();
	}

};