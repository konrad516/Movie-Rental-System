#pragma once

#include <string>
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////
// Abstract class Account
// subclass: Admin, User
///////////////////////////////////////////////////////////
class Account
{
private:
	int m_ID;
	string m_login;
	string m_password;
	string m_firstName;
	string m_lastName;
	bool m_is_admin;
public:

	virtual int getID() = 0;
	virtual string getFirstName() = 0;
	virtual string getLastName() = 0;
	virtual string getLogin() = 0;
	virtual string getPassword() = 0;
	virtual bool getIsAdmin() = 0;

	virtual void setID(int id) = 0;
	virtual void setLogin(string log) = 0;
	virtual void setPassword(string pass) = 0;
	virtual void setFirstName(string name) = 0;
	virtual void setLastName(string name) = 0;
	virtual void setIsAdmin(bool is_admin) = 0;

	virtual string printPanel() = 0;
	virtual void changePassword() = 0;

	virtual void print(ostream& out) const = 0;
};

ostream& operator<< (ostream& out, const Account& acc);

