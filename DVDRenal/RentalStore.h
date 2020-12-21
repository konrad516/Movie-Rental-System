#pragma once
#include <vector>
#include "Account.h"
#include "Movie.h"
#include "User.h"
#include "Admin.h"

constexpr auto MENU_WIDTH = 120;

using namespace std;

class RentalStore
{
private:
    vector<Account*> accounts;
    vector<Movie*> movies;

public:
    vector<Account*> getAccounts() { return accounts; }
    vector<Movie*> getMovies() { return movies; }
    void setAccounts(vector<Account*> accounts) { this->accounts = accounts; }
    void setMovies(vector<Movie*> movies) { this->movies = movies; }

    Account* loginAccount(string log, string pass);

    void createAccount(string log, string pass, string fname, string lname, bool isadmin = 0);
    void createMovie(string title, string director, string category);

    void showMovies(Account* acc = nullptr);
    Account* showAccounts(int acc_id = 0);

    void modifyAccount(Account* acc, string login, string password, string fname, string lname);

    void reciveMovie(int movie_id);
    void rentMovie(string user, int movie_id, string date);
};
