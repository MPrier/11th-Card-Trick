//-------------------------------------IPO---------------------------------------------------------
//Programmer's Name: Matthew Prier
//Program:  Lab 1: 11th Card Trick
//Program Flow (IPO): 
// Create a deck of 52 cards and output it to the screen
// Shuffle the deck
// Print the shuffled deck
// Take the top 21 cards from the deck array and print it
// Ask Participant to select a card and remember their card
// Deal the 21 card deck into 3 piles, stored in a 2 dimensional array
// Print the 3 piles 
// Ask the participant which pile contains their card
// Get a 1, 2, or 3 from the keyboard or print an error message
// If they input a 1 or 3, swap that pile with pile 2
// If input 2, no change
// Repeat these 2 more times
// After the 3rd time, output the 11th card in the deck array
// This will be their card
//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

enum suits { heart = 3, diamond, club, spade };

const int DECK_SIZE = 52;
const int CARD_TRICK_SIZE = 21;

struct cardType
{
	int rank;
	int suit;
};

void CreateDeck(cardType deck[]);

void PrintTheDeck(cardType deck[], const int DECK_SIZE);

void Swap(cardType& first, cardType& second);

void ShuffleTheDeck(cardType deck[]);

void PrintACard(int card, int suit);

void CardTrick(cardType trickDeck[7][3]);

void PrintPiles(cardType trickDeck[7][3], cardType deck[]);

void DealTheCards(cardType trickDeck[7][3], cardType deck[]);

void IsThisYourCard(cardType trickdeck[][3]);

void MainCardTrick(cardType trickDeck[][3], cardType deck[]);

int main(void)
{
	// declaring arrays
	cardType deck[DECK_SIZE];
	cardType trickDeck[7][3];

	/// This will seed the random off the clock tick.  That way you will get a more random number
	srand((unsigned int)time(NULL));

	CreateDeck(deck);

	cout << setw(46) << "52 Card Deck" << endl;

	PrintTheDeck(deck, DECK_SIZE);

	cout << endl << endl;

	cout << setw(47) << "Shuffled Deck" << endl;

	ShuffleTheDeck(deck);

	PrintTheDeck(deck, DECK_SIZE);

	cout << endl << endl;

	cout << setw(46) << "21 Card Deck" << endl;

	PrintTheDeck(deck, CARD_TRICK_SIZE);

	cout << setw(46) << "Pick a card" << endl;

	PrintPiles(trickDeck, deck);

	MainCardTrick(trickDeck, deck);

	return 0;
}
void CreateDeck(cardType deck[])
//-----------------------------------------------------------------------------------------------//
// Name: CreateDeck - Creates the deck of cards using a struct array
//-----------------------------------------------------------------------------------------------//
{
	int index;
	int card = 1;
	int suit = heart;

	for (index = 0; index < DECK_SIZE; index++)
	{
		deck[index].rank = card;
		deck[index].suit = suit;
		card++;
		if (card == 14)
		{
			card = 1;
			suit++;
		}
	}

}

void PrintTheDeck(cardType deck[], const int DECK_SIZE)
//-----------------------------------------------------------------------------------------------//
// Name: PrintTheDeck - Prints the deck of cards to the screen using a for loop and the PrintACard
// function
//-----------------------------------------------------------------------------------------------//
{
	int index;
	int card = 1;
	int suitChange = 1;


	for (index = 0; index < DECK_SIZE; index++)
	{
		PrintACard(deck[index].rank, deck[index].suit);
		suitChange++;
		if (suitChange == 14)
		{
			suitChange = 1;
			cout << endl;
		}

	}

	cout << endl;
}

void Swap(cardType& first, cardType& second)
//-----------------------------------------------------------------------------------------------//
// Name: Swap - Swaps two variables values
//-----------------------------------------------------------------------------------------------//
{
	cardType temp;

	temp = first;
	first = second;
	second = temp;
}

void ShuffleTheDeck(cardType deck[])
//-----------------------------------------------------------------------------------------------//
// Name: ShuffleTheDeck - Shuffles the deck of cards by generating a random number between 0 and
// 52 and using that number to swap the card places in the deck array
//-----------------------------------------------------------------------------------------------//
{
	int randSpot;
	int index;

	for (index = 0; index < DECK_SIZE; index++)
	{
		randSpot = rand() % DECK_SIZE;
	
		swap(deck[index], deck[randSpot]);

	}
}

