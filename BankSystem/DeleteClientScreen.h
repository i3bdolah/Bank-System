#pragma once
#include <iostream>
#include <iomanip>
#include "BankClient.h"
#include "BankUser.h"
#include "Screen.h"
#include "InputValidation.h"
using namespace std;

class DeleteClientScreen : protected Screen
{
private:

	static void _PrintClient(BankClient Client) {
		cout << "\nClient Card :";
		cout << "\n___________________";
		cout << "\nFirst Name  : " << Client.FirstName;
		cout << "\nLast Name   : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:

	static void ShowDeleteClient() {

		if (!CheckPermission(BankUser::enPermissions::eDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("Delete Client");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number : ";
		AccountNumber = InputValidation::ReadString();
		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThe Number Is NOT Exist!\n";
			cout << "Please Re-Enter Your Account Number : ";
			AccountNumber = InputValidation::ReadString();
		}

		BankClient Client = BankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nAre you sure, You want to Delete This Client [Y/N] : ";
		char ConfirmationResponse = 'N';
		cin >> ConfirmationResponse;

		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintClient(Client); // Should be empty object
			}
			else
			{
				cout << "\nClient was NOT Deleted\n";
			}
		}
		else {
			cout << "\nDeletion Cancelled. You Will Be Re-Directed\n";
		}

	}

};

