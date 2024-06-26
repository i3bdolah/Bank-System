#pragma once
#include <iostream>
#include <iomanip>
#include "Screen.h"
using namespace std;

class LoginRegisterScreen : protected Screen
{
private:

	static void _PrintRegisterLine(BankUser::stLoginLog Line) {
		cout << "| " << left << setw(20) << Line.DateTime;
		cout << "| " << left << setw(20) << Line.Username;
		cout << "| " << left << setw(20) << Line.Password;
		cout << "| " << left << setw(20) << Line.Permissions;
		cout << '\n';
	}

public:

	static void ShowLoginRegister() {

		if (!CheckPermission(BankUser::enPermissions::eLoginRegister))
		{
			return;
		}

		vector <BankUser::stLoginLog> vLines = BankUser::GetUsersLogs();
		//vector <string> vLines = {};

		string Title = "Register Logs List";
		string Subtitle = "(" + to_string(vLines.size()) + ") Log(s).";

		_DrawScreenHeader(Title, Subtitle);
		cout << "\n-------------------------------------------------------";
		cout << "-------------------------------------------------------\n";
		cout << "| " << left << setw(20) << "Date/Time";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(20) << "Permission";
		cout << "\n-------------------------------------------------------";
		cout << "-------------------------------------------------------\n";

		if (vLines.size() == 0)
		{
			cout << "\n\t\t\t";
			cout << "Sorry, No Client Found in The Database.\n";
		}
		else
		{
			for (BankUser::stLoginLog& L : vLines)
			{
				_PrintRegisterLine(L);
			}
		}
		cout << "\n-------------------------------------------------------";
		cout << "-------------------------------------------------------\n";
	}

};

