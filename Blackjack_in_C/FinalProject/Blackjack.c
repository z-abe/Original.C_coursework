#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CARDS 52
#pragma warning(disable:4996)

int main(void) {

	unsigned int bank;
	unsigned int bet;
	char* suit[4] = { " of Hearts", " of Diamonds", " of Clubs", " of Spades" };
	char* face[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	char deck[CARDS] = { "0" };
	int i;

	srand(time(NULL));

	printf("Welcome to blackjack!\nEnter your starting bank: $");
	scanf_s("%d", &bank);

	printf("Enter your starting bet: $");
	scanf_s("%d", &bet);

	printf("Your first two cards are:\n"); 

	for (i = 0; i < 2; i++) {
		int j = rand() % 13 - 1;
		int k = rand() % 4 - 1;
		int m = rand() % 3;
		
		
		switch (*face[j]) {
			case 'A':
				printf("%s", strcat(face[0], suit[k]));
				break;
			case '2':
				printf("%s", strcat(face[1], suit[k]));
				break;
			case '3':
				printf("%s", strcat(face[2], suit[k]));
				break;
			case '4':
				printf("%s", strcat(face[3], suit[k]));
				break;
			case '5':
				printf("%s", strcat(face[4], suit[k]));
				break;
			case '6':
				printf("%s", strcat(face[5], suit[k]));
				break;
			case '7':
				printf("%s", strcat(face[6], suit[k]));
				break;
			case '8':
				printf("%s", strcat(face[7], suit[k]));
				break;
			case '9':
				printf("%s", strcat(face[8], suit[k]));
				break;
			case '10':
				printf("%s", strcat(face[9], suit[k]));
				break;
			case 'J':
				printf("%s", strcat(face[10], suit[k]));
				break;
			case 'Q':
				printf("%s", strcat(face[11], suit[k]));
				break;
			case 'K':
				printf("%s", strcat(face[12], suit[k]));
				break;
		}





	}





}