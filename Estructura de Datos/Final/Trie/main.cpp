//
//  main.cpp
//  Trie
//
//  Created by Adrián Biller on 11/19/15.
//  Copyright © 2015 Adrián Biller. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include "Trie.h"


int main ()
{
    
    Trie tree;
    std::string name;
    std::ifstream file;
    file.open("words.txt");
    
    if(file.is_open())
    {
        while(std::getline(file, name))
        {
            std::cout<<name<<" Adding the word "<<name<<std::endl;
            tree.add(name);
        }
        file.close();
    }
    else
        std::cout<<"The file could not be read"<<std::endl;
    
    
    return 0;
}