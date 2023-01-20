#include "card.h"

Card::Card() : number(0), color(wild)
{
}
Card::Card(int num, COLOR col) : number(num), color(col)
{
}
bool Card::operator==(Card const& card1) const                                 //operator overloading ==
{
	return number == card1.number || color == card1.color || color == wild || card1.color == wild;
}
bool Card ::operator!=(Card const& card1)const                        //operator overloading =!
{
	return !(*this == card1);
}
std::ostream& operator<<(std::ostream& out, Card const& tempCard)
{
	out << "Number: ";
	if (tempCard.number == 10)
	{ out << "Draw-Two";
	}
	else if (tempCard.number == 11)
	{ out << "Skip";
	}
	else if (tempCard.number == 12)
	{ out << "Reverse";
	}
	else if (tempCard.number == 13)
	{ out << "Wild";
	}
	else if (tempCard.number == 14)
	{ out << "Draw-Four-Wild";
	}
	else
	{ out << (int)tempCard.number;
	}

	out << " Color:";
	if (tempCard.color == wild)
	{ out << "wild";
	}
	else if (tempCard.color == red)
	{ out << "red";
	}
	else if (tempCard.color == green)
	{ out << "green";
	}
	else if (tempCard.color == blue)
	{ out << "blue";
	}
	else if (tempCard.color == yellow)
	{ out << "yellow";
	}
	else
	{ out << "Error";
	}

	return out;

}