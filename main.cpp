
#include <iostream>
#include <fstream> 
#include <string> 
#include <cstdlib> 
#include <limits>
#include <ctime>
#include <time.h>
#include <string> 
#include <conio.h>
#include <windows.h>


#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;

#define TEXTFILE "intro.txt"
#define PRINT_ALL_PLAYERS 0
#define TEMP_DECK 1
#define TURN 2
#define TEST -1


void confirm(int x)
{
	cout << "Confirm Player " <<x<<" by entering "<<x<<" : ";
	int temp = 0;
	while (temp != x)
	{
		cin >> temp;
	}
}

COLOR FromString(const string& str)
{
	if (str == "red")
		return red;
	else if (str == "green")
		return green;
	else if (str == "blue")
		return blue;
	else if (str == "yellow")
		return yellow;
	else
		return wild;
}

void gotoxy(short x, short y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
}

void Start()
{
	int x = 13;
	int y = 0;

	system("color A");
	Sleep(3000);

	gotoxy(x - 10, y); cout << "R";
	Sleep(1000);
	gotoxy(x - 9, y); cout << "a";
	Sleep(800);
	gotoxy(x - 8, y); cout << "b";
	Sleep(750);
	gotoxy(x - 7, y); cout << "B";
	Sleep(600);
	gotoxy(x - 6, y); cout << "i";
	Sleep(550);
	gotoxy(x - 5, y); cout << "T";
	Sleep(500);
	gotoxy(x - 4, y); cout << "z";
	Sleep(2000);
	system("cls");

	system("color D");
	gotoxy(x, y); cout << "Gamers";
	Sleep(1500);
	system("cls");
	system("color E");
	gotoxy(x + 8, y); cout << "Presenting";
	Sleep(1500);
	system("cls");

	gotoxy(x - 10, y); cout << "R";
	gotoxy(x - 9, y); cout << "a";
	gotoxy(x - 8, y); cout << "b";
	gotoxy(x - 7, y); cout << "B";
	gotoxy(x - 6, y); cout << "i";
	gotoxy(x - 5, y); cout << "T";
	gotoxy(x - 4, y); cout << "z";
	Sleep(100);


	system("color D");
	gotoxy(x, y); cout << "Gamers";
	Sleep(100);

	system("color E");
	gotoxy(x + 8, y); cout << "Presenting";
	Sleep(1000);

	system("color C");

	gotoxy(x + 6, y + 1);    cout << " ______    ______  ";
	gotoxy(x + 6, y + 2);    cout << " |    |    |    | ";
	gotoxy(x + 6, y + 3);    cout << " |    |    |    |        ";
	gotoxy(x + 6, y + 4);    cout << " |    |    |    |        ";
	gotoxy(x + 6, y + 5);    cout << " |    |____|    | ";
	gotoxy(x + 6, y + 6);    cout << " |______________|";
	Sleep(2000);
	system("color A");
	gotoxy(x + 22, y + 7); cout << "  ___       ___  ";
	gotoxy(x + 22, y + 8); cout << "  | |\\      | |  ";
	gotoxy(x + 22, y + 9); cout << "  | |  \\    | |  ";
	gotoxy(x + 22, y + 10); cout << "  | |    \\  | |  ";
	gotoxy(x + 22, y + 11); cout << "  |_|      \\|_|  ";
	Sleep(2000);
	system("color B");
	gotoxy(x + 39, y + 12); cout << "____________ ";
	gotoxy(x + 39, y + 13); cout << "|    ___   | ";
	gotoxy(x + 39, y + 14); cout << "|    | |   | ";
	gotoxy(x + 39, y + 15); cout << "|    |_|   | ";
	gotoxy(x + 39, y + 16); cout << "|          | ";
	gotoxy(x + 39, y + 17); cout << "|__________|   2 0 2 0";
	gotoxy(x + 60, y + 22); cout << "";
	Sleep(2000);


	system("pause");
	system("cls");

	system("color 7");

}

