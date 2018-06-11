/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   deck.h
 * Author: arthur
 *
 * Created on June 9, 2018, 11:47 AM
 */

#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck {
public:
    Deck();
    void shuffle();
    void Print();

    Card TakeOneCard();
    int CardsInDeck();
private:
    void AddCard(const std::string& color, const std::string& value, int times);
    std::vector<Card> cards;
};


#endif /* DECK_H */

