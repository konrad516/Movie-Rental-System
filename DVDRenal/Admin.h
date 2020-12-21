#pragma once
#include "Account.h"

class Admin : public Account
{
private:
    int m_ID;
    string m_login;
    string m_password;
    string m_firstName;
    string m_lastName;
    bool m_is_admin;

public:
    int getID() { return m_ID; }
    string getFirstName() { return m_firstName; }
    string getLastName() { return m_lastName; }
    string getLogin() { return m_login; }
    string getPassword() { return m_password; }
    bool getIsAdmin() { return m_is_admin; }

    void setID(int id) { m_ID = id; }
    void setLogin(string login) { m_login = login; }
    void setPassword(string password) { m_password = password; }
    void setFirstName(string firstname) { m_firstName = firstname; }
    void setLastName(string lastname) { m_lastName = lastname; }
    void setIsAdmin(bool is_admin) { m_is_admin = is_admin; }

    string printPanel();
    void changePassword();

    void print(ostream& out) const;
};
