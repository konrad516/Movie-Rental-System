#pragma once
#include <string>
#include "Account.h"

using namespace std;

void print_title(string tittle);
void show_menu();
void account_login();
void account_create(bool isadmin=0);
void userMenu(Account* acc);
void adminMenu(Account* acc);
void ratingMenu();
void newRateMenu(int movieID);
void newCommentMenu(int movieID);
void createMovieMenu();
void modifyUserMenu();
void reciveMenu();
void rentMenu();
void deleteMovieMenu();
void deleteAccountMenu();