void congradulations()
{
	system("cls");
	cout << "\n\n\n" << endl;
	cout << "   xxxxxxxxx  xxxxxxxxx  xx      xx  xxxxxxxxx   xxxxxxxxxx        xxx        xxxxxxxx   xx    xx  xx              xxx      xxxxxxxx xx  xxxxxxxx  xx      xx  xxxxxxx   " << endl;
	cout << "   xxxxxxxxx  xx     xx  xxx     xx  x           xx      xx       xx xx       xx     xx  xx    xx  xx             xx xx        xx    xx  xx    xx  xxx     xx  xx        " << endl;
	cout << "   xx         xx     xx  xx x    xx  x           xx      xx      xx   xx      xx     xx  xx    xx  xx            xx   xx       xx    xx  xx    xx  xx x    xx  xx        " << endl;
	cout << "   xx         xx     xx  xx  x   xx  xx   xxxxx  xxxxxxxxxx     xxxxxxxxx     x      xx  xx    xx  xx           xxxxxxxxx      xx    xx  xx    xx  xx  x   xx  xxxxxxxx  " << endl;
	cout << "   xx         xx     xx  xx   x  xx  xx      xx  xx  xx        xx       xx    xx     xx  xx    xx  xx          xx       xx     xx    xx  xx    xx  xx   x  xx        xx  " << endl;
	cout << "   xxxxxxxxx  xx     xx  xx    x xx  xx      xx  xx    xx     xx         xx   xx     xx  xxxxxxxx  xxxxxxxx   xx         xx    xx    xx  xx    xx  xx    x xx        xx  " << endl;
	cout << "   xxxxxxxxx  xxxxxxxxx  xx     xxx  xxxxxxxxxx  xx      xx  xx           xx  xxxxxxxx   xxxxxxxx  xxxxxxxx  xx           xx   xx    xx  xxxxxxxx  xx     xxx  xxxxxxxx  " << endl;
}

void playerguide(string filename)
{
	//please make sure the intro.txt text file exist with your files
	system("color 3");

	string line;
	fstream myfile;
	myfile.open(filename.c_str());

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << endl;
		}
		myfile.close();
	}
	else
	{
		cout << "error unable to open file " << endl;
	}

}

void mainmenu()
{
	char choose;
	cout << "Main Menu" << endl << endl;
	cout << "a. Press A to view the player guide " << endl;
	cout << "b. Press B to play the game " << endl;
	cout << "c. Press E to exit ";
	cout << endl << endl;

	cin >> choose;
	system("cls");
	if ((choose == 'A') || (choose == 'a'))
	{
		while ((choose == 'A') || (choose == 'a'))
		{
			playerguide(TEXTFILE);
			cout << endl;
			system("pause");
			system("cls");
			cout << "Enter A to read the instructions again , press any key to play the game or press E to exit  " << endl;
			cin >> choose;
		}
		system("cls");
		if ((choose == 'E') || (choose == 'e'))
		{
			exit(0);
		}
	}

	else if ((choose == 'B') || (choose == 'b'))
	{

	}
	else if ((choose == 'E') || (choose == 'e'))
	{
		exit(0);
	}
	else
	{
		cout << "The input is wrong :(";
		exit(0);
	}

}

