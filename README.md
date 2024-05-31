# Bank System Desktop Application

## Overview

### Introduction
The Bank System desktop application is developed using C++. It offers a comprehensive solution for managing banking operations, including client management, user management, and currency exchange functionalities. This document provides an overview of the application's architecture, functionalities, and usage.

### Why Bank System
This application aims to streamline banking operations by providing a unified platform for managing clients, users, and currency exchange processes. By integrating these functionalities, the Bank System ensures efficient and secure handling of financial transactions and data management.

### Architecture
The application is structured into three main sub-systems:
- **Bank Client**
- **Bank User**
- **Currency Exchange**

Additionally, it utilizes several custom libraries to support various functionalities, such as date management, input validation, and utility functions.

## Sub-Systems

### Bank Client
The Bank Client sub-system handles all client-related operations. It includes the following functionalities:

| Functionality              | Description                                               |
|----------------------------|-----------------------------------------------------------|
| AddNewClientScreen         | Allows the addition of new clients to the system.         |
| DeleteClientScreen         | Enables the deletion of existing clients from the system. |
| FindClientScreen           | Provides functionality to search for clients based on specific criteria. |
| ListClientsScreen          | Displays a list of all clients registered in the system.  |
| UpdateClientScreen         | Allows updating the information of existing clients.      |
| DepositScreen              | Facilitates depositing money into a client's account.     |
| WithdrawScreen             | Facilitates withdrawing money from a client's account.    |
| TransferScreen             | Enables transferring money between client accounts.       |
| TransferLogScreen          | Displays a log of all money transfers made.               |
| TotalBalancesScreen        | Shows the total balances of all client accounts.          |
| TransactionsMenuScreen     | Provides a menu for navigating different transaction-related screens. |

### Bank User
The Bank User sub-system is responsible for managing users who interact with the banking system. It includes the following functionalities:

| Functionality              | Description                                               |
|----------------------------|-----------------------------------------------------------|
| AddNewUserScreen           | Allows the addition of new users to the system.           |
| DeleteUserScreen           | Enables the deletion of existing users from the system.   |
| FindUserScreen             | Provides functionality to search for users based on specific criteria. |
| ListUserScreen             | Displays a list of all users registered in the system.    |
| UpdateUserScreen           | Allows updating the information of existing users.        |
| LoginScreen                | Provides a login interface for users to access the system.|
| LoginRegisterScreen        | Handles the registration of new users and logging in of existing users. |
| ManageUsersScreen          | Offers an interface for managing user roles and permissions.|

### Currency Exchange
The Currency Exchange sub-system manages currency-related operations. It includes the following functionalities:

| Functionality              | Description                                               |
|----------------------------|-----------------------------------------------------------|
| CurrencyCalculatorScreen   | Provides a calculator for currency conversions.           |
| CurrencyMenuScreen         | Displays a menu for navigating different currency-related screens. |
| FindCurrencyScreen         | Allows searching for currencies based on specific criteria.|
| ListCurrencyScreen         | Displays a list of all available currencies in the system.|
| UpdateRateScreen           | Enables updating the exchange rates for currencies.       |


## Usage
![Screenshot 2024-05-31 152442](https://github.com/i3bdolah/Bank-System/assets/80276711/8ece8268-f236-40ed-ab8a-a1d95b05e32e)
![Screenshot 2024-05-31 152458](https://github.com/i3bdolah/Bank-System/assets/80276711/e4d15082-9880-4f10-aeac-59a8463e7c3b)
![Screenshot 2024-05-31 152523](https://github.com/i3bdolah/Bank-System/assets/80276711/2e0267b1-4da5-48ec-8121-5e7beb4e2854)
![Screenshot 2024-05-31 152534](https://github.com/i3bdolah/Bank-System/assets/80276711/46d34fb3-ce32-465d-99c3-f14fa8aa2e57)
![Screenshot 2024-05-31 152543](https://github.com/i3bdolah/Bank-System/assets/80276711/21a8521c-9972-4dc8-a5ec-38d52311ba52)
![Screenshot 2024-05-31 152558](https://github.com/i3bdolah/Bank-System/assets/80276711/a8c051c3-6de9-47ed-ace7-4f01c8dbeb22)
![Screenshot 2024-05-31 152610](https://github.com/i3bdolah/Bank-System/assets/80276711/79fcd981-a716-4c35-80ec-d038c33fbdbe)
![Screenshot 2024-05-31 152620](https://github.com/i3bdolah/Bank-System/assets/80276711/740e6aae-25de-4851-bc92-b2bd26f16179)
![Screenshot 2024-05-31 152638](https://github.com/i3bdolah/Bank-System/assets/80276711/4aeb7bb9-a092-4d7f-a4f7-86c1e1854661)
![Screenshot 2024-05-31 152647](https://github.com/i3bdolah/Bank-System/assets/80276711/f66e0976-b872-44dd-b2e0-9724743afae6)
![Screenshot 2024-05-31 152718](https://github.com/i3bdolah/Bank-System/assets/80276711/09105c13-74ee-444f-8a3a-9bdcd484dff4)


## Conclusion
The Bank System desktop application is designed to streamline and secure banking operations, providing robust functionalities for managing clients, users, and currency exchange processes. With a modular architecture and custom libraries, the application ensures efficiency and flexibility, making it a valuable tool fits banking needs.
