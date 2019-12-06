#include<iostream>
#include "cuckoo.hpp"

using namespace std;


node* createNode(int key){
  node* newNode = new node;
  newNode->key = key;
  return newNode;
}

HashTable::HashTable(int bsize){
  this->tableSize = bsize;
  table = new node*[tableSize];
  for(int i=0;i<bsize;i++)
      table[i] = nullptr;
}

HashTable::~HashTable(){

}
unsigned int HashTable::hash1(int key){
  return (key % tableSize);
}

unsigned int HashTable::hash2(int key){
  return (floor(key/tableSize)%tableSize);
}

node* searchItem(int key){
  int index1 = hash1(key);
  int index2 = hash2(key);
  if(table1[index1]->key == key){
    return table1[index1];
  }
  else{
    return table2[index2];
  }
}

void insertItem(int key){

}

void deleteItem(int key){
  int index1 = hash1(key);
  int index2 = hash2(key);
  if(table1[index1]->key == key){
    node temp = table1[index1];
    free(temp);
    table1[index1] = createNode(-1);
  }
  else{
    node temp = table2[index2];
    free(temp);
    table2[index2] = createNode(-1);
  }
}
