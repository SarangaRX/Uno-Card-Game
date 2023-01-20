#ifndef _CARD_H_
#define _CARD_H_
#include<iostream>

enum COLOR
{
	wild, green, yellow, red, blue
};

class Card
{
public:
	int number;
	COLOR color;

	bool operator == (Card const& card1) const;
	bool operator !=(Card const& card1) const;

	Card();
	Card(int num, COLOR col);

};

std::ostream& operator<<(std::ostream& out, Card const& tempCard);

#endif
