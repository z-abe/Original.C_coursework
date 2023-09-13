#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int wDeck[][FACES]);
int deal(unsigned int wDeck[][FACES], const char* wFace[],
	const char* wSuit[], int player, int hand, int hit);

int main(void) {

	unsigned int deck[SUITS][FACES] = { 0 };
	unsigned int bank;
	unsigned int bet;
	int player;
	int dealer;
	int hand = 1;
	int hit = 3;
	unsigned int choice;
	int end = 1;
	unsigned int x = 1;

	srand(time(NULL));
	shuffle(deck);

	const char* suit[SUITS] =
	{ "Hearts", "Diamonds", "Clubs", "Spades" };

	const char* face[FACES] =
	{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K" };

	printf("Welcome to Blackjack!\nThe payout is 1-to-1\nThe dealer must hit to 18\nEnter your starting bank: $");
	scanf_s("%d", &bank);

	while (end == 1) {

		
		player = 0;
		dealer = 0;

		printf("Enter your starting bet: $");
		scanf_s("%d", &bet);

		while (bet > bank) {
			printf("You cannot bet more than you have...\nPlease enter bet: $");
			scanf_s("%d", &bet);
		}

		player = deal(deck, face, suit, player, hand, hit);
		hand = hand + 2;
		hit = hit + 2;
		printf("Your total is: %d\n", player);

		dealer = deal(deck, face, suit, dealer, hand, hit);
		hand = hand + 2;
		hit = hit + 2;
		printf("The dealer's total is: %d\n", dealer);

		if (player == 21 && dealer != 21) {
			printf("Blackjack! Winner Winner Chicken Dinner!");
			bank = bank + bet;

		}
		else if (dealer == 21 && player != 21){
			printf("Awe... Too bad. Dealer has blackjack.");
			bank = bank - bet;
		}
		else	{
			hand = hand + 2;
			++hit;
			printf("\n(1 = HIT)\n(2 = STAND)\nEnter choice: ");
			scanf_s("%d", &choice);

			while (choice == 1 && player < 21) {
				player = deal(deck, face, suit, player, hand, hit);

				printf("Your total is %d\n", player);
				if (player < 21) {
					printf("\n(1 = HIT)\n(2 = STAND)\nEnter choice: ");
					scanf_s("%d", &choice);
					++hand;
					++hit;
				}
			}

			while (choice == 2 && dealer < 19) {
				dealer = deal(deck, face, suit, dealer, hand, hit);

				printf("The dealer's total is %d\n", dealer);
				++hand;
				++hit;
			}

			if (player > 21) {
				bank = bank - bet;
				printf("You busted!");
			}
			else if (dealer > 21) {
				bank = bank + bet;
				printf("Dealer busted!\nIt's your lucky day!");
			}
			else if (player > dealer) {
				bank = bank + bet;
				printf("You win! Congrats!");
			}
			else if (dealer > player) {
				bank = bank - bet;
				printf("Sorry! Maybe next time...");
			}
			else if (player == dealer) {
				printf("That's a push... that's a win in my book.");
			}
		}
		printf("\n\nYou have $%d remaining.\n", bank);

		if (bank == 0) {
			printf("You are out of money.\nRun program to play again.");
			exit(1);
		}
		else {
			printf("Would you like to play again? \n(1 = YES)\n(2 = END)\nEnter choice : ");
			scanf_s("%d", &end);
			hit = hit + 2;
			++hand;
		}
		if (hit > 52) {
			printf("Deck has run out! Run program to play again.");
			exit(1);
		}
	}
}

void shuffle(unsigned int wDeck[][FACES]) {

	for (size_t card = 1; card <= CARDS; ++card) {
		size_t row;
		size_t column;

		do {
			row = rand() % SUITS;
			column = rand() % FACES;
		} while (wDeck[row][column] != 0);

		wDeck[row][column] = card;
	}
}

unsigned int deal(unsigned int wDeck[][FACES], const char* wFace[],
	const char* wSuit[], int player, int hand, int hit) {

	for (size_t count = hand; count < hit; ++count) {
		for (size_t row = 0; row < SUITS; ++row) {
			for (size_t column = 0; column < FACES; ++column) {
				if (wDeck[row][column] == count) {
					printf("%s of %s\n", wFace[column], wSuit[row]);

					switch (*wFace[column]) {
					case 'A':
						player += 11;
						break;
					case '2':
						player += 2;
						break;
					case '3':
						player += 3;
						break;
					case '4':
						player += 4;
						break;
					case '5':
						player += 5;
						break;
					case '6':
						player += 6;
						break;
					case '7':
						player += 7;
						break;
					case '8':
						player += 8;
						break;
					case '9':
						player += 9;
						break;
					case 'T':
						player += 10;
						break;
					case 'J':
						player += 10;
						break;
					case 'Q':
						player += 10;
						break;
					case 'K':
						player += 10;
						break;
					}
				}
			}
		}
	}
	return player;
}