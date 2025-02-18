// includes

#include <stdio.h>

// structs and impls

// global decl

struct card {
  int number;
  int suit;
  // 0 = swords
  // 1 = cups
  // 2 = coins
  // 3 = clubs
};

struct card deck[40];

// other functions

void initalize_deck ()
{
  int n = 1;
  int d = 0;

  for (int i = 0; i < 40; i++) { // loop through every card
    deck[i].number = n;
    deck[i].suit = d;

    switch (n) {
      case 7:  
        n = 10; // no 8 or 9 in the Spanish deck
        break;
      case 12: 
        n = 1;  // new suit!
        d++;
        break;
      default: n++;
    }
  }
}

void print_cards(int cards) {
  for (int i = 0; i < cards; i++) {
    printf("%d", deck[i].number);
    printf(", ");
    switch (deck[i].suit) {
      case 0:
        printf("SWORDS\n");
        break;
      case 1:
        printf("CUPS\n");
        break;
      case 2:
        printf("COINS\n");
        break;
      case 3:
        printf("CLUBS\n");
        break;
      default:
        printf("someone's gotten creative\n");
    }
  }
}

// main() function

int main(int argc, char *argv[])
{
  initalize_deck();

  print_cards(40);
}

