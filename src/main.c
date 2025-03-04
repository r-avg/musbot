// includes

#include <math.h>
#include <stdio.h>
#include <stdlib.h> // for rng
#include <stdbool.h> // booleans are dlc, for whatever reason
#include <string.h>

// structs and impls

struct card {
  int number; // dummy cards will have a zero as number
  int suit; // could this be an enum? yeah most likely but who cares 
  // 0 = swords
  // 1 = cups
  // 2 = coins
  // 3 = clubs
  // 4 = dummy card! symbolizing an empty card
};

struct card deck[40];
struct card discard_pile[40];

struct player {
  struct card hand[4];
  bool is_pair; // if player isn't your pair, then they're part of the other pair!
  char name[10]; // arrays of undeclared length must be declared at the end of the struct
};

struct player players[4];

// debug functions

void print_card(struct card input_card) {
  if (input_card.number != 0) { // dummy cards aren't printed because why would they
    printf("  %d of ", input_card.number);
  }
  
  switch (input_card.suit) {
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
    case 4: // dummy cards
      break;
    default:
      printf("someone's gotten creative!\n");
  }
}

void print_deck() { // this function used for debugging shit with the deck
  for (int i = 0; i < 40; i++) {
    print_card(deck[i]);
  }
}

void print_hand(struct player current_player) {
  for (int j = 0; j < 4; j++) { // loop through cards
    print_card(current_player.hand[j]);
  }
}

void print_player_name(int i) {
  printf("%s\n", players[i].name);
}

// regular old functions

void initalize_deck () {
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

  // the discard pile starts full of dummy cards!
    discard_pile[i].number = 0;
    discard_pile[i].suit = 4;
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

int current_deck_length() {
  bool done_reading = false;
  int deck_length = 0;

  for (int i = 0; !done_reading; i++) {
    if (deck[i].suit == 4 || deck[i].number == 0) {
      done_reading = true;
      deck_length = i;
    }
  }

  return deck_length;
}

struct card dummy() {
  struct card dummy;
  dummy.number = 0;
  dummy.suit = 4;
  return dummy;
}

struct card draw_card() { // gets the top card from the deck, "deletes" that card and shuffles all cards forwards once
  struct card drawn_card = deck[0];

  int deck_length = current_deck_length();

  for (int i = 0; i <= deck_length; i++) {
    if (i == deck_length) { // to avoid duplicating cards 
      deck[i] = dummy();
    } else {
      deck[i] = deck[i+1]; // NOTE: might cause OOB so keep an eye out! teehee
    }
  }

  return drawn_card;
}

void discard_card() {
  // pick a card to discard
  int answer;
  struct card discarded_card; // having the card be saved in lieu of just deleting could come in handy
  bool correct_input = false;

  printf("Your current hand is:\n");
  print_hand(players[0]);

  while (!correct_input) {
    printf("Which card do you wish to discard (1..4)?\n");
    scanf("%d", answer);

    switch (answer) {
      case 1 | 2 | 3 | 4: // why this needs to be a bitwise OR i know not
        discarded_card = players[0].hand[answer-1];
        correct_input = true;
        break;
      default:
        printf("Invalid answer!");
    }
  }


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

void turn() { // TODO: for testing purposes, you're the only one playing for now
  char answer[15];

  printf("Your current hand is:\n");
  print_hand(players[0]);

  while (strcmp("no mus\n", answer) != 0) {
    while (strcmp("mus\n", answer) != 0 && strcmp("no mus\n", answer) != 0) { // fgets adds a newline at the end
      printf("Do you wish to discard and draw a card (mus) or end the drawing phase (no mus)?\n");
      fgets(answer, sizeof(answer), stdin);
      printf("%s", answer);

      printf("%i\n", strcmp("mus", answer));
      printf("%i\n", strcmp("no mus", answer));
    }

    if (strcmp("mus", answer)) {
      discard_card();
      draw_card();

      print_hand(players[0]);
    } else {
      printf("And the drawing and discarding phase ends!");
      // end_phase();
    }
  }
}

// main() function

int main(int argc, char *argv[])
{
  initalize_deck();

  shuffle();

  init_players();

  for (int i = 0; i < 4; i++) {
    print_player_name(i);
    print_hand(players[i]);
  }

  turn();

  // print_deck();
}

