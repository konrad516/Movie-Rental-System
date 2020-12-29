#pragma once
#include "MovieRating.h"

using namespace std;

class Movie
{
private:
    int m_movieID;
    string m_title;
    string m_director;
    string m_category;
    string m_rentedLogin;
    string m_returnDate;
    MovieRating m_rating;

public:
    Movie() {};

    ///////////////////////////////////////////////////////////
    // Movie constructor, rentedLogin and returnDate defalut value are "0" (movie is not rented)
    ///////////////////////////////////////////////////////////
    Movie(int movieID, string title, string director, string category, string rentedLogin = "0", string returnDate = "0")
        : m_movieID(movieID), m_title(title), m_director(director), m_category(category), m_rentedLogin(rentedLogin), m_returnDate(returnDate) {};
    
    int getMovieID() { return m_movieID; }
    string getTitle() { return m_title; }
    string getDirector() { return m_director; }
    string getCategory() { return m_category; }
    string getRentedLogin() { return m_rentedLogin; }
    string getReturnDate() { return m_returnDate; }
    MovieRating getRating() { return m_rating; }

    void setTitle(string title) { m_title = title; }
    void setDirector(string director) { m_director = director; }
    void setCategory(string category) { m_category = category; }
    void setRentedID(string rentedLogin) { m_rentedLogin = rentedLogin; }
    void setReturnDate(string returnDate) { m_returnDate = returnDate; }
    void setRating(MovieRating rating) { m_rating = rating; }

    friend ostream& operator<<(ostream& out, const Movie& rhs);
    friend istream& operator>>(istream& in, Movie& rhs);

    void printMovie();
    void printMovieRating();
};

ostream& operator<<(ostream& out, const Movie& rhs);
istream& operator>>(istream& in, Movie& rhs);