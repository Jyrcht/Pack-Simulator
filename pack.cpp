#include "pack.h"

#include <iostream>
#include <set>
#include <unordered_set>

Pack::Pack(std::string g, std::string s){
    game = g;
    set = s;
}

void Pack::build(std::unordered_map<std::string, card>& cards){
    //Get the set cards mapped via rarity
    std::unordered_map<std::string, std::vector<std::string>> rarites;
    std::string code(set);
    code+="-000";
    for(int i=1;;i++){
        if(i>=10){
            code.pop_back();
        }
        if(i>=100){
            code.pop_back();
        } 
        code.pop_back();
        code+=std::to_string(i);
        std::unordered_map<std::string, card>::const_iterator pos = cards.find(code);
        if(pos==cards.end()){
            break;
        }          
        if(cards[code].rarity=="")
            continue;
        rarites[cards[code].rarity].push_back(cards[code].code);
    }

    //print all rarities
    for(auto const& rarity: rarites){
        std::cout<<rarity.first<<": \n";
        for(auto const& str: rarity.second){
            std::cout<<str<<"\n";
        }
        std::cout<<"\n";
    }

}

void::Pack::open(){
    for(card c : cards){
        std::cout<<c.name<<'\n';
    }
}