/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "card.h"
using namespace std;

Card::Card(string c, string v) {
    color = c;
    value = v;
}

string Card::GetColor() const {
    return color;
}

string Card::GetValue() const {
    return value;
}

string Card::Print() {
    if (color == "") {
        return value;
    } else if (value == "") {
        return "any " + color;
    }
    return color + " " + value;
}
