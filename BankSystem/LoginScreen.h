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

	static void _Login() {
		bool LoginFailed = false;
		string Username, Password;

		do
		{

			if (LoginFailed)
			{
				cout << "\nNot Found!\nPlease Re-Enter Your Username/Password";
			}

			cout << "\n\nPlease Enter Username : ";
			cin >> Username;
			
			cout << "\nPlease Enter Password : ";
			cin >> Password;

			GlobalUser = BankUser::Find(Username, Password);

			LoginFailed = GlobalUser.IsEmpty();

		} while (LoginFailed);

		MainScreen::ShowMainMenu();
	}

public:

	static void ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("Login");
		_Login();
	}

};