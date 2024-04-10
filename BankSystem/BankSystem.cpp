#include <iostream>
#include "BankClient.h"
#include "InputValidation.h"
#include "Utility.h"
using namespace std;

void ReadClientInfo(BankClient& Client)
{
	cout << "\nEnter FirstName: ";
	Client.FirstName = InputValidation::ReadString();

	cout << "\nEnter LastName: ";
	Client.LastName = InputValidation::ReadString();

	cout << "\nEnter Email: ";
	Client.Email = InputValidation::ReadString();

	cout << "\nEnter Phone: ";
	Client.Phone = InputValidation::ReadString();

	cout << "\nEnter PinCode: ";
	Client.PinCode = InputValidation::ReadString();

	cout << "\nEnter Account Balance: ";
	Client.AccountBalance = InputValidation::ReadDouble();
}

void UpdateClient() {
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


	ReadClientInfo(Client);

	BankClient::enSaveResults SaveResult;
	SaveResult = Client.Save();

	switch (SaveResult)
	{
	case  BankClient::enSaveResults::svSucceeded:
	{
		cout << "\nAccount Updated Successfully :-)\n";
		Client.Print();
		break;
	}
	case BankClient::enSaveResults::svFaildEmptyObject:
	{
		cout << "\nError Account as not Saved because it's Empty";
		break;
	}
	}
}

void AddNewClient() {
	string AccountNumber = "";

	cout << "\nPlease Enter Account Number : ";
	AccountNumber = InputValidation::ReadString();
	while (BankClient::IsClientExist(AccountNumber))
	{
		cout << "\nThe Number Is Already Exist!\n";
		cout << "Please Re-Enter Your Account Number : ";
		AccountNumber = InputValidation::ReadString();
	}

	BankClient Client = BankClient::GetAddNewClientObject(AccountNumber);

	ReadClientInfo(Client);

	BankClient::enSaveResults SaveResult;
	SaveResult = Client.Save();

	switch (SaveResult)
	{
	case  BankClient::enSaveResults::svSucceeded:
	{
		cout << "\n________________________________\n";
		cout << "\nAccount Updated Successfully :-)\n";
		Client.Print();
		break;
	}
	case BankClient::enSaveResults::svFaildEmptyObject:
	{
		cout << "\nError Account as not Saved because it's Empty";
		break;
	}
	case BankClient::enSaveResults::svFaildAccountNumberExists:
		cout << "\nError Account was not Saved because it's a Duplicated Account Number";
		break;
	}
}

void DeleteClient() {
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
	Client.Print();

	cout << "\nAre you sure, You want to Delete This Client [Y/N] : ";
	char ConfirmationResponse = 'N';
	cin >> ConfirmationResponse;

	if (ConfirmationResponse == 'Y' || ConfirmationResponse == 'y')
	{
		if (Client.Delete())
		{
			cout << "\nClient Deleted Successfully :-)\n";
			Client.Print(); // Should be empty object
		}
		else
		{
			cout << "\nClient was NOT Deleted\n";
		}
	}

}

void PrintShowClientsListLine(BankClient Client) {
	cout << "| " << left << setw(11) << Client.AccountNumber();
	cout << "| " << left << setw(20) << Client.FullName();
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(25) << Client.Email;
	cout << "| " << left << setw(9) << Client.PinCode;
	cout << "| " << left << setw(12) << Client.AccountBalance;
	cout << '\n';
}

void ShowClientsList() {
	//vector <BankClient> vClients = {};
	vector <BankClient> vClients = BankClient::GetClientsList();

	cout << "\t\t\t\t";
	cout << "Client List (" << vClients.size() << ") Client(s).";
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
			PrintShowClientsListLine(C);
		}
	}
	cout << "\n________________________________________________";
	cout << "________________________________________________\n";
}

void PrintShowBalancesListLine(BankClient Client) {
	cout << "| " << left << setw(25) << Client.AccountNumber();
	cout << "| " << left << setw(40) << Client.FullName();
	cout << "| " << left << setw(23) << Client.AccountBalance;
	cout << '\n';
}

void ShowClientsBalance() {
	vector <BankClient> vClients = BankClient::GetClientsList();
	double TotalBalances = BankClient::GetTotalBalances();


	cout << "\t\t\t\t";
	cout << "Client List (" << vClients.size() << ") Client(s).";
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
		for (BankClient& C : vClients)
		{
			PrintShowBalancesListLine(C);
		}
	}
	cout << "\n________________________________________________";
	cout << "________________________________________________\n";
	cout << "\n\t\t\t";
	cout << "Total Balances = " << TotalBalances << endl;
	cout << "\t\t\t";
	cout << "( " << Utility::NumberToText((int)TotalBalances) << ")." << endl;
}

int main()
{
	//UpdateClient();
	//AddNewClient();
	//DeleteClient();
	//ShowClientsList();
	ShowClientsBalance();
}