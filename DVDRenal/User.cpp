#include "User.h"
#include "menu.h"
#include <iostream>

///////////////////////////////////////////////////////////
// Print user choice decision panel
// return user choice
///////////////////////////////////////////////////////////
string User::printPanel()
{
    system("cls");
    string title = "DVD RENTAL - WELCOME " + m_firstName + " " + m_lastName;
    string choice{};

    print_title(title);

    cout << "\t\t1. Show all films" << endl
        << "\t\t2. Show your films" << endl
        << "\t\t3. Change password" << endl
        << "\t\t4. Back" << endl;

    cout << "\n\n\tPlease enter your choice: ";
    getline(cin, choice);

    if (choice.length() > 1)
        choice = "x";

    return choice;
}

///////////////////////////////////////////////////////////
// Print user change password panel
// Set new password
///////////////////////////////////////////////////////////
void User::changePassword()
{
    system("cls");
    string title = "DVD RENTAL - CHANGE PASSWORD FOR " + m_firstName + " " + m_lastName;

    print_title(title);

    string pass1{};

    cout << "\t\tPlease enter new password: ";
    getline(cin, pass1);
    m_password = pass1;
    cout << "\t\tYour new password is: " << m_password;
    cout << "\n\n";
    system("pause");
}

///////////////////////////////////////////////////////////
// Function is called by the overloaded output operator <<
///////////////////////////////////////////////////////////
void User::print(ostream& out) const
{
    out << m_is_admin << "," << m_login << "," << m_password << "," << m_firstName << "," << m_lastName << "\n";
}
