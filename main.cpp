#include "main.h"

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <unordered_set>

#include "pack.h"

void fowLoop(){

    std::vector<Pack> packs;

    int choice=0;
    bool bad_input=false;
    do{
        std::cout<<"Select option:\n1.Load Sets\n2.Construct pack\n3.Open pack\n";
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

    switch(choice){
        case 1:
            loadSets();
            break;
        case 2:
            constructPack();
            break;
        case 3:
            openPack();
            break;
    }

}

void loadSets(){
    std::cout<<"\nType the three letter code for all sets desired, seperated by a space.\n";
    std::string sets;
    std::getline(std::cin,sets);
    std::cin.clear();
    loadFow(sets);
}

void constructPack(){

}

void openPack(){

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
        if(choice<1||choice>1){
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