#pragma once
#include <iostream>
#include <iomanip>
#include "InputValidation.h"
#include "BankClient.h"
#include "Screen.h"
using namespace std;

class DepositScreen : protected Screen {
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

	static void ShowDepositScreen() {
		_DrawScreenHeader("Deposit");

		string AccountNumber = "";

		cout << "\nPlease Enter Your Account Number : ";
		AccountNumber = InputValidation::ReadString();

		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nNot Found!\nPlease Re-Enter Your Account Number : ";
			AccountNumber = InputValidation::ReadString();
		}

		BankClient Client = BankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0.0;
		cout << "\nPlease Enter The Deposit Amount : ";
		Amount = InputValidation::ReadDouble();

		cout << "\nAre you sure, You want to Deposit This Amount [Y/N] : ";
		char ConfirmationResponse = 'N';
		cin >> ConfirmationResponse;

		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y') {
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nThe New Balance for " << Client.FullName() << " is = " << Client.AccountBalance <<"\n";
		}
		else
		{
			cout << "\nDeposit Cancelled. You Will Be Re-Directed\n";
		}
	}

};

