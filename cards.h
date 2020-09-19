#ifndef CARDS_H
#define CARDS_H

#include <stdio.h>

#include <string>
#include <unordered_map>

typedef struct card{
    std::string name;
    std::string set;
    std::string code;
    std::string rarity;
}card;

typedef struct fowcard: card{
    std::string type;
    std::string attribute;
    std::string cost;
    int total_cost;
    union{
        std::string race;
        std::string trait;
    };
    int atk;
    int def;
    std::string text;
}fowcard;

std::unordered_map<std::string, card> loadFow(std::string sets);

#endif