int main()
{
	srand(time(NULL));
	Start();
	mainmenu();
	//Sleep(1000);
	system("cls");
	int numPlayers;
	int flag = 0;

	while (flag == 0)
	{
		cout << "Please enter the number of players: ";
		cin >> numPlayers;
		if (numPlayers >= 2 && numPlayers <= 10)
		{
			flag = 1;
			break;
		}
		else
		{
			cout << "Number of players should be 2-10\n" << endl;
		}
	}
	Deck mainDeck;
	Player* playerHand;
	mainDeck.setDeck();
	mainDeck.quickShuffle();
	playerHand = new Player[numPlayers];
	for (int i = 0; i < numPlayers; i++)          //get cards from main deck
	{
		for (int k = 0; k < 7; k++)
		{
			Card tempCard;
			tempCard = mainDeck.draw();
			playerHand[i].handAdd(tempCard);        //add cards to players hands
		}
	}
	Deck tempDeck;
	Card playedCard;                       //card line 19
	Card tempCard;
	int card_flag = 0;
	while (card_flag == 0)
	{
		tempCard = mainDeck.draw();
		if (tempCard.color != wild)
		{
			card_flag = 1;
			playedCard = tempCard;
		}
		else
		{
			tempDeck.addCard(tempCard);
		}
	}


#if TEST == PRINT_ALL_PLAYERS
	for (int i = 0; i < amount_players; i++)
	{
		cout << "player: " << i << endl;
		play_array[i].print();
	}
#endif
	srand(unsigned int(time(NULL)));
	int turn = rand() % numPlayers;
	cout << "\nPlayer " << turn << " is playing" << endl;
	confirm(turn);

	bool force_draw_bool = false;
	int turn_flag = 1;
	int win = 0;
	while (win == 0)
	{
		system("cls");


#if TEST == TEMP_DECK
		temp_deck.print_deck();
#endif 

		Player* curr_player = &playerHand[turn % numPlayers];

		cout << "\nPlayer " << turn % numPlayers << " is playing" << endl;

		if (force_draw_bool)
		{
			if (playedCard.number == 10)
			{
				cout << "Forced Draw-2" << endl;
				Card draw_2;
				for (int i = 0; i < 2; i++)                //if draw2, draw 2 cards from draw file and add to hand
				{
					draw_2 = mainDeck.draw();
					curr_player->handAdd(draw_2);
				}
			}
			if (playedCard.number == 14)
			{
				cout << "Forced Draw-4" << endl;
				Card draw_4;
				for (int i = 0; i < 4; i++)                //if draw4, draw 4 cards from draw file and add to hand
				{
					draw_4 = mainDeck.draw();
					curr_player->handAdd(draw_4);
				}

			}
			force_draw_bool = false;
		}
		cout << "\nCards remaining for each player: " << endl;                 //display no of remaining card of each player
		for (int i = 0; i < numPlayers; i++)
		{
			cout << "Player " << i << ": " << playerHand[i].getSize() << "   ";
		}
		cout << endl;
		cout << "\nPlayed Card: " << playedCard << endl;
		cout << "\nPlayer " << turn % numPlayers << " hand" << endl;

		curr_player->print();
		int check_flag = 0;
		int index;
		int size = curr_player->getSize();
		while (check_flag == 0)
		{
			cout << "\nTo draw a card from draw file, enter '-1' " << endl;
			cout << "To play from your hand, enter the index of the card " << endl;
			cout << "Choice : ";
			cin >> index;
			if (index == -1)               //if player has no matches in hand
			{
				Card draw_temp;
				draw_temp = mainDeck.draw();              //draw from draw file
				cout << "DRAWN CARD: " << draw_temp << endl;
				if (draw_temp == playedCard && draw_temp.color != wild)        //if the drawn card is suitable to play
				{

					int play_draw_flag = 0;
					while (play_draw_flag == 0)
					{

						string drawnPlay;
						cout << "Do you want to play the drawn card [y/n] : ";
						cin >> drawnPlay;
						if (drawnPlay == "y"|| drawnPlay == "Y")
						{
							playedCard = draw_temp;
							tempDeck.addCard(draw_temp);
							if (playedCard.number >= 10 && playedCard.number <= 14)
							{
								force_draw_bool = true;
							}
							play_draw_flag = 1;
						}
						if (drawnPlay == "n"|| drawnPlay == "N")
						{
							curr_player->handAdd(draw_temp);              //if player dont play with drawn card, add it to hand
							play_draw_flag = 1;
						}
					}

				}
				else                                //if the drawn card is not suitable to play, add it to hand
				{
					curr_player->handAdd(draw_temp);
				}
				check_flag = 1;

			}
			if (index >= 0 && index < size)
			{
				Card temp = curr_player->peek(index);
				if (temp == playedCard)
				{
					curr_player->handRemove(index);
					tempDeck.addCard(temp);
					playedCard = temp;
					if (playedCard.color == wild)
					{
						int check_color = 0;
						COLOR temp_color;
						string str_color;
						while (check_color == 0)
						{
							cout << "Please choose a color (red , green, blue, yellow) :";
							cin >> str_color;
							temp_color = FromString(str_color);
							if (temp_color != wild)
							{
								playedCard.color = temp_color;
								check_color = 1;
							}
							else
							{ cout << "Color is not valid" << endl;
							}

						}
					}
					if (playedCard.number >= 10 && playedCard.number <= 14)
					{
						force_draw_bool = true;
					}
					check_flag = 1;
				}
				else
				{ cout << "Error " << endl;
				}
			}
			else
			{ cout << "Index is not valid " << endl;
			}
		}

		if (curr_player->getSize() == 0)         //if player has no cards
		{
			win = 1;
			cout << "\nPlayer " << turn % numPlayers << " has won the game." << endl;
			congradulations();
		}


		if (playedCard.number == 11 && force_draw_bool == true)
		{
			if (turn_flag == 1)
				turn = turn + 2;
			else
				turn = turn - 2;
		}
		else if (playedCard.number == 12 && force_draw_bool == true)
		{
			if (numPlayers == 2)
			{ turn = turn + 2;
			}
			else
			{
				if (turn_flag == 1)
				{
					turn_flag = -1;
					turn--;
				}
				else
				{
					turn_flag = 1;
					turn++;
				}

			}
		}
		else
		{
			if (turn_flag == 1)
				turn++;
			else
				turn--;
		}


		system("cls");
		cout << "\nCards remaining for each player: " << endl;
		for (int i = 0; i < numPlayers; i++)
		{
			cout << "Player " << i << ": " << playerHand[i].getSize() << "   ";
		}
		cout << endl;
		cout << "\nPlayed Card: " << playedCard << endl;
		confirm(turn % numPlayers);

	}

	return 0;
}