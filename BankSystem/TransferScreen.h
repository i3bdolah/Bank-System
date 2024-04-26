#pragma once
#include <iostream>
#include "Screen.h"
#include "InputValidation.h"
#include "BankClient.h"
using namespace std;

class TransferScreen : protected Screen
{
private:

	static void _PrintBriefClientLine(BankClient Client) {
		cout << "\nClient Card :";
		cout << "\n___________________";
		cout << "\nAccount Number  : " << Client.AccountNumber();
		cout << "\nFull Name       : " << Client.FullName();
		cout << "\nAccount Balance : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static BankClient _ValidateClient() {
		string AccountNumber = InputValidation::ReadString();

		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nNot Found!\nPlease Re-Enter Your Account Number : ";
			AccountNumber = InputValidation::ReadString();
		}

		return BankClient::Find(AccountNumber);
	}
public:

	static void ShowTransferScreen() {
		_DrawScreenHeader("Transfer");

		cout << "\nPlease Enter Sender Account Number : ";
		BankClient FromClient = _ValidateClient();
		_PrintBriefClientLine(FromClient);

		cout << "\nPlease Enter Receiver Account Number : ";
		BankClient ToClient = _ValidateClient();
		while (ToClient.AccountNumber() == FromClient.AccountNumber())
		{
			cout << "\nYou've Entered The Same Account!!! ";
			cout << "\nPlease Enter Receiver Account Number : ";
			ToClient = _ValidateClient();
		}
		_PrintBriefClientLine(ToClient);


		double Amount = 0;

		cout << "\nPlease Enter The Amount : ";
		Amount = InputValidation::ReadDouble();

		while (Amount < 0.0 || Amount >= FromClient.AccountBalance)
		{
			cout << "\nPlease Re-Enter Valid Amount : ";
			Amount = InputValidation::ReadDouble();
		}

		cout << "\nAre You Sure, You Want To Transfer This Amount [Y/N] : ";
		char ConfirmationResponse = 'N';
		cin >> ConfirmationResponse;

		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y') {

			if (FromClient.Withdraw(Amount)) {
				cout << "\nAmount Transferred Successfully.\n";
				cout << "\nThe New Balance for " << FromClient.FullName() << " is = " << FromClient.AccountBalance << "\n";
				ToClient.Deposit(Amount);
			}
			else
			{
				cout << "\nTransfer Cancelled Due Insufficient Balance. You Will Be Re-Directed\n";
			}

		}
		else
		{
			cout << "\nTransfer Cancelled. You Will Be Re-Directed\n";
		}
	}
};

