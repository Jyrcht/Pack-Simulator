#include "cards.h"

#include <stdio.h>

#include <string>
#include <unordered_map>

std::unordered_map<std::string, card> loadFow(std::string sets){

    FILE *data;
    data=fopen("./FoW/carddata.txt","r");
    if(data==NULL){
        fprintf(stderr,"Could not open file");
        exit(-1);
    }

    std::unordered_map<std::string, card> cards;
    return cards;
}