# MUSBOT

This is a project with which I aim to learn a bit about C and also to play the classic Spanish card game ***Mus***. 

----------

## THE RULES OF THE GAME

Behold! An outline of the average game of *Mus*, according to the [Wikipedia article (in Spanish)](https://es.wikipedia.org/wiki/Mus) - which explains the rules in a decent amount of detail.

The game is generally played by four people, playing in pairs, but if you haven't been blessed with such a lively social life it can be played by two people.

1. Each player is given four cards from the deck by a player called the Hand (*mano*). 
2. Once they've had a chance to see their cards, starting with the Hand, they can either call for *mus* or *no mus*: if *mus* is unanymously agreed upon, players must discard at least one of their cards, leaving them facing down in the centre of the table, and they're given back an equal amount from the deck. Then, the step is repeated until one of the players doesn't agree to *mus*.
3. It's then time to get into the meat and potatoes of the game. From here, the game consists of four phases: 
    - ***Grande***: Whoever has the most valuable cards, wins! Therefore, if player A has three kings and the rest of players have no kings, player A's pair wins. In case of tie, whichever player has the most horses (knights on horseback, but literally named *caballos* in common Spanish parlance - the most remarkable part of the card, I guess) wins; then knights, then whichever number's higher.
    - ***Chica***: Whoever has the least valuable cards, wins! Aces are, in a refreshing twist, the *least* valuable card.
    - ***Pares***: Each player says whether or not they have a pair in their hand. This round plays only if both pairs have at least one player with at least a pair in their hand (because it's pointless otherwise). The order in this case is as follows:
        - *Duples*: Having either all four of a card or two pairs. Note that having all four of a card counts as two separate pairs, so in case of having two *duples* whoever has the highest pair wins
        - *Medias*: Having three of a card  
        - *Pares*: Having a single pair 
    - ***Juego***: Having **31 or more points** in the hand: Each player says whether they have 31 or more points in the hand (*juego sí*) or not (*juego no*). In case only one player or pair has *juego*, no betting takes place and the player wins the phase. In case both pairs have at least a player with *juego*, then normal betting rules apply. If no one has *juego*, then the aggregate score of the cards determines the winner, with normal betting taking place.   
     Cards give out points depending on their numerical value, with knights, horses and kings giving out 10 points each. There's some caveats to this, though:
    


## THINGS TO IMPLEMENT

- **THE DECK**: Pride and joy of the senior citizenry of my country 
- **A SHUFFLER**: A quick and dirty pseudo-random movement of the "cards" 
- **THE ACTUAL BOTS**: Four computer-generated people (likely with a random Basque name assigned to them, for added realism) that can play *Mus* more or less decently



