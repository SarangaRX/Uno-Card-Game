#include "card.h"
#include "player.h"
#include <iostream>
using namespace std;

Player::Player()             //initialize first card of player hand
{
	head = NULL;
	size = 0;
}
Player::Player(const Player& card1)         
{
	copy(card1);
}
const Player& Player::operator= (const Player& card1)
{
	if (this != &card1)
	{
		remove();
		copy(card1);         
	}

	return *this;
}
Player::~Player()
{
	remove();
}
void Player::handAdd(Card tempCard)              //add card to player hand
{
	card_elem* tempPtr;
	tempPtr = new card_elem();
	tempPtr->data = tempCard;
	tempPtr->next = head;
	head = tempPtr;
	size++;
}
Card Player::handRemove(int pos)
{
	if (pos < 0 || pos >= size)
	{
		return Card();                  //constructor without parameters
	}
	card_elem* prevPtr = head;
	card_elem* target = prevPtr->next;
	Card tempCard;
	int tempPos = pos;

	if (pos == 0)
	{
		tempCard = head->data;
		head = head->next;
		delete prevPtr;
		size--;
		return tempCard;
	}
	while (tempPos > 1)
	{
		prevPtr = prevPtr->next;
		target = prevPtr->next;
		tempPos--;

	}
	prevPtr->next = target->next;
	tempCard = target->data;
	delete target;
	size--;
	return tempCard;
}
void Player::print() const                       //display cards in the hand
{
	int tempSize = size;

	int i = 0;
	card_elem* tempPtr = head;
	while (tempSize > 0)
	{
		cout << i << ":  " << tempPtr->data << endl;
		tempPtr = tempPtr->next;
		i++;
		tempSize--;
	}
}
void Player::copy(const Player& card1)
{
	size = card1.size;
	if (size > 0)
	{
		head = new card_elem();
		head->data = card1.head->data;
	}
	else
	{
		head = NULL;
		return;
	}
	card_elem* otherPtr = card1.head->next;
	card_elem* tempPtr;
	card_elem* prevPtr = head;
	for (int i = 1; i < size; i++)
	{
		tempPtr = new card_elem();
		prevPtr->next = tempPtr;
		tempPtr->data = otherPtr->data;
		prevPtr = tempPtr;
		tempPtr = NULL;
		otherPtr = otherPtr->next;
	}

}
void Player::remove()
{
	card_elem* tempPtr = head;
	card_elem* nextPtr;
	while (size > 0)
	{
		nextPtr = tempPtr->next;
		delete tempPtr;
		tempPtr = nextPtr;
		size--;
	}
	head = NULL;
}
int Player::getSize() const
{
	return size;
}
Card Player::peek(int pos) const
{
	int tempPos = pos;
	card_elem* temp_elem = head;
	while (tempPos > 0)
	{
		temp_elem = temp_elem->next;
		tempPos--;
	}

	return temp_elem->data;

}