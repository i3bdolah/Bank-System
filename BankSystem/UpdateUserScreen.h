#pragma once
#include <iostream>
#include <iomanip>
#include "InputValidation.h"
#include "BankUser.h"
#include "Screen.h"

using namespace std;

class UpdateUserScreen : protected Screen
{
private:
	static void _ReadUserInfo(BankUser& User)
	{
		cout << "\nEnter First Name : ";
		User.FirstName = InputValidation::ReadString();

		cout << "\nEnter Last Name : ";
		User.LastName = InputValidation::ReadString();

		cout << "\nEnter Email : ";
		User.Email = InputValidation::ReadString();

		cout << "\nEnter Phone : ";
		User.Phone = InputValidation::ReadString();

		cout << "\nEnter Password : ";
		User.Password = InputValidation::ReadString();

		//cout << "\nEnter Permissions : ";
		User.Permissions = _ReadPermissions();
	}

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

	static int _ReadPermissions() {
		int Permissions = 0;
		char ConfirmationResponse = 'N';

		cout << "\nObtain Full-Access [Y/N] : ";
		cin >> ConfirmationResponse;
		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			return -1;
		}

		cout << "\n\nAccess To List Clients [Y/N]   : ";
		cin >> ConfirmationResponse;
		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			Permissions += BankUser::enPermissions::eListClients;
		}

		cout << "\nAccess To Add New Client [Y/N] : ";
		cin >> ConfirmationResponse;
		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			Permissions += BankUser::enPermissions::eAddNewClient;
		}

		cout << "\nAccess To Update Client [Y/N]  : ";
		cin >> ConfirmationResponse;
		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			Permissions += BankUser::enPermissions::eUpdateClient;
		}

		cout << "\nAccess To Delete Client [Y/N]  : ";
		cin >> ConfirmationResponse;
		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			Permissions += BankUser::enPermissions::eDeleteClient;
		}

		cout << "\nAccess To Find Client [Y/N]    : ";
		cin >> ConfirmationResponse;
		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			Permissions += BankUser::enPermissions::eFindClient;
		}

		cout << "\nAccess To Transactions [Y/N]   : ";
		cin >> ConfirmationResponse;
		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			Permissions += BankUser::enPermissions::eTransactions;
		}

		cout << "\nAccess To Manage Users [Y/N]   : ";
		cin >> ConfirmationResponse;
		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			Permissions += BankUser::enPermissions::eManageUsers;
		}

		return Permissions;
	}
public:

	static void ShowUpdateUser() {
		_DrawScreenHeader("Update User");

		string Username = "";

		cout << "\nPlease Enter Your Username : ";
		Username = InputValidation::ReadString();

		while (!BankUser::IsUserExist(Username))
		{
			cout << "\nThe Username Is NOT Exist!\n";
			cout << "Please Re-Enter Your Username : ";
			Username = InputValidation::ReadString();
		}

		BankUser User = BankUser::Find(Username);

		_PrintUser(User);

		cout << "\nAre you sure, You want to Update This User [Y/N] : ";
		char ConfirmationResponse = 'N';
		cin >> ConfirmationResponse;

		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			cout << "\n\nUpdate User Info:";
			cout << "\n____________________\n";

			_ReadUserInfo(User);

			BankUser::enSaveResults SaveResult;
			SaveResult = User.Save();

			switch (SaveResult)
			{
			case  BankUser::enSaveResults::svSucceeded:
			{
				cout << "\nAccount Updated Successfully :-)\n";
				cout << "\n\nThe Updated User Info:";
				cout << "\n____________________\n";
				_PrintUser(User);
				break;
			}
			case BankUser::enSaveResults::svFailedEmptyObject:
			{
				cout << "\nError Account as not Saved because it's Empty";
				break;
			}
			}
		}
		else
		{
			cout << "\nUpdate Cancelled. You Will Be Re-Directed\n";
		}

	}

};

