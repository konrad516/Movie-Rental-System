#pragma once
#include <string>
#include <vector>

using namespace std;

class MovieRating
{
private:
	vector<string> m_comments{};
	int m_ratingSum{};
	int m_counter{};
public:
	//MovieRating() {};
	MovieRating(vector<string> comments = {}, int ratingSum = 0, int Counter = 0) :
		m_comments(comments), m_ratingSum(ratingSum), m_counter(Counter) {};

	void setComments(vector<string>comments) { m_comments = comments; }
	void setRatingSum(int ratingSum) { m_ratingSum = ratingSum; }
	void setRatingCounter(int counter) { m_counter = counter; }

	vector<string> getComments() { return m_comments; }
	int getRatingSum() { return m_ratingSum; }
	int getRatingCounter() { return m_counter; }

	float getRating();
	void printRating();

	void addComment(string text);
	void addRating(int rating);

	friend ostream& operator<<(ostream& out, const MovieRating& rhs);
	friend istream& operator>>(istream& in, MovieRating& rhs);
};

ostream& operator<<(ostream& out, const MovieRating& rhs);
istream& operator>>(istream& in, MovieRating& rhs);