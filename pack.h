#ifndef PACK_H
#define PACH_H

#include <string>
#include <unordered_set>

#include "cards.h"

class Pack{
    private:
        std::string game;
        std::string set;
        std::string cluster;
        std::vector<card> cards;

        void buildGrimm(std::unordered_map<std::string, card>& cards, std::unordered_map<std::string, std::vector<std::string>>& rarites);
        void buildAlice(std::unordered_map<std::string, card>& cards, std::unordered_map<std::string, std::vector<std::string>>& rarites);
        void buildLapis(std::unordered_map<std::string, card>& cards, std::unordered_map<std::string, std::vector<std::string>>& rarites);

    public:
        Pack(std::string g, std::string s);

        void build(std::unordered_map<std::string, card>& cards);
        void open();

        std::string getGame(){return game;}
        std::string getSet(){return set;}
        std::vector<card> getCards(){return cards;}
};

#endif