#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck : public Card
{
public:
	Deck();
	Deck(const Deck& card1);
	const Deck& operator= (const Deck& card1);
	~Deck();
	void shuffle();
	void quickShuffle();
	Card draw();
	void setDeck();
	void displayDeck();
	int addCard(Card tempCard);
	int getSize();

private:
	Card* ptrDeck;
	int size;
	void clear();
	void copy(const Deck& card1);
};

std::ostream& operator<<(std::ostream& out, Deck const& tempDeck);

#endif
