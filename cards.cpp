#include "cards.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <locale>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, card_t> loadFow(std::string sets){
    std::unordered_map<std::string, card_t> cards;
    std::ifstream data;
    std::string set;

    std::locale loc;
    for(std::string::size_type i=0; i<sets.length(); i++)
        sets[i]=std::toupper(sets[i],loc);

    data.open("./FoW/carddata.txt",std::ios::in);
    if(!data.is_open()){
        std::cerr<<"Error opening './FoW/carddata.txt'\n";
        return cards;
    } 
    else{
        std::string line;
        std::getline(data,line);
        while(std::getline(data,line)){
            card_t card = makeCard(line);
            //std::cout<<card.name<<" "<<card.code<<" "<<card.rarity<<'\n';
            cards.emplace(card.code,card);
        }
        std::cout<<'\n';
    }

    return cards;
}

card_t makeCard(std::string line){
    card_t card;
    int cnt=1; 

    for(std::size_t i=0; i<line.find_last_of('\t');i++){
        std::size_t pos = line.find('\t',i);
        std::string str = line.substr(i,pos-i);
        switch(cnt){
            case 1:
            card.name=str;
            break;
            case 2:
            card.set=str;
            break;
            case 3:
            if(str.length()>7 && card.set.substr(0,3)!="VIN"){
                std::size_t pos = str.find(',');
                str=str.substr(0,pos); 
            }
            card.code=str;
            break;
            case 6:
            card.rarity=str;
            break;
        }
        i=pos;
        cnt++;
    }
    //std::string str = line.substr(line.find_last_of('\t'));
    //std::cout<<str<<'\n';
    return card;
}
