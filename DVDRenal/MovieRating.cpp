#include "MovieRating.h"
#include <iostream>
#include <iomanip>

float MovieRating::getRating()
{
    if (m_counter)
        return m_ratingSum / m_counter;
    else
        return 0.0;
}

void MovieRating::printRating()
{
    if (m_counter)
        cout << "Users Rating: " << setprecision(2) << getRating() << endl;
    else
        cout << "The movie has no ratings\n";

    if(m_comments.empty())
        cout <<"\nThe movie has no comments\n";
    else
    {
        cout << endl;
        for (auto com : m_comments)
            cout << setw(100) << com << endl;
    }
}

void MovieRating::addComment(string text)
{
    m_comments.push_back(text);
}

void MovieRating::addRating(int rating)
{
    m_ratingSum += rating;
    m_counter++;
}

ostream& operator<<(ostream& out, const MovieRating& rhs)
{
    out << ";" << rhs.m_ratingSum << ";" << rhs.m_counter;
    for (auto com : rhs.m_comments)
        out << ";" << com;
    return out;
}

istream& operator>>(istream& in, MovieRating& rhs)
{
    // TODO: tu wstawiæ instrukcjê return
}
