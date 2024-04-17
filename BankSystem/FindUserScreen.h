#pragma once
#include <iostream>
#include <iomanip>
#include "InputValidation.h"
#include "BankUser.h"
#include "Screen.h"

using namespace std;

class FindUserScreen : protected Screen
{
private:

	static void _PrintUser(BankUser User) {
		cout << "\nUser Card :";
		cout << "\n___________________";
		cout << "\nFirst Name  : " << User.FirstName;
		cout << "\nLast Name   : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUsername    : " << User.Username;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}

public:

	static void ShowFindUserScreen() {
		_DrawScreenHeader("Find User");

		string Username = "";

		cout << "\nPlease Enter Username : ";
		Username = InputValidation::ReadString();
		while (!BankUser::IsUserExist(Username))
		{
			cout << "\nThe Username Is NOT Exist!\n";
			cout << "Please Re-Enter Your Username : ";
			Username = InputValidation::ReadString();
		}

		BankUser User = BankUser::Find(Username);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found\n";
		}
		else {
			cout << "\nSorry, User Is Empty!\n";
		}

		_PrintUser(User);
	}

};

