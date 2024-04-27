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
		BankClient SenderClient = _ValidateClient();
		_PrintBriefClientLine(SenderClient);

		cout << "\nPlease Enter Receiver Account Number : ";
		BankClient ReceiverClient = _ValidateClient();
		while (ReceiverClient.AccountNumber() == SenderClient.AccountNumber())
		{
			cout << "\nYou've Entered The Same Account!!! ";
			cout << "\nPlease Enter Receiver Account Number : ";
			ReceiverClient = _ValidateClient();
		}
		_PrintBriefClientLine(ReceiverClient);


		double Amount = 0;

		cout << "\nPlease Enter The Amount : ";
		Amount = InputValidation::ReadDouble();

		while (Amount < 0.0 || Amount > SenderClient.AccountBalance)
		{
			cout << "\nPlease Re-Enter Valid Amount : ";
			Amount = InputValidation::ReadDouble();
		}

		cout << "\nAre You Sure, You Want To Transfer This Amount [Y/N] : ";
		char ConfirmationResponse = 'N';
		cin >> ConfirmationResponse;

		if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y') {
			switch (SenderClient.Transfer(Amount, ReceiverClient))
			{
			case BankClient::eInvalidAmount:
				cout << "\nTransfer Cancelled Due Insufficient Balance. You Will Be Re-Directed\n";
				break;
			case BankClient::eSameAccount:
				cout << "\nTransfer Cancelled Due Invalid Account. You Will Be Re-Directed\n";
				break;
			case BankClient::eSuccess:
				cout << "\nAmount Transferred Successfully.\n";
				_PrintBriefClientLine(SenderClient);
				_PrintBriefClientLine(ReceiverClient);
				break;
			}
		}
		else
		{
			cout << "\nTransfer Cancelled. You Will Be Re-Directed\n";
		}
	}
};

