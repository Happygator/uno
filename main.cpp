#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <curses.h>
#include "card.h"
#include "deck.h"
#include "hand.h"

using namespace std;


// at most one of these comments are true
// the comment below is false
// all comments above are false
// at least two of these comments are true
// the comment above is true
int cardplayed = 0;
int rand1 = 0;
int rand2 = 0;
bool playerskipped;
string colorchosen;
Card currentcard;
int computerplaying;
bool carddrawn;
bool cardlegal = false;

int main(int argc, char** argv) {
    Deck deck;
    deck.shuffle();
    deck.Print();
    currentcard = deck.TakeOneCard();
    Hand hand1(&deck);
    Hand hand2(&deck);
    //hand1 is player's hand, hand 2 is opponent's hand 
    cout << "*************\n";
    while (hand1.CardsinHand() > 0 && hand2.CardsinHand() > 0) {
        //Player's turn
        if (not playerskipped) {
            while (not cardlegal){
            hand1.PrintHand();
            cout << "Current card is " << currentcard.Print() << endl;
            cout << "Opponent has " << hand2.CardsinHand() << " cards in hand" << endl; 
            cout << "Type the number of the card to play it, or type -1 to draw a card." << endl;
            cin >> cardplayed;
            if (cardplayed == -1) {
                cardlegal = true;
            } else if (hand1.CardCanPlay(hand1.CardatPosition(cardplayed), currentcard)) {
                cardlegal = true;
            } else {
                cout << "That was not a legal card to play. Try again." << endl;
            }
            }
            cardlegal = false;
            if (cardplayed == -1) {
                hand1.AddCard(&deck);
                carddrawn = true;
                for (int i=0; i<10; i++) {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                }
            } else {
                currentcard = hand1.PlayCard(cardplayed);
                if (currentcard.GetValue() == wild || currentcard.GetValue() == draw4){
                    cout << "What color do you choose?(all lowercase)" << endl;
                    cin >> colorchosen;
                }
                for (int i=0; i<10; i++) {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                }
                cout << "You play " << currentcard.Print() << endl;
                
                if (currentcard.GetValue() == skip || currentcard.GetValue() == reverse) {
                    cout << "Opponent's turn is skipped" << endl;
                    continue;
                } else if (currentcard.GetValue() == draw2) {
                    hand2.AddCard(&deck);
                    hand2.AddCard(&deck);
                    cout << "Opponent draws 2 cards" << endl;
                    cout << "Opponent's turn is skipped" << endl;
                    continue;
                } else if (currentcard.GetValue() == wild) {
                    cout << "You choose " << colorchosen << endl;
                    currentcard = Card(colorchosen, "");
                } else if (currentcard.GetValue() == draw4) {
                    cout << "You choose " << colorchosen << endl;
                    currentcard = Card(colorchosen, "");
                    for (int i = 0; i < 4; i++) {
                        hand2.AddCard(&deck);
                    }  
                    cout << "Opponent draws 4 cards" << endl;
                    cout << "Opponent's turn is skipped" << endl;
                    continue;
                }
            }
            if (carddrawn) {
                cout << "You draw a card" << endl;
                carddrawn = false;
            }
        }
        playerskipped = false;
        if (hand1.CardsinHand() == 0) {
            break;
        }
        cout << "Computer's turn" << endl;
        //Computer's turn
        computerplaying = hand2.FirstPlayableCard(currentcard);
        if (computerplaying == -1) {
            hand2.AddCard(&deck);
            cout << "Computer draws a card" << endl;
        } else {
            currentcard = hand2.PlayCard(computerplaying);
            cout << "Computer plays " << currentcard.Print() << endl;
            if (currentcard.GetValue() == skip || currentcard.GetValue() == reverse) {
                playerskipped = true;
                cout << "Your turn is skipped" << endl;
            } else if (currentcard.GetValue() == draw2) {
                hand1.AddCard(&deck);
                hand1.AddCard(&deck);
                playerskipped = true;
                cout << "You draw 2 cards" << endl;
                cout << "Your turn is skipped" << endl;
            } else if (currentcard.GetValue() == wild) {
                cout << "Computer chooses " << colorchosen << endl;
                colorchosen = colors[rand() % 4];
                currentcard = Card(colorchosen, "");
            } else if (currentcard.GetValue() == draw4) {
                colorchosen = colors[rand() % 4];
                cout << "Computer chooses " << colorchosen << endl;
                currentcard = Card(colorchosen, "");
                for (int i = 0; i < 4; i++) {
                    hand1.AddCard(&deck);
                }
                playerskipped = true;
                cout << "You draw 4 cards" << endl;
                cout << "Your turn is skipped" << endl;
            }

        }
    }
    if (hand1.CardsinHand() == 0) {
        cout << "You win!";
    } else {

        cout << "You lose!";
    }
    return 0;
}
