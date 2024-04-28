#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Person.h"
#include "Date.h"
#include "String.h"
using namespace std;

string const UserFile = "Users.txt";
string const LoginRegisterFile = "Login Register.txt";

class BankUser : public Person
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _Username;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;

	static BankUser _ConvertLineToUserObject(string Line, string Separator = "#//#") {
		vector <string> vUserData;
		vUserData = String::Split(Line, Separator);

		return BankUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
	};

	static vector <BankUser> _LoadUsersObjectFromFile() {
		vector <BankUser> _vUser;
		fstream MyFile;
		MyFile.open(UserFile, ios::in); // Reading Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) // Line By Line
			{
				BankUser CurrUser = _ConvertLineToUserObject(Line);
				_vUser.push_back(CurrUser);
			}
			MyFile.close();
		}
		return _vUser;
	}

	static string _ConvertUserObjectToLine(BankUser User, string Separator = "#//#") {
		string Line = "";

		Line += User.FirstName + Separator;
		Line += User.LastName + Separator;
		Line += User.Email + Separator;
		Line += User.Phone + Separator;
		Line += User.Username + Separator;
		Line += User.Password + Separator;
		Line += to_string(User.Permissions);

		return Line;
	}

	static void _SaveUsersObjectToFile(vector <BankUser> vUser) {
		fstream MyFile;
		MyFile.open(UserFile, ios::out); // Overwrite Mode

		string Line;
		if (MyFile.is_open())
		{
			for (BankUser& C : vUser)
			{
				if (C._MarkedForDelete != true)
				{
					Line = _ConvertUserObjectToLine(C);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _AddLineToFile(string Line, string DestFile = UserFile) {
		fstream MyFile;
		MyFile.open(DestFile, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	void _Update() {
		vector <BankUser> _vUser = _LoadUsersObjectFromFile();

		for (BankUser& C : _vUser)
		{
			if (C.Username == _Username)
			{
				C = *this;
				break;
			}
		}
		_SaveUsersObjectToFile(_vUser);
	}

	void _AddNew() {
		_AddLineToFile(_ConvertUserObjectToLine(*this));
	}

	static BankUser _GetEmptyUserObject() {
		return BankUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	};

	string _CreateLogLine() {
		string date = Date::GetSystemDate().GetDateInString();
		string time = Date::GetSystemTime();

		vector <string> Line = { time, Username, Password, to_string(Permissions) };

		string FormattedLine = date + " - " + String::Join(Line, "#//#");

		return FormattedLine;
	}

	static vector <string> _LoadUsersLogs() {
		vector <string> _vLines;
		fstream MyFile;
		MyFile.open(LoginRegisterFile, ios::in); // Reading Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) // Line By Line
			{
				_vLines.push_back(Line);
			}
			MyFile.close();
		}
		return _vLines;
	}
public:

	enum enPermissions {
		eListClients = 1,
		eAddNewClient = 2,
		eUpdateClient = 4,
		eDeleteClient = 8,
		eFindClient = 16,
		eTransactions = 32,
		eManageUsers = 64,
		eLoginRegister = 128,
		eAll = -1
	};

	BankUser(enMode _Mode,
		string _FirstName, string _LastName, string _Email, string _Phone,
		string _Username, string _Password, int _Permissions)
		: Person(_FirstName, _LastName, _Email, _Phone) {
		this->_Mode = _Mode;
		this->_Username = _Username;
		this->_Password = _Password;
		this->_Permissions = _Permissions;
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	void SetUsername(string _Username) { this->_Username == _Username; }
	string GetUsername() { return _Username; }
	__declspec(property(get = GetUsername, put = SetUsername)) string Username;

	void SetPassword(string _Password) { this->_Password = _Password; }
	string GetPassword() { return _Password; }
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int _Permissions) { this->_Permissions = _Permissions; }
	int GetPermissions() { return _Permissions; }
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static BankUser Find(string Username) {
		fstream MyFile;
		MyFile.open(UserFile, ios::in); // Reading Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) // Line By Line
			{
				BankUser CurrUser = _ConvertLineToUserObject(Line);
				if (CurrUser.Username == Username)
				{
					MyFile.close();
					return CurrUser;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static BankUser Find(string Username, string Password) {
		fstream MyFile;
		MyFile.open(UserFile, ios::in); // Reading Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) // Line By Line
			{
				BankUser CurrUser = _ConvertLineToUserObject(Line);
				if (CurrUser.Username == Username
					&& CurrUser.Password == Password)
				{
					MyFile.close();
					return CurrUser;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	enum enSaveResults {
		svFailedEmptyObject = 0,
		svSucceeded = 1,
		svFaildUsernameExists = 2
	};

	enSaveResults Save() {
		switch (_Mode)
		{
		case BankUser::EmptyMode:
		{
			return enSaveResults::svFailedEmptyObject;
		}

		case BankUser::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}

		case BankUser::AddNewMode:
		{

			if (BankUser::IsUserExist(_Username))
			{
				return enSaveResults::svFaildUsernameExists;
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

	static bool IsUserExist(string Username)
	{
		return !Find(Username).IsEmpty();
	}

	static BankUser GetAddNewUserObject(string Username) {
		return BankUser(enMode::AddNewMode, "", "", "", "", Username, "", 0);
	}

	bool Delete() {
		vector <BankUser> vUser = _LoadUsersObjectFromFile();

		for (BankUser& C : vUser)
		{
			if (C._Username == _Username)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveUsersObjectToFile(vUser);
		*this = _GetEmptyUserObject();

		return true;
	}

	static vector <BankUser> GetUsersList() {
		return _LoadUsersObjectFromFile();
	}

	bool CheckPermission(enPermissions Permission) {
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((this->Permissions & Permission) == Permission)
			return true;
		else
			return false;
	}

	bool RegisterLogin() {
		if (!this->IsEmpty())
		{
			_AddLineToFile(_CreateLogLine(), LoginRegisterFile);
			return true;
		}
		else
		{
			return false;
		}
	}

	static vector <string> GetUsersLogs() {
		return _LoadUsersLogs();
	}
};

