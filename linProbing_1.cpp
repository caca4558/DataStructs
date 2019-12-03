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
    return (key % tableSize);
}

node* HashTable::searchItem(int key)
{
    int count = 0;
    int index = hashFunction(key);
    while(count < table.size()){
      if(table[index]->key == key){
        return table[index];
      }
      else{
        if(index == table.size()){
          index = 0;
          count++;
        }
        else{
          index++;
          count++;
        }
      }
    }
    return NULL;
}

bool HashTable::insertItem(int key)
{
    int index = hashFunction(key);
    node* checker = table[index];
    if(table[index] == NULL){
      table[index] = createNode(key);
    }
    // if(searchItem(key) != NULL){
    //   return false;
    // }
    else{
      bool check = false;
      while(check == false){
        if(table[index] == NULL){
          table[index] = createNode(key);
          break;
        }
        else{
          if(index == table.size()){
            index = 0;
          }
          else{
            index++;
          }
        }
      }
    }
}

void HashTable::deleteItem(int key){
  node* temp;
  int index = hashFunction(key);
  while(true){
    if(table[index]->key == key){
      temp = table[index];
      table[index]->key = NULL;
      delete temp;
      break;
    }
    else{
      if(index == table.size){
        index = 0;
      }
      else{
        index++;
      }
    }
  }
}

