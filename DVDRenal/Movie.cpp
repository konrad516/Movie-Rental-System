#include "Movie.h"
#include <iomanip>
#include <iostream>

///////////////////////////////////////////////////////////
// Print movie data, if movie is not rented do not print returnDate
///////////////////////////////////////////////////////////
//
// INPUT:
//			none
// OUTPUT:
//			none
//
void Movie::printMovie()
{
    string temp = "NO";
    if (m_rentedLogin == "0")
    {
        temp = "YES";
        cout << setw(4) << m_movieID << setw(30) << m_title << setw(25) << m_director << setw(15) << m_category << setw(12) << temp << setw(20) << "---" << endl;
    }
    else
        cout << setw(4) << m_movieID << setw(30) << m_title << setw(25) << m_director << setw(15) << m_category << setw(12) << temp << setw(20) << m_returnDate << endl;
}

///////////////////////////////////////////////////////////
// Print movie rating
///////////////////////////////////////////////////////////
//
// INPUT:
//			none
// OUTPUT:
//			none
//
void Movie::printMovieRating()
{
    m_rating.printRating();
}

///////////////////////////////////////////////////////////
// Overloaded output operator <<
///////////////////////////////////////////////////////////
ostream& operator<<(ostream& out, const Movie& rhs)
{
    out << rhs.m_title << "," << rhs.m_director << "," << rhs.m_category << "," << rhs.m_rentedLogin << "," << rhs.m_returnDate << rhs.m_rating << endl;
    return out;
}

///////////////////////////////////////////////////////////
// Overloaded input operator >>
///////////////////////////////////////////////////////////
istream& operator>>(istream& in, Movie& rhs)
{
    in >> rhs.m_movieID >> rhs.m_title >> rhs.m_director >> rhs.m_category >> rhs.m_rentedLogin >> rhs.m_returnDate;
    return in;
}
