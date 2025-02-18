// includes

#include <stdio.h>
#include <stdlib.h> // for rng

// structs and impls

struct card {
  int number;
  int suit; // could this be an enum? yeah most likely but there isn't really much of a point
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
  int s = 0;

  for (int i = 0; i < 40; i++) { // loop through every card
    deck[i].number = n;
    deck[i].suit = s;

    switch (n) {
      case 7:  
        n = 10; // no 8 or 9 in the Spanish deck
        break;
      case 12: 
        n = 1;  // new suit!
        s++;
        break;
      default: n++;
    }
  }
}

void print_cards(int cards) { // this function used for debugging shit with the deck
  for (int i = 0; i < cards; i++) {
    printf("%d: ", i+1);
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
        printf("someone's gotten creative!\n");
    }
  }
}

void shuffle() {
  // int r = rand() % 20; <- generates a random int between 0 and 19!

  for (int i = 0; i < 40; i++) {
    int r = rand() % 40;
    struct card temp = deck[r];
    deck[r] = deck[i];
    deck[i] = temp;
  }
}

// main() function

int main(int argc, char *argv[])
{
  initalize_deck();

  shuffle();

  print_cards(40);
}

