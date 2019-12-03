#include<iostream>
#include "bst.hpp"

using namespace std;



node* createNode(int key){
  node* newNode = new Node;
  newNode->key = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

node* insertHelper(node* currNode, int key){

}

HashTable(int bsize){

}
~hashTable(){

}
unsigned int HashTable::hashFunction(int key){
  return (key % tableSize);
}
node* HashTable::searchItem(int key){

}
bool HashTable::insertItem(int key){
  int index = hashFunction(key);
  


}
void HashTable::deleteItem(int key){

}
