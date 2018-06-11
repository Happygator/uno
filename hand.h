/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hand.h
 * Author: arthur
 *
 * Created on June 9, 2018, 11:59 AM
 */

#ifndef HAND_H
#define HAND_H
#include "deck.h"

class Hand {
public:
    Hand(Deck* deck);
    void AddCard(Deck* deck);
    void RemoveCard(/* start with 0 */ int card_position);
    void PrintHand();
    Card PlayCard(int cardtoplay);
    Card CardatPosition(int position);
    int CardsinHand();
    int FirstPlayableCard(const Card& currentcard);
    bool CardCanPlay(const Card& card1, const Card& card2);
private:
    std::vector<Card> cards;
};

#endif /* HAND_H */

