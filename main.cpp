#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
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
            hand1.PrintHand();
            cout << "Current card is " << currentcard.Print() << endl;
            cout << "Type the number of the card to play it, or type -1 to draw a card." << endl;
            cin >> cardplayed;
            if (cardplayed == -1) {
                hand1.AddCard(&deck);
                cout << "You draw a card" << endl;
            } else {
                currentcard = hand1.PlayCard(cardplayed);
                cout << "You play " << currentcard.Print() << endl;
                if (currentcard.GetValue() == "skip" || currentcard.GetValue() == "reverse") {
                    continue;
                } else if (currentcard.GetValue() == "draw2") {
                    hand2.AddCard(&deck);
                    hand2.AddCard(&deck);
                    continue;
                } else if (currentcard.GetValue() == "wild") {
                    cout << "What color do you choose?(all lowercase)" << endl;
                    cin >> colorchosen;
                    currentcard = Card(colorchosen, "");
                } else if (currentcard.GetValue() == "draw4") {
                    cout << "What color do you choose?(all lowercase)" << endl;
                            currentcard = Card(colorchosen, "");
                    for (int i = 0; i < 4; i++) {
                        hand2.AddCard(&deck);
                    }  
                    continue;
                }
            }
        }
        playerskipped = false;
        if (hand1.CardsinHand() == 0) {
            break;
        }
        //Computer's turn
        computerplaying = hand2.FirstPlayableCard(currentcard);
        if (hand2.CardatPosition(computerplaying).GetValue().empty()) {
            hand2.AddCard(&deck);
            cout << "Computer draws a card" << endl;
        } else {
            currentcard = hand2.PlayCard(computerplaying);
            cout << "Computer plays " << currentcard.Print() << endl;
            if (currentcard.GetValue() == "skip" || currentcard.GetValue() == "reverse") {
                //skip player
                cout << "Your turn is skipped" << endl;
            } else if (currentcard.GetValue() == "draw2") {
                hand1.AddCard(&deck);
                hand1.AddCard(&deck);
                //skip player
                cout << "You draw 2 cards" << endl;
                cout << "Your turn is skipped" << endl;
            } else if (currentcard.GetValue() == "wild") {
                cout << "Computer chooses " << colorchosen << endl;
                //computer picks a color
                currentcard = Card(colorchosen, "");
            } else if (currentcard.GetValue() == "draw4") {
                //computer picks a color
                cout << "Computer chooses " << colorchosen << endl;
                currentcard = Card(colorchosen, "");
                for (int i = 0; i < 4; i++) {
                    hand1.AddCard(&deck);
                }
                //skip player
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

