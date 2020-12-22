#include "MovieRating.h"

float MovieRating::getRating()
{
    if (m_counter)
        return m_ratingSum / m_counter;
    else
        return 0.0;
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
