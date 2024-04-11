#pragma once
#include <iostream>

using namespace std;

class Screen
{
protected:
	static void _DrawScreenHeader(string Title, string Subtitle = "") {
		cout << "______________________________________\n\n";
		cout << Title;

		if (Subtitle != "")
		{
			cout << "\n" << Subtitle;
		}
		cout << "\n______________________________________\n\n";
	}
};

