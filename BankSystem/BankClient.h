#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Person.h"
#include "String.h"
using namespace std;

string const ClientFile = "Clients.txt";

class BankClient : public Person
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkedForDelete = false;

	static BankClient _ConvertLineToClientObject(string Line, string Separator = "#//#") {
		vector <string> vClientData;
		vClientData = String::Split(Line, Separator);

		return BankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	};

	static vector <BankClient> _LoadClientsObjectFromFile() {
		vector <BankClient> _vClients;
		fstream MyFile;
		MyFile.open(ClientFile, ios::in); // Reading Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) // Line By Line
			{
				BankClient CurrClient = _ConvertLineToClientObject(Line);
				_vClients.push_back(CurrClient);
			}
			MyFile.close();
		}
		return _vClients;
	}

	static string _ConvertClientObjectToLine(BankClient Client, string Separator = "#//#") {
		string Line = "";

		Line += Client.FirstName + Separator;
		Line += Client.LastName + Separator;
		Line += Client.Email + Separator;
		Line += Client.Phone + Separator;
		Line += Client.AccountNumber() + Separator;
		Line += Client.PinCode + Separator;
		Line += to_string(Client.AccountBalance);

		return Line;
	}

	static void _SaveClientsObjectToFile(vector <BankClient> vClients) {
		fstream MyFile;
		MyFile.open(ClientFile, ios::out); // Overwrite Mode

		string Line;
		if (MyFile.is_open())
		{
			for (BankClient& C : vClients)
			{
				if (C._MarkedForDelete == false)
				{
					Line = _ConvertClientObjectToLine(C);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _AddLineToFile(string Line, string DestFile = ClientFile) {
		fstream MyFile;
		MyFile.open(DestFile, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	void _Update() {
		vector <BankClient> _vClients = _LoadClientsObjectFromFile();

		for (BankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientsObjectToFile(_vClients);
	}

	void _AddNew() {
		_AddLineToFile(_ConvertClientObjectToLine(*this));
	}

	static BankClient _GetEmptyClientObject() {
		return BankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	};

public:

	BankClient(enMode _Mode,
		string _FirstName, string _LastName, string _Email, string _Phone,
		string _AccountNumber, string _PinCode, double _AccountBalance)
		: Person(_FirstName, _LastName, _Email, _Phone) {
		this->_Mode = _Mode;
		this->_AccountNumber = _AccountNumber;
		this->_PinCode = _PinCode;
		this->_AccountBalance = _AccountBalance;
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	string AccountNumber() { return _AccountNumber; }

	void SetPinCode(string _PinCode) { this->_PinCode = _PinCode; }
	string GetPinCode() { return _PinCode; }
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double _AccountBalance) { this->_AccountBalance = _AccountBalance; }
	double GetAccountBalance() { return _AccountBalance; }
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	// No UI Related In the Back-end.

	/*void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}*/

	static BankClient Find(string AccountNumber) {
		fstream MyFile;
		MyFile.open(ClientFile, ios::in); // Reading Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) // Line By Line
			{
				BankClient CurrClient = _ConvertLineToClientObject(Line);
				if (CurrClient.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return CurrClient;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static BankClient Find(string AccountNumber, string PinCode) {
		fstream MyFile;
		MyFile.open(ClientFile, ios::in); // Reading Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) // Line By Line
			{
				BankClient CurrClient = _ConvertLineToClientObject(Line);
				if (CurrClient.AccountNumber() == AccountNumber
					&& CurrClient.PinCode == PinCode)
				{
					MyFile.close();
					return CurrClient;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save() {
		switch (_Mode)
		{
		case BankClient::EmptyMode:
		{
			return enSaveResults::svFailedEmptyObject;
		}

		case BankClient::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}

		case BankClient::AddNewMode:
		{

			if (BankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return svSucceeded;
			}
		}
		}
	}

	static bool IsClientExist(string AccountNumber)
	{
		return !Find(AccountNumber).IsEmpty();
	}

	static BankClient GetAddNewClientObject(string AccountNumber) {
		return BankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete() {
		vector <BankClient> vClients = _LoadClientsObjectFromFile();

		for (BankClient& C : vClients)
		{
			if (C._AccountNumber == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientsObjectToFile(vClients);
		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <BankClient> GetClientsList() {
		return _LoadClientsObjectFromFile();
	}

	static double GetTotalBalances() {
		vector <BankClient> vClients = _LoadClientsObjectFromFile();
		double Total = 0.0;

		for (BankClient& C : vClients)
		{
			Total += C.AccountBalance;
		}
		return Total;
	}

	void Deposit(double Amount) {
		AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount) {
		if (AccountBalance < Amount)
		{
			return false;
		}
		else
		{
			AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	enum enTranferStatus { eInvalidAmount = 1, eSameAccount = 2, eSuccess = 3 };

	enTranferStatus Transfer(double Amount, BankClient& ReceiverClient) {
		if (Amount < 0.0 || Amount > this->AccountBalance)
		{
			return enTranferStatus::eInvalidAmount;
		}
		else if (this->AccountNumber() == ReceiverClient.AccountNumber()) {
			return enTranferStatus::eSameAccount;
		}
		else
		{
			this->Withdraw(Amount);
			ReceiverClient.Deposit(Amount);
			return enTranferStatus::eSuccess;
		}
	}
};