void CardTrick(cardType trickDeck[7][3])
//-----------------------------------------------------------------------------------------------//
// Name: CardTrick - Ask's which pile contains their card and moves that pile into the middle
// of the piles
//-----------------------------------------------------------------------------------------------//
{
	int index;
	int pile;

	cout << "Which Pile Contains Your Card? 1, 2, or 3: ";
	cin >> pile;

	while (pile != 1 && pile != 2 && pile != 3)
	{
		cout << "Error. Try Again: ";
		cin >> pile;
	}

	if (pile == 1)
	{
		for (index = 0; index < 7; index++)
		{
			swap(trickDeck[index][0], trickDeck[index][1]);
		}
	}
	else if (pile == 2)
	{

	}
	else if (pile == 3)
	{
		for (index = 0; index < 7; index++)
		{
			swap(trickDeck[index][1], trickDeck[index][2]);
		}
	}
	
}

void PrintPiles(cardType trickDeck[7][3], cardType deck[])
//-----------------------------------------------------------------------------------------------//
// Name: PrintPiles - Print the card piles to the screen 
//-----------------------------------------------------------------------------------------------//
{
	int index;
	int rows = 0;
	int columns = 0;

	cout << setw(6) << "#1" << setw(6) << "#2" << setw(6) << "#3" << endl;

	for (index = 0; index < CARD_TRICK_SIZE; index++)
	{

		trickDeck[rows][columns] = deck[index];

		PrintACard(trickDeck[rows][columns].rank, trickDeck[rows][columns].suit);
		
		columns++;

		if (columns == 3)
		{
			rows++;
			cout << endl;

			columns = 0;
		}
	}
}
void PrintACard(int card, int suit)
//-----------------------------------------------------------------------------------------------//
// Name: PrintACard - Prints the card number and suit to the screen
//-----------------------------------------------------------------------------------------------//
{
	char printChar;

	if (card >= 2 && card <= 10)
	{
		cout << setw(5) << card << (char)suit;
	}
	else
	{
		switch (card)
		{
		case 11: printChar = 'J';
			break;

		case 12: printChar = 'Q';
			break;

		case 13: printChar = 'K';
			break;

		default: printChar = 'A';
		}
		
		cout << setw(5) << printChar << (char)suit;
	}

}
void DealTheCards(cardType trickDeck[7][3], cardType deck[])
//-----------------------------------------------------------------------------------------------//
// Name: DealTheCards - Print the card piles to the screen and update the 2 dimensional array
//-----------------------------------------------------------------------------------------------//
{
	int index;
	int rows = 0;
	int columns = 0;
	int piles = 0;

	cout << setw(6) << "#1" << setw(6) << "#2" << setw(6) << "#3" << endl;

	for (index = 0; index < CARD_TRICK_SIZE; index++)
	{
		deck[index] = trickDeck[rows][columns];

		PrintACard(deck[index].rank, deck[index].suit);

		piles++;
		rows++;

		if (piles % 3 == 0)
		{
			cout << endl;
		}

		if (rows == 7)
		{
			columns++;
			rows = 0;
		}
	}

	rows = 0;
	columns = 0;

	for (index = 0; index < CARD_TRICK_SIZE; index++)
	{
		trickDeck[rows][columns] = deck[index];

		columns++;

		if (columns == 3)
		{
			rows++;
			columns = 0;
		}
	}
}

void IsThisYourCard(cardType trickDeck[][3])
//-----------------------------------------------------------------------------------------------//
// Name: IsThisYourCard - Print their card (the 11th card or the 4 card in the 2nd pile
// to the screen
//-----------------------------------------------------------------------------------------------//
{
	cout << endl;

	cout << "Is This Your Card? ";

	PrintACard(trickDeck[3][1].rank, trickDeck[3][1].suit);
}

void MainCardTrick(cardType trickDeck[][3], cardType deck[])
//-----------------------------------------------------------------------------------------------//
// Name: MainCardTrick - Repeats the Dealing and shuffling of the piles and outputs their card.
// Helps clean the main
//-----------------------------------------------------------------------------------------------//
{
	int index;

	for (index = 0; index < 3; index++)
	{
		CardTrick(trickDeck);

		DealTheCards(trickDeck, deck);
	}
	
	IsThisYourCard(trickDeck);
}