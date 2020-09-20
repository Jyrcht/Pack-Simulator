#include "cards.h"

#include <stdio.h>

#include <iostream>
#include <locale>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, card> loadFow(std::string sets){
    std::unordered_map<std::string, card> cards;
    FILE *data;
    std::string set;

    std::locale loc;
    for(std::string::size_type i=0; i<sets.length(); i++)
        sets[i]=std::toupper(sets[i],loc);

    std::cout<<sets<<'\n';

    data=fopen("./FoW/carddata.txt","r");
    if(data==NULL){
        fprintf(stderr,"Could not open file");
        return cards; 
    }
    else{

    }
    free(data);

    return cards;
}