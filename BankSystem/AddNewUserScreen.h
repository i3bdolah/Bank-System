#pragma once
#include "Screen.h";
#include "BankUser.h";
#include "InputValidation.h";

using namespace std;

class AddNewUserScreen : protected Screen {

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

		cout << "\nAccess To Login Register [Y/N]  : ";
		cin >> ConfirmationResponse;
		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			Permissions += BankUser::enPermissions::eLoginRegister;
		}
		
		return Permissions;
	}

public:

	static void ShowAddNewUserScreen() {
		_DrawScreenHeader("Add New User");

		string Username = "";

		cout << "\nPlease Enter Username : ";
		Username = InputValidation::ReadString();
		while (BankUser::IsUserExist(Username))
		{
			cout << "\nThe Username Is Already Exist!\n";
			cout << "Please Re-Enter Your Username : ";
			Username = InputValidation::ReadString();
		}

		BankUser User = BankUser::GetAddNewUserObject(Username);

		_ReadUserInfo(User);

		BankUser::enSaveResults SaveResult = User.Save();

		switch (SaveResult)
		{
		case BankUser::svSucceeded:
			cout << "\n________________________________\n";
			cout << "\nUser Added Successfully :-)\n";
			
			_PrintUser(User);
			break;
		case BankUser::svFailedEmptyObject:
			cout << "\nError! User was not Saved because it's Empty";
			break;
		case BankUser::svFaildUsernameExists:
			cout << "\nError! User was not Saved because it's a Duplicated Username";
			break;
		}
	}
};

