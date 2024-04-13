#pragma once
#include <iostream>
#include <iomanip>
#include "Screen.h"
#include "BankClient.h"
#include "InputValidation.h"
using namespace std;

class WithdrawScreen : protected Screen {
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

	static void ShowWithdrawScreen() {
		_DrawScreenHeader("Withdraw");

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
		cout << "\nPlease Enter The Withdraw Amount : ";
		Amount = InputValidation::ReadDouble();

		while (!(Amount > 0.0 && Amount <= Client.AccountBalance))
		{
			cout << "\nPlease Re-Enter Valid Withdraw Amount : ";
			Amount = InputValidation::ReadDouble();
		}

		cout << "\nAre you sure, You want to Withdraw This Amount [Y/N] : ";
		char ConfirmationResponse = 'N';
		cin >> ConfirmationResponse;

		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y') {

			if (Client.Withdraw(Amount)) {
				cout << "\nAmount Withdrawn Successfully.\n";
				cout << "\nThe New Balance for " << Client.FullName() << " is = " << Client.AccountBalance << "\n";
			}
			else
			{
				cout << "\nWithdraw Cancelled Due Insufficient Balance. You Will Be Re-Directed\n";
			}

		}
		else
		{
			cout << "\nWithdraw Cancelled. You Will Be Re-Directed\n";
		}

	}

};

