/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   card.h
 * Author: arthur
 *
 * Created on June 9, 2018, 11:15 AM
 */

#ifndef CARD_H
#define CARD_H
#include <cstdlib>
#include <string>

const std::string colors[4] = {"red", "yellow", "green", "blue"};
const std::string draw4 = "draw4";
const std::string wild = "wild";
const std::string draw2 = "draw2";
const std::string skip = "skip";
const std::string reverse = "reverse";



class Card {
public:

    Card(){};
    Card(std::string c, std::string v);
    std::string GetColor() const;
    std::string GetValue() const;
    std::string Print();
private:
    std::string color;
    std::string value;
};

#endif /* CARD_H */