#pragma once
#include <iostream>
#include "BankUser.h"
#include "Global.h"
#include "Date.h"

using namespace std;

class Screen
{
protected:

	static void _DrawScreenHeader(string Title, string Subtitle = "") {
		cout << "===========================================\n";

		cout << "\t" << Title;

		if (Subtitle != "") cout << "\n\t" << Subtitle;

		cout << "\n\n";
		cout << "Username : " << GlobalUser.Username << endl;
		cout << "Date     : " << Date::GetSystemDate().GetDateInString() << endl;

		cout << "\n===========================================\n\n";
	}

	static bool CheckPermission(BankUser::enPermissions Permission) {

		if (!GlobalUser.CheckPermission(Permission)) {
			_DrawScreenHeader("Access Denied!", "Contact your Admin");
			return false;
		}
		else {
			return true;
		}

	}

};

