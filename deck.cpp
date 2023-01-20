#include "deck.h"
#include "card.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Deck::Deck()
{
	ptrDeck = new Card[108];
	size = 0;

}
void Deck::setDeck()
{
	int num = 0,x,y;
	for (x = 1; x <= 4; x++)
	{
		ptrDeck[size].number = num;                            // num 0 cards from 4 colors
		ptrDeck[size].color = static_cast<COLOR>(x);            
		size++;                                                 //size is increasing
	}
	//card rand 1-9,draw two,skip and reverse
	for (num = 1; num < 12; num++)                              //1-9 + 10:draw2 + 11:skip + 12:reverse
	{
		for (x = 0; x < 2; x++)                                //each have 2 cards
		{
			for (y= 1; y < 4; y++)                             //4 colors
			{
				ptrDeck[size].number = num;
				ptrDeck[size].color = static_cast<COLOR>(y);
				size++;
			}
		}

	}
	//wild card and draw four
	for (num = 13; num < 14; num++)
	{
		for ( x = 0; x < 4; x++)
		{
			ptrDeck[size].number = num;
			ptrDeck[size].color = wild;
			size++;

		}

	}

}
Deck::Deck(const Deck& card1)
{
	copy(card1);
}
const Deck& Deck::operator=(const Deck& card1)
{
	if (this != &card1)
	{
		clear();
		copy(card1);
	}
	return *this;
}

Deck::~Deck()
{
	clear();
}
void Deck::shuffle()
{
	Card* tempDeck = new Card[size];
	for (int i = 0; i < size; i++)
	{
		tempDeck[i] = ptrDeck[i];
	}

	int tempSize = size;
	int tempPos;
	int pos;
	for (int i = 0; i < size; i++)
	{
		srand(time(NULL));
		pos = rand() % tempSize;
		ptrDeck[i] = tempDeck[pos];
		tempSize--;
		for (tempPos = 0; tempPos < tempSize; tempPos++)
		{
			tempDeck[tempPos] = tempDeck[tempPos + 1];
		}
	}
	delete[] tempDeck;
}
void Deck::quickShuffle()
{
	int pos;
	int tempSize = size - 1;
	Card tempCard;
	while (tempSize > 0)
	{
		srand(time(NULL));
		pos = rand() % tempSize;
		tempCard = ptrDeck[tempSize];
		ptrDeck[tempSize] = ptrDeck[pos];
		ptrDeck[pos] = tempCard;
		tempSize--;
	}
}

Card Deck::draw()
{
	if (size <= 0)                   //get a card from draw pile
	{
		return Card();
	}
	Card tempCard = ptrDeck[size - 1];
	size--;
	return tempCard;
}

int Deck::addCard(Card tempCard)
{
	if (size < 108)
	{
		ptrDeck[size] = tempCard;
		size++;
		return 0;
	}
	else
		return -1;
}
int Deck::getSize()      //return the number of cards in need. ex:remaining no of cards with each player
{
	return size;
}
void Deck::displayDeck()
{
	for (int i = 0; i < size; i++)
	{
		cout << i << ": " << ptrDeck[i] << endl;
	}
}

void Deck::copy(const Deck& card1)
{
	size = card1.size;
	ptrDeck = new Card[size];
	for (int i = 0; i < size; i++)
	{
		ptrDeck[i] = card1.ptrDeck[i];

	}
}

void Deck::clear()
{
	delete[] ptrDeck;
	ptrDeck = NULL;
	size = 0;
}

