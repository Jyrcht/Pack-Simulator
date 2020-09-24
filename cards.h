#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <unordered_map>
#include <vector>

typedef struct card{
    std::string name;
    std::string set;
    std::string code;
    std::string rarity;
}card_t;

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
}fowcard_t;

std::unordered_map<std::string, card_t> loadFow(std::string sets);

card_t makeCard(std::string line);

#endif