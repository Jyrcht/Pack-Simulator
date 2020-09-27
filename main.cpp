#include "main.h"

#include <iostream>
#include <limits>
#include <locale>
#include <string>
#include <vector>
#include <unordered_set>

void fowLoop(){

    std::vector<Pack> packs;
    std::unordered_map<std::string, card> cards = loadFow();

    if(cards.empty())
        std::cerr<<"Error: Couldn't load cards!\n\n";

    bool loop=true;
    do{
        int choice=0;
        bool bad_input=false;
        do{
            std::cout<<"Select option:\n1.Construct pack\n2.Open pack\n3.Check cards\n";
            if(std::cin >> choice){
                bad_input=false;
            }
            else{
                bad_input=true;
                std::cerr<<"Bad input, must be of type int.\n\n";
            }
            if(choice<1||choice>3){
                bad_input=true;
                std::cerr << "Bad Input, not an available option.\n\n";
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }while(bad_input);

        std::cout<<'\n';
        std::string set;        
        std::locale loc;
        switch(choice){
            case 1:
                std::cout<<"\nType the three letter code for the desired set.\n";
                std::getline(std::cin,set);
                for(std::size_t i=0; i<set.length(); i++)
                    set[i]=std::toupper(set[i],loc);   
                for(int i=0;i<5;i++)           
                    packs.push_back(constructPack(cards,set));
                break;
            case 2:
                openPack(packs);
                break;
            case 3:
                checkCards(cards);
                break;
        }
    }while(loop);
}

Pack constructPack(std::unordered_map<std::string, card>& cards, std::string set){
    Pack pak("FoW",set);
    pak.build(cards);
    return pak;
}

void openPack(std::vector<Pack>& packs){
    for(Pack p : packs){
        p.open();
    }
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

        std::cout<<cards[choice].name<<" "<<cards[choice].rarity <<'\n';

    }while(loop);
}

int main(int argc, char **argv){

    int choice=0;
    bool bad_input=false;

    srand((unsigned)time(0));

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