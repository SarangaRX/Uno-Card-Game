#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"

class Player
{
public:
	Player();
	Player(const Player& card1);
	const Player& operator= (const Player& card1);
	~Player();
	void handAdd(Card temp);
	Card handRemove(int pos);
	void print() const;
	int getSize() const;
	Card peek(int pos) const;
private:
	class card_elem
	{
	public:
		card_elem()
		{
			next = NULL;
		}
		Card data;
		card_elem* next;
	};
	card_elem* head;
	int size;
	void copy(const Player& card1);
	void remove();
};
#endif

