#include "MovieRating.h"
#include <iostream>
#include <iomanip>

///////////////////////////////////////////////////////////
// Calculate and return movie rating
///////////////////////////////////////////////////////////
float MovieRating::getRating()
{
    if (m_counter)
        return static_cast<float> (m_ratingSum) / static_cast<float> (m_counter);
    else
        return 0.0;
}

///////////////////////////////////////////////////////////
// Print movie rating with comments
///////////////////////////////////////////////////////////
void MovieRating::printRating()
{
    if (m_counter)
        cout << "\t\tUsers Rating: " << setprecision(2) << getRating() << endl;
    else
        cout << "\t\tThe movie has no ratings\n";

    if(m_comments.empty())
        cout <<"\n\t\tThe movie has no comments\n";
    else
    {
        int counter = 1;
        cout << endl << "\t\tComments:\n\n";
        for (auto com : m_comments)
        {
            cout << left << "\t\t" << left << counter << ". " << left << setw(90) << com << endl << endl;
            counter++;
        }
    }
    cout << internal;
}

///////////////////////////////////////////////////////////
// Add new comment
///////////////////////////////////////////////////////////
void MovieRating::addComment(string text)
{
    m_comments.push_back(text);
}

///////////////////////////////////////////////////////////
// Add new rating
///////////////////////////////////////////////////////////
void MovieRating::addRating(int rating)
{
    m_ratingSum += rating;
    m_counter++;
}

///////////////////////////////////////////////////////////
// Overloaded output operator <<
///////////////////////////////////////////////////////////
ostream& operator<<(ostream& out, const MovieRating& rhs)
{
    out << ";" << rhs.m_ratingSum << ";" << rhs.m_counter;
    for (auto com : rhs.m_comments)
        out << ";" << com;
    out << ";";
    return out;
}

///////////////////////////////////////////////////////////
// Overloaded output operator >>
///////////////////////////////////////////////////////////

istream& operator>>(istream& in, MovieRating& rhs)
{
    return in;
}
