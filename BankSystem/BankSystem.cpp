#include <iostream>
#include "LoginScreen.h"
#include "Global.h"
using namespace std;

int main()
{
	while (true)
	{
		if (!LoginScreen::ShowLoginScreen()) {
			break;
		}
	}
}