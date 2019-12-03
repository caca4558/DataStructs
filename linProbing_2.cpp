#include<iostream>
#include "linProbing.hpp"


using namespace std;

node* HashTable::createNode(int key)
{
    node* nw = new node;
    nw->key = key;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

unsigned int HashTable::hashFunction(int key)
{
    return (floor(key/tableSize)%tableSize);
}

void HashTable::deleteItem(int key){
  int index = hashFunction(key);
  node* temp = table[index];
  delete(temp);
}

node* HashTable::searchItem(int key)
{
    int index = hashFunction(key);
    return table[index];
}

bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        int index = hashFunction(key);
        table[index] = createNode(key,table[index]);
        return true;
     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }
}
