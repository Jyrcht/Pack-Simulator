#ifndef PACK_H
#define PACH_H

#include <string>
#include <unordered_set>

#include "cards.h"

class Pack{
    private:
        std::string game;
        std::string set;
        std::unordered_multiset<std::string> cards;
    public:
        Pack(std::string g, std::string s);


        void makePack(std::string set);
        void openPack();

        std::string getGame(){return game;}
        std::string getSet(){return set;}
        std::unordered_multiset<std::string> getCards(){return cards;}
};

#endif