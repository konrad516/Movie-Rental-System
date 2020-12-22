#include "RentalStore.h"
#include <iostream>
#include <iomanip>

///////////////////////////////////////////////////////////
// Search account with given login and password
///////////////////////////////////////////////////////////
//
// INPUT:
//			login and password to account
// OUTPUT:
//          pointer to Account
//			nullptr if account not found or do not exist
//
Account* RentalStore::loginAccount(string log, string pass)
{
    for (auto acc : accounts)
    {
        if (acc->getLogin() == log && acc->getPassword() == pass)
            return acc;
    }
    return nullptr;
}

///////////////////////////////////////////////////////////
// Create new account, push it to vector<Account*> accounts
///////////////////////////////////////////////////////////
//
// INPUT:
//			login, password, first name, last name, is_admin
//          defalut value of is_admin is "0"
// OUTPUT:
//          none
//
void RentalStore::createAccount(string log, string pass, string fname, string lname, bool is_admin)
{
    Account* acc = new User();

    acc->setID(accounts.size() + 1);
    acc->setIsAdmin(is_admin);
    acc->setLogin(log);
    acc->setPassword(pass);
    acc->setFirstName(fname);
    acc->setLastName(lname);

    accounts.push_back(acc);
}

///////////////////////////////////////////////////////////
// Create new MOVIE, push it to vector<Movie*> movies 
///////////////////////////////////////////////////////////
//
// INPUT:
//			login, password, first name, last name, is_admin
//          defalut value of is_admin is "0"
// OUTPUT:
//          none
//
void RentalStore::createMovie(string title, string director, string category)
{
    Movie* mov = new Movie(movies.back()->getMovieID() + 1, title, director, category);
    movies.push_back(mov);
}

///////////////////////////////////////////////////////////
// Print movies
// if acc=nullptr print all movies
// if acc!=nullptr print all rented movies of this user
///////////////////////////////////////////////////////////
//
// INPUT:
//			pointer to account
//          defalut value of acc is nullptr
// OUTPUT:
//          none
//
void RentalStore::showMovies(Account* acc)
{
    system("cls");
    cout << setw(4) << "ID" << setw(30) << "Title" << setw(25) << "Director" << setw(15) << "Category" << setw(12) << "Avaliable" << setw(20) << "Return date" << endl << endl;
    if (acc)
    {
        int counter = 0;
        string login = acc->getLogin();
        for (auto mov : movies)
            if (mov->getRentedLogin() == login)
            {
                mov->printMovie();
                counter++;
            }
        if (counter == 0)
            cout << "\n\t\tYou don't have any rented movies" << endl;
    }
    else
    {
        for (auto mov : movies)
            mov->printMovie();
    }
    cout << endl;

}

void RentalStore::showMovieDetails(int movieId)
{
    cout << endl;
    if (movieId > movies.size() || movieId<1)
        cout << "\n\t\tMovie doesn't exist\n";
    else 
    {
        movies[movieId - 1]->printMovieRating();
    }

    cout << endl;
}

///////////////////////////////////////////////////////////
// Print account data
// if acc_id=0 print all accounts data
// if acc_id!=0 print only one account data
///////////////////////////////////////////////////////////
//
// INPUT:
//			acc_id which is account id
//          defalut value of acc_id is 0
// OUTPUT:
//          if account found return pointer to account
//          if input parametr acc_id=0 return nullptr
//          else return nullptr
//
Account* RentalStore::showAccounts(int acc_id)
{
    int counter = 0;
    cout << endl
        << setw(5) << "ID" << setw(10) << "is admin" << setw(15) << "login" << setw(15) << "password" << setw(15) << "fname" << setw(15) << "lname" << endl << endl;
    for (auto acc : accounts)
    {
        if (acc_id)
        {

            if (acc_id == acc->getID())
            {
                counter++;
                cout << setw(5) << acc->getID() << setw(10) << acc->getIsAdmin() << setw(15) << acc->getLogin() << setw(15) << acc->getPassword() << setw(15) << acc->getFirstName() << setw(15) << acc->getLastName() << endl;
                return acc;
            }
        }
        else
            cout << setw(5) << acc->getID() << setw(10) << acc->getIsAdmin() << setw(15) << acc->getLogin() << setw(15) << acc->getPassword() << setw(15) << acc->getFirstName() << setw(15) << acc->getLastName() << endl;
    }
    if (counter == 0 && acc_id)
    {
        cout << "Account not found" << endl;
        return nullptr;
    }
    cout << endl;
    return nullptr;
}

///////////////////////////////////////////////////////////
// Set new data to account
///////////////////////////////////////////////////////////
//
// INPUT:
//			Account pointer, login, password, first name, last name
// OUTPUT:
//          none
//
void RentalStore::modifyAccount(Account* acc, string login, string password, string fname, string lname)
{
    acc->setLogin(login);
    acc->setPassword(password);
    acc->setFirstName(fname);
    acc->setLastName(lname);
}

///////////////////////////////////////////////////////////
// Recive Movie funtion, set rentedID and returnDate to "0" which means movie is not longer rented
///////////////////////////////////////////////////////////
//
// INPUT:
//			movie id
// OUTPUT:
//          none
//
void RentalStore::reciveMovie(int movie_id)
{
    if (movie_id > movies.size())
        cout << "\n\t\tMovie doesn't exist\n";

    else if (movies[movie_id - 1]->getRentedLogin() == "0")
        cout << "\n\t\tMovie is not rented\n";

    else
    {
        movies[movie_id - 1]->setRentedID("0");
        movies[movie_id - 1]->setReturnDate("0");
        cout << "\n\t\tDone\n\t\tMovie: " << movies[movie_id - 1]->getTitle() << " is no longer rented.\n";
    }
}

///////////////////////////////////////////////////////////
// Rent Movie funtion, set rentedID to user login, and returnDate
///////////////////////////////////////////////////////////
//
// INPUT:
//			login of user, movie id, return date
// OUTPUT:
//          none
//
void RentalStore::rentMovie(string user, int movie_id, string date)
{
    if (movie_id > movies.size() || movie_id < 1)
        cout << "\n\t\tMovie doesn't exist\n";

    else if (movies[movie_id - 1]->getRentedLogin() != "0")
        cout << "\n\t\tMovie is rented\n";

    else
    {
        movies[movie_id - 1]->setRentedID(user);
        movies[movie_id - 1]->setReturnDate(date);
        cout << "\n\t\tDone\n\t\tMovie detail: \n";
        movies[movie_id - 1]->printMovie();
    }
}

void RentalStore::deleteMovie(int movie_id)
{
    if (movie_id > movies.size() || movie_id < 1)
        cout << "\n\t\tMovie doesn't exist\n";

    else
    {
        delete movies[movie_id - 1];
        movies.erase(movies.begin() + movie_id - 1, movies.begin() + movie_id);
        cout << "\n\t\tMovie has been deleted successfully\n";
    }
}

void RentalStore::deleteAccount(int acc_id)
{
    if (acc_id > accounts.size() || acc_id < 1)
        cout << "\n\t\tAccount do not exist\n";

    else
    {
        delete accounts[acc_id - 1];
        accounts.erase(accounts.begin() + acc_id - 1, accounts.begin() + acc_id);
        cout << "\n\t\tAccount has been deleted successfully\n";
    }
}

