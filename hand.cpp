/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "hand.h"
using namespace std;

Hand::Hand(Deck* deck) {
    for (int i = 0; i < 7; i++) {
        AddCard(deck);
    }
}

void Hand::AddCard(Deck* deck) {
    cards.push_back(deck->TakeOneCard());
}
Card Hand::CardatPosition(int position){
    return cards.at(position);
}

bool Hand::CardCanPlay(const Card& card1, const Card& card2){
    if (card1.GetColor().empty() || card2.GetColor().empty()){
        return true;   
    } else if (card1.GetColor() == card2.GetColor() || card1.GetValue() == card2.GetValue()){
        return true;
    }
    return false;
}
void Hand::RemoveCard(/* start with 0 */ int card_position) {
    cards.erase(cards.begin() + card_position);
}
Card Hand::PlayCard(int cardtoplay){
    Card card = cards.at(cardtoplay);
    RemoveCard(cardtoplay);
    return card;
}
int Hand::FirstPlayableCard(const Card& currentcard){
    for (int i = 0; i < cards.size(); i++) {
        if (CardCanPlay(currentcard, cards.at(i))){
            return i;
        }
    }
    return -1;
}
void Hand::PrintHand() {
    cout << "*** Hand *********\n";
    for (int i = 0; i < cards.size(); i++) {
        cout << i << ": " << cards.at(i).Print() << endl;
    }
    cout << " end of Hand \n";
}

int Hand::CardsinHand() {
    return cards.size();
}