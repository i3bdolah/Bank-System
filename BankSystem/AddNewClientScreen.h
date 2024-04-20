#pragma once
#include "Screen.h";
#include "BankClient.h";
#include "InputValidation.h";
#include "BankUser.h";
using namespace std;

class AddNewClientScreen : protected Screen
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

	static void ShowAddNewClient() {

		if (!CheckPermission(BankUser::enPermissions::eAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("Add New Client");
		
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

		_ReadClientInfo(Client);

		BankClient::enSaveResults SaveResult;
		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case  BankClient::enSaveResults::svSucceeded:
		{
			cout << "\n________________________________\n";
			cout << "\nAccount Added Successfully :-)\n";
			_PrintClient(Client);
			break;
		}
		case BankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\nError Account as not Saved because it's Empty";
			break;
		}
		case BankClient::enSaveResults::svFaildAccountNumberExists:
			cout << "\nError Account was not Saved because it's a Duplicated Account Number";
			break;
		}
	}
};

