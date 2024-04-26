#pragma once
#include <iostream>
#include <iomanip>
#include "InputValidation.h"
#include "BankUser.h"
#include "Screen.h"

using namespace std;

class DeleteUserScreen : protected Screen
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

	static void ShowDeleteUserScreen() {
		_DrawScreenHeader("Delete User");

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
		_PrintUser(User);

		cout << "\nAre You Sure, You Want To Delete This User [Y/N] : ";
		char ConfirmationResponse = 'N';
		cin >> ConfirmationResponse;

		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
				_PrintUser(User); // Should be empty object
			}
			else
			{
				cout << "\nUser was NOT Deleted\n";
			}
		}
		else {
			cout << "\nDeletion Cancelled. You Will Be Re-Directed\n";
		}

	}
};

