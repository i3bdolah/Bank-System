#pragma once
#include <iostream>
#include <iomanip>
#include "InputValidation.h"
#include "BankUser.h"
#include "Screen.h"
using namespace std;

class ListUserScreen : protected Screen
{
private:

	static void _PrintUserListLine(BankUser User) {
		cout << "| " << left << setw(11) << User.Username;
		cout << "| " << left << setw(20) << User.FullName();
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(25) << User.Email;
		cout << "| " << left << setw(9) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions;
		cout << '\n';
	}

public:

	static void ShowListUserScreen() {
		//vector <BankUser> vUsers = {};
		vector <BankUser> vUsers = BankUser::GetUsersList();
		string Title = "Users List";
		string Subtitle = "(" + to_string(vUsers.size()) + ") User(s).";

		_DrawScreenHeader(Title, Subtitle);
		cout << "\n___________________________________________________";
		cout << "___________________________________________________\n";
		cout << "| " << left << setw(11) << "Username";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(9) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << "\n___________________________________________________";
		cout << "___________________________________________________\n";

		if (vUsers.size() == 0)
		{
			cout << "\n\t\t\t";
			cout << "Sorry, No User Found in The Database.\n";
		}
		else
		{
			for (BankUser& C : vUsers)
			{
				_PrintUserListLine(C);
			}
		}
		cout << "\n___________________________________________________";
		cout << "___________________________________________________\n";
	}
};

