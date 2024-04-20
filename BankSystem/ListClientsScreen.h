#pragma once
#include <iostream>
#include <iomanip>
#include "BankClient.h"
#include "Screen.h"
#include "BankUser.h"
using namespace std;

class ListClientsScreen : protected Screen
{
private:
	
	static void _PrintClientListLine(BankClient Client) {
		cout << "| " << left << setw(11) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(25) << Client.Email;
		cout << "| " << left << setw(9) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;
		cout << '\n';
	}

public:

	static void ShowClientsList() {

		if (!CheckPermission(BankUser::enPermissions::eListClients))
		{
			return;
		}

		//vector <BankClient> vClients = {};
		vector <BankClient> vClients = BankClient::GetClientsList();
		string Title = "Client List";
		string Subtitle = "(" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, Subtitle);
		cout << "\n________________________________________________";
		cout << "________________________________________________\n";
		cout << "| " << left << setw(11) << "Acc. Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(9) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n________________________________________________";
		cout << "________________________________________________\n";

		if (vClients.size() == 0)
		{
			cout << "\n\t\t\t";
			cout << "Sorry, No Client Found in The Database.\n";
		}
		else
		{
			for (BankClient& C : vClients)
			{
				_PrintClientListLine(C);
			}
		}
		cout << "\n________________________________________________";
		cout << "________________________________________________\n";
	}
};

