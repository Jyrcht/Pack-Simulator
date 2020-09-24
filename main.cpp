#include "main.h"

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <unordered_set>

#include "pack.h"

void fowLoop(){

    std::vector<Pack> packs;
    std::unordered_map<std::string, card> cards;

    bool loop=true;
    do{
        int choice=0;
        bool bad_input=false;
        do{
            std::cout<<"Select option:\n1.Load Sets\n2.Construct pack\n3.Open pack\n4.Check cards\n";
            if(std::cin >> choice){
                bad_input=false;
            }
            else{
                bad_input=true;
                std::cerr<<"Bad input, must be of type int.\n\n";
            }
            if(choice<1||choice>4){
                bad_input=true;
                std::cerr << "Bad Input, not an available option.\n\n";
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }while(bad_input);

        switch(choice){
            case 1:
                loadSets(cards);
                if(cards.empty())
                    std::cerr<<"Error: Couldn't load cards!\n\n";
                break;
            case 2:
                constructPack();
                break;
            case 3:
                openPack();
                break;
            case 4:
                checkCards(cards);
                break;
        }
    }while(loop);
}

void loadSets(std::unordered_map<std::string, card_t>& cards){
    std::cout<<"\nType the three letter code for all sets desired, seperated by a space.\n";
    std::string sets;
    std::getline(std::cin,sets);
    std::cin.clear();
    cards = loadFow(sets);
}

void constructPack(){

}

void openPack(){

}

void checkCards(std::unordered_map<std::string, card>& cards){
    bool loop = true;
    do{
        std::string choice;
        bool bad_input=false;
        do{
            std::cout<<"Enter card code or q to quit.\n";
            if(std::cin >> choice){
                bad_input=false;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }while(bad_input);

        if(choice=="q"){
            break;
        }        

        std::cout<<cards[choice].name<<'\n';

    }while(loop);
}

int main(int argc, char **argv){

    int choice=0;
    bool bad_input=false;

    do{
        std::cout<<"Select card game:\n1.Force of Will\n";
        if(std::cin >> choice){
            bad_input=false;
        }
        else{
            bad_input=true;
            std::cerr<<"Bad input, must be of type int.\n\n";
        }
        if(!bad_input && (choice<1||choice>1)){
            bad_input=true;
            std::cerr << "Bad Input, not an available option.\n\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(bad_input);

    std::cout<<'\n';

    switch(choice){
        case 1:
            fowLoop();
            break;  
    }

    return 0;
}