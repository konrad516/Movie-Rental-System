#include "ReadFiles.h"
#include <sstream>

///////////////////////////////////////////////////////////
// Load accounts (admins and users) data from file
///////////////////////////////////////////////////////////
//
// INPUT:
//			none
// OUTPUT:
//			vector of abstract class object pointers Accounts
//
vector<Account*> ReadFiles::readAccounts()
{
    ifstream accountsFile(accountsFilePath);

    string id, is_admin, login, pass, fname, lname;

    if (accountsFile.is_open())
    {
        while (!accountsFile.eof())
        {
            getline(accountsFile, id, ',');
            getline(accountsFile, is_admin, ',');
            getline(accountsFile, login, ',');
            getline(accountsFile, pass, ',');
            getline(accountsFile, fname, ',');
            getline(accountsFile, lname, '\n');
            if (id.empty())
                break;
            if (is_admin == "1")
            {
                Account* adm = new Admin();
                adm->setID(stoi(id));
                adm->setIsAdmin(stoi(is_admin));
                adm->setLogin(login);
                adm->setPassword(pass);
                adm->setFirstName(fname);
                adm->setLastName(lname);
                m_accounts.push_back(adm);
            }
            else
            {
                Account* us = new User();
                us->setID(stoi(id));
                us->setIsAdmin(stoi(is_admin));
                us->setLogin(login);
                us->setPassword(pass);
                us->setFirstName(fname);
                us->setLastName(lname);
                m_accounts.push_back(us);
            }
        }
        accountsFile.close();
    }
    return m_accounts;
}

///////////////////////////////////////////////////////////
// Load movies data from file
///////////////////////////////////////////////////////////
//
// INPUT:
//			none
// OUTPUT:
//			vector of class object pointers Movie
//
vector<Movie*> ReadFiles::readMovies()
{
    ifstream moviesFile(moviesFilePath);

    string title, director, category, returnDate, movieID, rentedLogin, temp, ratingSum, ratingCounter, line;
    vector<string> comments;

    if (moviesFile.is_open())
    {

        while (!moviesFile.eof())
        {
            Movie* mov = new Movie;
            comments.clear();
            getline(moviesFile, movieID, ',');
            getline(moviesFile, title, ',');
            getline(moviesFile, director, ',');
            getline(moviesFile, category, ',');
            getline(moviesFile, rentedLogin, ',');
            getline(moviesFile, returnDate, ';');
            getline(moviesFile, ratingSum, ';');
            getline(moviesFile, ratingCounter, ';');
            getline(moviesFile, line, '\n');
            stringstream s(line);
            while (getline(s, temp, ';'))
                comments.push_back(temp);

            if (!movieID.empty())
            {
                MovieRating rating(comments, stoi(ratingSum), stoi(ratingCounter));
                Movie* mov = new Movie(stoi(movieID), title, director, category, rentedLogin, returnDate);
                mov->setRating(rating);
                m_movies.push_back(mov);
            }
        }
        moviesFile.close();
    }
    return m_movies;
}

///////////////////////////////////////////////////////////
// Save accounts data to file
///////////////////////////////////////////////////////////
//
// INPUT:
//			vector of abstract class object pointers Accounts
// OUTPUT:
//			none
//
void ReadFiles::saveAccounts(vector<Account*> accounts)
{
    ofstream AccountsFile(accountsFilePath);
    int id = 0;
    if (AccountsFile.is_open())
    {
        for (auto acc : accounts)
        {
            AccountsFile << ++id << "," << *(acc);
            delete acc;
        }
    }
    AccountsFile.close();
}

///////////////////////////////////////////////////////////
// Save movies data to file
///////////////////////////////////////////////////////////
//
// INPUT:
//			vector of class object pointers Movie
// OUTPUT:
//			none
//
void ReadFiles::saveMovies(vector<Movie*> movies)
{
    ofstream moviesFile(moviesFilePath);
    int id = 0;

    if (moviesFile.is_open())
    {
        for (auto mov : movies)
        {
            moviesFile << ++id << "," << *(mov);
            delete mov;
        }
        moviesFile.close();
    }
}