#include <iostream>
#include "MainScreen.h"
using namespace std;


//void PrintShowBalancesListLine(BankClient Client) {
//	cout << "| " << left << setw(25) << Client.AccountNumber();
//	cout << "| " << left << setw(40) << Client.FullName();
//	cout << "| " << left << setw(23) << Client.AccountBalance;
//	cout << '\n';
//}
//
//void ShowClientsBalance() {
//	vector <BankClient> vClients = BankClient::GetClientsList();
//	double TotalBalances = BankClient::GetTotalBalances();
//	//vector <BankClient> vClients = {};
//	//double TotalBalances = 0;
//
//
//	cout << "\t\t\t\t";
//	cout << "Client List (" << vClients.size() << ") Client(s).";
//	cout << "\n________________________________________________";
//	cout << "________________________________________________\n";
//	cout << "| " << left << setw(25) << "Acc. Number";
//	cout << "| " << left << setw(40) << "Name";
//	cout << "| " << left << setw(23) << "Balance";
//	cout << "\n________________________________________________";
//	cout << "________________________________________________\n";
//
//	if (vClients.size() == 0)
//	{
//		cout << "\n\t\t\t";
//		cout << "Sorry, No Client Found in The Database.\n";
//	}
//	else
//	{
//		for (BankClient& C : vClients)
//		{
//			PrintShowBalancesListLine(C);
//		}
//		cout << "\n________________________________________________";
//		cout << "________________________________________________\n";
//		cout << "\n\t\t\t";
//		cout << "Total Balances = " << TotalBalances << endl;
//		cout << "\t\t\t";
//		cout << "(" << String::TrimRight(Utility::NumberToText((int)TotalBalances)) << ")." << endl;
//	}
//	cout << "\n________________________________________________";
//	cout << "________________________________________________\n";
//}

int main()
{
	//UpdateClient();
	//AddNewClient();
	//DeleteClient();
	//ShowClientsList();
	//ShowClientsBalance();

	MainScreen::ShowMainMenu();
}