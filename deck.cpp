/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <sstream>
#include <vector>
#include "deck.h"
using namespace std;

Deck::Deck() {
    int index = 0;
    for (int c = 0; c < 4; c++) {
        string color = colors[c];
        for (int i = 0; i < 10; i++) {
            std::ostringstream ss;
            ss << i;
            string value = ss.str();
            AddCard(color, value, 2);
        }
        AddCard(color, "skip", 2);
        AddCard(color, "reverse", 2);
        AddCard(color, "draw2", 2);
    }
    AddCard("", "wild", 4);
    AddCard("", "draw4", 4);

}

void Deck::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < 1000000; i++) {
        int rand1 = rand() % 112;
        int rand2 = rand() % 112;
        Card* a = &cards.at(rand1);
        Card* b = &cards.at(rand2);
        Card t = *a;
        *a = *b;
        *b = t;
    }

}
int Deck::CardsInDeck(){
    return cards.size();
}
Card Deck::TakeOneCard(){
    Card card = cards.back();
    cards.pop_back();
    return card;
}

void Deck::Print() {
    for (int i = 0; i < cards.size(); i++) {
        cout << cards.at(i).Print() << endl;
    }
}

void Deck::AddCard(const string& color, const string& value, int times) {
    Card card(color, value);
    for (int i = 0; i < times; i++) {
        cards.push_back(card);
    }

}