#include "Admin.h"
#include "menu.h"
#include <iostream>

///////////////////////////////////////////////////////////
// Print user choice decision panel
///////////////////////////////////////////////////////////
//
// INPUT:
//			none
// OUTPUT:
//			admin choice
//
string Admin::printPanel()
{
    system("cls");
    string title = "DVD RENTAL - WELCOME ADMIN " + m_firstName + " " + m_lastName;
    string choice{};

    print_title(title);

    cout << "\t\t1. Show all films" << endl
        << "\t\t2. Add film" << endl
        << "\t\t3. Show all accounts" << endl
        << "\t\t4. Modify account" << endl
        << "\t\t5. Create admin" << endl
        << "\t\t6. Create user" << endl
        << "\t\t7. Return movie" << endl
        << "\t\t8. Rent movie" << endl
        << "\t\t9. Back" << endl;

    cout << "\n\n\tPlease enter your choice: ";
    getline(cin, choice);

    if (choice.length() > 1)
        choice = "x";

    return choice;
}

///////////////////////////////////////////////////////////
// Print admin change password panel
///////////////////////////////////////////////////////////
//
// INPUT:
//			none
// OUTPUT:
//			none
//
void Admin::changePassword()
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
void Admin::print(ostream& out) const
{
    out << m_is_admin << "," << m_login << "," << m_password << "," << m_firstName << "," << m_lastName << "\n";
}