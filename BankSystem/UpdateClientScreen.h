#pragma once
#include <iostream>
#include <iomanip>
#include "BankClient.h"
#include "Screen.h"
using namespace std;

class UpdateClientScreen : protected Screen
{
private:
	static void _ReadClientInfo(BankClient& Client)
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = InputValidation::ReadString();

		cout << "\nEnter Last Name: ";
		Client.LastName = InputValidation::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = InputValidation::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = InputValidation::ReadString();

		cout << "\nEnter Pin Code: ";
		Client.PinCode = InputValidation::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = InputValidation::ReadDouble();
	}

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

	static void ShowUpdateClient() {
		_DrawScreenHeader("Update Client");

		string AccountNumber = "";

		cout << "\nPlease Enter Your Account Number : ";
		AccountNumber = InputValidation::ReadString();

		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nNot Found!\nPlease Re-Enter Your Account Number : ";
			AccountNumber = InputValidation::ReadString();
		}

		BankClient Client = BankClient::Find(AccountNumber);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";


		_ReadClientInfo(Client);

		BankClient::enSaveResults SaveResult;
		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case  BankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(Client);
			break;
		}
		case BankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\nError Account as not Saved because it's Empty";
			break;
		}
		}
	}

};

