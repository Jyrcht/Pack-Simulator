#include "pack.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <set>
#include <unordered_set>

Pack::Pack(std::string g, std::string s){
    game = g;
    set = s;
    if(set == "CMF" || set == "TAT" || set == "MPR" || set == "MOA"){
        cluster="Grimm";
    }
    else if(set == "SKL" || set == "TTW" || set == "TMS" || set == "BFA"){
        cluster="Alice";
    }
    else if(set == "CFC" || set == "LEL" || set == "RDE" || set == "ENW"){
        cluster="Lapis";
    }
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
        /*         
        if(cards[code].rarity=="")
            continue;
        */
        rarites[cards[code].rarity].push_back(cards[code].code);
    }

    //print all rarities
    /*
    for(auto const& rarity: rarites){
        std::cout<<rarity.first<<": \n";
        for(auto const& str: rarity.second){
            std::cout<<str<<"\n";
        }
        std::cout<<"\n";
    }
    //*/

    //Build pack based on rarities
    if(cluster=="Grimm"){
        buildGrimm(cards,rarites);
    }else if(cluster=="Alice"){
        buildAlice(cards,rarites);
    }
    else if(cluster=="Lapis"){
        buildLapis(cards,rarites);
    }

}

void Pack::buildGrimm(std::unordered_map<std::string, card>& cards, std::unordered_map<std::string, std::vector<std::string>>& rarites){

}

void Pack::buildAlice(std::unordered_map<std::string, card>& cards, std::unordered_map<std::string, std::vector<std::string>>& rarites){
    srand((unsigned)time(0));
    int n = 0;
    std::unordered_set<int> used;
    for(int i=1;i<=7;i++){
        if(i<=5){
            auto pos = used.find(0); 
            do{
                n = (rand()%rarites["Common"].size());
                pos = used.find(n); 
            }while(pos!=used.end());
            used.emplace(n);
            this->cards.push_back(cards[rarites["Common"][n]]);
            if(i==5)
                used.clear();
        }
        else if(i<=7){
            auto pos = used.find(0); 
            do{
                n = (rand()%rarites["Uncommon"].size());
                pos = used.find(n); 
            }while(pos!=used.end());
            used.emplace(n);
            this->cards.push_back(cards[rarites["Uncommon"][n]]);
            if(i==7)
                used.clear();
        }
    }
    n = (rand()%rarites["Rare"].size());
    this->cards.push_back(cards[rarites["Rare"][n]]);
    n = (rand()%18)+1;
    if(n<=6){
        n = (rand()%rarites["Super"].size());
        this->cards.push_back(cards[rarites["Super"][n]]);
    }
    else if(n<=17){
        //Stone
        n = (rand()%rarites[""].size());
        this->cards.push_back(cards[rarites[""][n]]);
    }
    else{
        n = (rand()%rarites["Super"].size());
        this->cards.push_back(cards[rarites["Super"][n]]);
    }
    n = (rand()%4)+1;
    switch(n){
        case 1:
            n = (rand()%rarites["Common"].size());
            this->cards.push_back(cards[rarites["Common"][n]]);
        break;
        case 2:
            n = (rand()%rarites["Uncommon"].size());
            this->cards.push_back(cards[rarites["Uncommon"][n]]);
        break;
        case 3:
            n = (rand()%rarites["Rare"].size());
            this->cards.push_back(cards[rarites["Rare"][n]]);
        break;
        case 4:
            n = (rand()%rarites["Super"].size());
            this->cards.push_back(cards[rarites["Super"][n]]);
        break;
    }

}
    
void Pack::buildLapis(std::unordered_map<std::string, card>& cards, std::unordered_map<std::string, std::vector<std::string>>& rarites){
    for(int i=0;i<10;i++){
        if(i<=5){

        }
        else if(i<=7){

        }
        else if(i==8){

        }
        else if(i==9){

        }else{
            
        }
    }
}


void::Pack::open(){
    for(card c : cards){
        std::cout<<c.name<<'\n';
    }
}