#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <unordered_map>

#include "cards.h"

void fowLoop();
void loadSets(std::unordered_map<std::string, card_t>& cards);
void constructPack();
void openPack();
void checkCards(std::unordered_map<std::string, card>& cards);

#endif