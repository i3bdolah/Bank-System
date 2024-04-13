#pragma once
#include <iostream>
#include <iomanip>
#include "String.h"
#include "Utility.h"
#include "InputValidation.h"
#include "BankClient.h"
#include "Screen.h"
using namespace std;


class TotalBalancesScreen : protected Screen
{
private:

	static void _PrintTotalBalancesLine(BankClient Client) {
		cout << "| " << left << setw(25) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(23) << Client.AccountBalance;
		cout << '\n';
	}

public:

	static void ShowTotalBalancesScreen() {
		vector <BankClient> vClients = BankClient::GetClientsList();

		string Title = "Client List";
		string Subtitle = "(" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, Subtitle);
		cout << "\n________________________________________________";
		cout << "________________________________________________\n";
		cout << "| " << left << setw(25) << "Acc. Number";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(23) << "Balance";
		cout << "\n________________________________________________";
		cout << "________________________________________________\n";

		if (vClients.size() == 0)
		{
			cout << "\n\t\t\t";
			cout << "Sorry, No Client Found in The Database.\n";
		}
		else
		{
			double TotalBalances = BankClient::GetTotalBalances();

			for (BankClient& C : vClients)
			{
				_PrintTotalBalancesLine(C);
			}
			cout << "\n________________________________________________";
			cout << "________________________________________________\n";
			cout << "\t\t\t";
			cout << "Total Balances = " << TotalBalances << endl;
			cout << "\t\t\t";
			cout << "(" << String::TrimRight(Utility::NumberToText((int)TotalBalances)) << ").";
		}
		cout << "\n________________________________________________";
		cout << "________________________________________________\n";
	}
};

