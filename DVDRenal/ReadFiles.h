#pragma once
#include <vector>
#include <fstream>
#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "Movie.h"

using namespace std;

//file paths
constexpr auto moviesFilePath = "files/movies.csv";
constexpr auto accountsFilePath = "files/accounts.csv";

class ReadFiles
{
private:
    vector<Account*> m_accounts;
    vector<Movie*> m_movies;

public:
    vector<Account*> readAccounts();
    vector<Movie*> readMovies();
    void saveAccounts(vector<Account*> accounts);
    void saveMovies(vector<Movie*> movies);
};
