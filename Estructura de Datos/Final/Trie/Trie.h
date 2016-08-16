//
//  Trie.hpp
//  Trie
//
//  Created by Adrián Biller on 11/19/15.
//  Copyright © 2015 Adrián Biller. All rights reserved.
//

#pragma once
#include "trieNode.h"
#include <string.h>



class Trie
{
    
private:
    trieNode* root;
    
    
    
public:
    Trie();
    void add(std::string word);
    bool search(std::string word);
    void print(trieNode * _root);
    void print();

};


Trie::Trie()
{
    this->root = new trieNode;
}


void Trie::add(std::string word)
{
    trieNode* root = this->root;
    if(word.length() ==0)
    {
        root->getWordM();
        return;
    }
    
    for(int i =0; i<word.length(); i++)
    {
        trieNode * tmp = root->searchNext(word[i]);
        if(tmp != NULL)
        {
            root = tmp;
        }
        else
        {
            trieNode * tmp2 = new trieNode();
            tmp2->setData(word[i]);
            root->addLetter(tmp2);
            root = tmp2;
        }
        if(i ==word.length()-1)
        {
            root->setWordM();
        }
    }
}


bool Trie::search(std::string word)
{
    trieNode * current = root;
    while(current  != NULL)
    {
        for(int i = 0; i<word.length(); i++)
        {
            trieNode * tmp = current->searchNext(word[i]);
            if(tmp == NULL )
                return false;
            current = tmp;
        }
        if(current->getWordM())
            return true;
        else
            return false;
    }
    return false;
}

void Trie::print()
{
    if(this->root == nullptr)
        return;
    else print(this->root);
    std::cout<< std::endl;
}


void Trie::print(trieNode * _root)
{
    
    for(int i = 0; i<26; i++)
    {
        if(_root == nullptr)
            return;
        print(_root->searchNext(i));
        std::cout<<_root->getData()<<std::endl;
    }
}






