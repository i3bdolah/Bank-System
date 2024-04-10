#include <iostream>
#include "BankClient.h"
#include "InputValidation.h"
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
		cout << "\nNot Found ...\nPlease Re-Enter Your Account Number : ";
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
		cout << "\nThe Number Is Already Used ...\n";
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

int main()
{
	//UpdateClient();
	AddNewClient();
}