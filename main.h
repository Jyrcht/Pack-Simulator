#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <unordered_map>

#include "cards.h"
#include "pack.h"

void fowLoop();
void loadSets(std::unordered_map<std::string, card_t>& cards);
Pack constructPack(std::unordered_map<std::string, card>& cards, std::string set);
void openPack(std::vector<Pack>& packs);
void checkCards(std::unordered_map<std::string, card>& cards);

#endif