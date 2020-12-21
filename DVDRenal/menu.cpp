#include "menu.h"
#include "DVDRental.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include "RentalStore.h"
#include "Account.h"

RentalStore store;

void print_title(string tittle)
{
	string temp(MENU_WIDTH, '-');
	cout << temp << endl
		<< setw((MENU_WIDTH + tittle.size()) / 2) << tittle << endl
		<< temp << endl;
}

void show_menu()
{
	system("cls");
	string title = "DVD RENTAL";
	string choice{};

	print_title(title);

	cout << "\t\t1. Login" << endl << "\t\t2. Create new account" << endl << "\t\t3. Exit" << endl << endl;

	cout << "\tPlease enter your choice: ";
	getline(cin, choice);

	if (choice.length() > 1)
		choice = "x";

	switch (choice[0])
	{
	case '1':
		account_login();
		show_menu();
		break;
	case '2':
		account_create();
		cout << "\n\t\tNew account has been successfully registered\n\n";
		system("pause");
		show_menu();
		break;
	case '3':
		break;
	default:
		cout << "Please enter correct input" << endl;
		show_menu();
		break;
	}
}

void account_login()
{
	system("cls");

	string title = "DVD RENTAL";
	string choice{};

	string log{};
	string pass{};

	print_title(title);

	cout << "\t\tPlease enter your login: ";
	getline(cin, log);
	cout << "\t\tPlease enter your password: ";
	getline(cin, pass);

	Account* acc = store.loginAccount(log, pass);
	if (acc == nullptr)
	{
		cout << "\t\tPlease create new account or enter corect login or password\n\n";
		system("pause");
	}
	else
	{
		if (acc->getIsAdmin() == true)
			adminMenu(acc);
		else
			userMenu(acc);
	}
}

void account_create(bool isadmin)
{
	system("cls");

	string title = "DVD RENTAL";

	string log, pass, fname, lname;

	print_title(title);

	cout << "\t\tPlease enter your login: ";
	getline(cin, log);
	cout << "\t\tPlease enter your password: ";
	getline(cin, pass);
	cout << "\t\tPlease enter your first name: ";
	getline(cin, fname);
	cout << "\t\tPlease enter your last name: ";
	getline(cin, lname);
	store.createAccount(log, pass, fname, lname, isadmin);
}

void userMenu(Account* acc)
{
	string choice = acc->printPanel();
	switch (choice[0])
	{
	case '1':
		store.showMovies();
		system("pause");
		userMenu(acc);
		break;

	case '2':
		store.showMovies(acc);
		system("pause");
		userMenu(acc);
		break;
	case '3':
		acc->changePassword();
		userMenu(acc);
		break;
	case '4':
		break;
	default:
		cout << "Please enter correct input" << endl;
		system("pause");
		userMenu(acc);
		break;
	}
}

void adminMenu(Account* acc)
{
	string choice = acc->printPanel();
	switch (choice[0])
	{
	case '1':
		store.showMovies();
		system("pause");
		adminMenu(acc);
		break;

	case '2':
		createMovieMenu();
		system("pause");
		adminMenu(acc);
		break;
	case '3':
		store.showAccounts();
		system("pause");
		adminMenu(acc);
		break;
	case '4':
		modifyUserMenu();
		cout << "\n\t\tNew account has been successfully registered\n\n";
		system("pause");
		adminMenu(acc);
		break;
	case '5':
		account_create(true);
		cout << "\n\t\tNew account has been successfully registered\n\n";
		system("pause");
		adminMenu(acc);
		break;
	case '6':
		account_create(false);
		system("pause");
		adminMenu(acc);
		break;
	case '7':
		reciveMenu();
		system("pause");
		adminMenu(acc);
		break;
	case '8':
		rentMenu();
		system("pause");
		adminMenu(acc);
		break;
	case '9':
		break;
	default:
		cout << "Please enter correct input" << endl;
		system("pause");
		adminMenu(acc);
		break;
	}
}

void createMovieMenu()
{
	system("cls");

	string title = "DVD RENTAL - Create Movie";

	string title_temp, director, category;

	print_title(title);

	cout << "\t\tPlease enter title: ";
	getline(cin, title_temp);
	cout << "\t\tPlease enter director: ";
	getline(cin, director);
	cout << "\t\tPlease enter category: ";
	getline(cin, category);
	store.createMovie(title_temp, director, category);
	cout << endl;
}

void modifyUserMenu()
{
	system("cls");

	string title = "DVD RENTAL - Modify User";

	string acc_id, login, password, fname, lname;

	print_title(title);

	cout << "\t\tPlease enter account ID: ";
	getline(cin, acc_id);

	Account* acc = store.showAccounts(stoi(acc_id));
	if (!acc)
	{
		system("pause");
		return;
	}
	cout << "\n\t\tPlease enter new login: ";
	getline(cin, login);
	cout << "\t\tPlease enter new password: ";
	getline(cin, password);
	cout << "\t\tPlease enter new first name: ";
	getline(cin, fname);
	cout << "\t\tPlease enter new last name: ";
	getline(cin, lname);
	store.modifyAccount(acc, login, password, fname, lname);
	cout << "\n\n\t\tAccount: ";
	store.showAccounts(stoi(acc_id));
}

void reciveMenu()
{
	system("cls");

	string title = "DVD RENTAL - Recive Movie";
	string movie_id;

	print_title(title);

	cout << "\t\tPlease enter movie ID: ";
	getline(cin, movie_id);

	store.reciveMovie(stoi(movie_id));
}

void rentMenu()
{
	system("cls");

	string title = "DVD RENTAL - Rent Movie";
	string user;
	string movieID, date;

	print_title(title);

	cout << "\t\tPlease enter user login: ";
	getline(cin, user);

	cout << "\t\tPlease enter movie ID: ";
	getline(cin, movieID);

	cout << "\t\tPlease enter return date (format: DD.MM.YY): ";
	getline(cin, date);

	store.rentMovie(user, stoi(movieID), date);
	cout << endl;
}