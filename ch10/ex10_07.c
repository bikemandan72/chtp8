/*
10.7 (Card Shuffling and Dealing Modification)
Modify the program of Fig. 10.16 to shuffle the cards using a high-performance shuffle
(as shown in Fig. 10.3). Print the resulting deck in a two-column format that uses 
the face and suit names. Precede each card with its color.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define SUITS 4
#define FACES 13
#define COLORS 2

// bitCard structure definition with bit fields
struct bitCard {
	unsigned int face : 4; // 4 bits; 0-15        
	unsigned int suit : 2; // 2 bits; 0-3         
	unsigned int color : 1; // 1 bit; 0-1          
};

typedef struct bitCard Card; // new type name for struct bitCard   

void fillDeck(Card * const wDeck); // prototype
void deal(const Card * const wDeck); // prototype
void shuffle(Card * const wDeck);

int main(void)
{
	Card deck[CARDS]; // create array of Cards
	srand(time(NULL)); // randomize
	fillDeck(deck);
	shuffle(deck);
	//puts("Card values 0-12 correspond to Ace through King");
	//puts("Suit values 0-3 correspond Hearts, Diamonds, Clubs and Spades");
	//puts("Color values 0-1 correspond to red and black\n");
	deal(deck);
}

// initialize Cards
void fillDeck(Card * const wDeck)
{
	// loop through wDeck
	for (size_t i = 0; i < CARDS; ++i) {
		wDeck[i].face = i % (CARDS / 4);
		wDeck[i].suit = i / (CARDS / 4);
		wDeck[i].color = i / (CARDS / 2);
	}
}

// shuffle cards
void shuffle(Card * const wDeck)
{ 
   // loop through wDeck randomly swapping Cards
   for (size_t i = 0; i < CARDS; ++i) { 
      size_t j = rand() % CARDS;
      Card temp = wDeck[i];      
      wDeck[i] = wDeck[j];
      wDeck[j] = temp;      
   } 
}

// output cards in two-column format; cards 0-25 indexed with 
// k1 (column 1); cards 26-51 indexed with k2 (column 2)
void deal(const Card * const wDeck)
{
	// initialize suit array                       
	const char *suit[SUITS] =            
		{"Hearts", "Diamonds", "Clubs", "Spades"};
	
	// initialize face array                   
	const char *face[FACES] =
		{"Ace", "Deuce", "Three", "Four",         
		"Five", "Six", "Seven", "Eight",         
		"Nine", "Ten", "Jack", "Queen", "King"};
		
	// initialize colors array                       
	const char *color[COLORS] = {"Red", "Black"};

	printf("%-5s %5s    %-8s   %-5s %5s    %-8s\n", "Color", "Card", "Suit",
		"Color", "Card", "Suit");
	// loop through wDeck
	for (size_t k1 = 0, k2 = k1 + 26; k1 < CARDS / 2; ++k1, ++k2) {
		printf("%-5s %5s of %-8s   ",
			color[wDeck[k1].color], face[wDeck[k1].face], suit[wDeck[k1].suit]);
		printf("%-5s %5s of %-8s\n",
			color[wDeck[k2].color], face[wDeck[k2].face], suit[wDeck[k2].suit]);
	}
}