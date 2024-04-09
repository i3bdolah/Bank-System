#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Person.h"
#include "String.h"
using namespace std;

string const File = "Clients.txt";

class BankClient : public Person
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;

	static BankClient _ConvertLineToObject(string Line, string Separator = "#//#") {
		vector <string> vClientData;
		vClientData = String::Split(Line, Separator);

		return BankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	};

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

	string AccountNumber() { return _AccountNumber; }

	void SetPinCode(string _PinCode) { this->_PinCode = _PinCode; }
	string GetPinCode() { return _PinCode; }
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double _AccountBalance) { this->_AccountBalance = _AccountBalance; }
	double GetAccountBalance() { return _AccountBalance; }
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	void Print()
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

	}

	static BankClient Find(string AccountNumber) {
		fstream MyFile;
		MyFile.open(File, ios::in); // Reading Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) // Line By Line
			{
				BankClient CurrClient = _ConvertLineToObject(Line);
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
		MyFile.open(File, ios::in); // Reading Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) // Line By Line
			{
				BankClient CurrClient = _ConvertLineToObject(Line);
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

	static bool IsClientExist(string AccountNumber)
	{
		return !Find(AccountNumber).IsEmpty();
	}

};

