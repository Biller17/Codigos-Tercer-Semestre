//
//  trieNode.h
//  Trie
//
//  Created by Adrián Biller on 11/19/15.
//  Copyright © 2015 Adrián Biller. All rights reserved.
//

#pragma once
#include <iostream>
#include <vector>


class trieNode
{
protected:
    char data;
    bool wordM;
    std::vector <trieNode*> next;
    
    
public:
    trieNode(){ data = ' '; };
    trieNode(char _data);
    char getData();
    void setData(char _item);
    bool getWordM();
    void setWordM();
    trieNode * searchNext(char letter);
    void addLetter(trieNode * node);

};



trieNode::trieNode(char _data)
{
    data = _data;
    for(int i = 0; i<26; i++)
    {
        next[i] = nullptr;
    }
    
}

char trieNode::getData()
{
    return this->data;
}

void trieNode::setData(char _item)
{
    this->data = _item;
}

bool trieNode::getWordM()
{
    return wordM;
}

void trieNode::setWordM()
{
    wordM = true;
}

trieNode * trieNode::searchNext(char letter)
{
    trieNode* tmp;
    for(int i = 0; i < next.size(); i++)
    {
        tmp = next.at(i);
        if (letter  == tmp->getData())
        {
            return tmp;
        }
    }
    return NULL;
}

void trieNode::addLetter(trieNode *node)
{
    next.push_back(node);
}



