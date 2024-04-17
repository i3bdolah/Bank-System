#pragma once
#include <iostream>
#include <iomanip>
#include "BankClient.h"
#include "Screen.h"
using namespace std;

class FindClientScreen : protected Screen
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

	static void ShowFindClient() {
		_DrawScreenHeader("Find Client");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number : ";
		AccountNumber = InputValidation::ReadString();
		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThe Client Is NOT Found!\n";
			cout << "Please Re-Enter Your Account Number : ";
			AccountNumber = InputValidation::ReadString();
		}

		BankClient Client = BankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found\n";
		}
		else {
			cout << "\nSorry, Client Is Empty!\n";
		}

		_PrintClient(Client);
	}

};

