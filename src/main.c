// includes

#include <stdio.h>
#include <stdlib.h> // for rng
#include <stdbool.h> // booleans are dlc, for whatever reason
#include <string.h>

// structs and impls

struct card {
  int number;
  int suit; // could this be an enum? yeah most likely but who cares 
  // 0 = swords
  // 1 = cups
  // 2 = coins
  // 3 = clubs
};

struct card deck[40];

struct player {
  struct card hand[4];
  bool is_pair; // if player isn't your pair, then they're part of the other pair!
  char name[]; // arrays of undeclared length must be declared at the end of the struct
};

struct player players[4];

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

void print_deck(int cards) { // this function used for debugging shit with the deck
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
  for (int i = 0; i < 40; i++) {
    int r = rand() % 40;
    struct card temp = deck[r];
    deck[r] = deck[i];
    deck[i] = temp;
  }
}

struct card draw_card() { // gets the top card from the deck, "deletes" that card and shuffles all cards forwards once
  struct card drawn_card = deck[0];

  for (int i = 0; i < 40; i++) {
    deck[i] = deck[i+1]; // might cause OOB so keep an eye out! teehee
  }

  return drawn_card;
}

void init_players() {
  for (int i = 0; i < 4; i++) { // loop through the players
    strcpy(players[i].name, "Norberto"); // can't assign to an array because reasons
   
    for (int j = 0; j < 4; j++) {
      players[i].hand[j] = draw_card();
    }
    // TODO: the rest of player initialization
  }
}

// main() function

int main(int argc, char *argv[])
{
  initalize_deck();

  shuffle();

  print_deck(40);
}

