// CPP program to implement hashing with chaining
#include<iostream>
#include<cmath>
#include "Chaining.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

unsigned int HashTable::hashFunction(int key){
    unsigned int val = floor(key/tableSize);
    return (val%tableSize);
}

void HashTable::deleteItem(int key){
  int index = hashFunction(key);
  node* prev = table[index];
  node* temp = table[index];
  if(temp != nullptr && temp->key == key)
  {
    table[index] = temp->next;
    delete(temp);
    return;
  }
  while(temp != nullptr && temp->key != key)
  {
    prev = temp;
    temp = temp->next;
  }
  if(temp == nullptr)
  {
    return;
  }
  prev->next = temp->next;
  delete temp;
}

node* HashTable::searchItem(int key)
{
    int index = hashFunction(key);
    node* temp = table[index];
    while(temp != nullptr)
    {
      if(temp->key == key)
      {
        return temp;
      }
      temp = temp->next;
    }
    return nullptr;
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

void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<" - [ ";
        node* temp = table[i];
        while(temp != nullptr)
        {
          cout << temp->key << " ";
          temp = temp ->next;
        }
        cout << "]" << endl;
    }
 }

