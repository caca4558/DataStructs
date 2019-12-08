#include<iostream>
#include "bst.hpp"

using namespace std;


node* getMinValueNode(node* currNode){

    if(currNode->left == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->left);
}


node* deleteItemHelper(node* currNode, int key){
  if(currNode == NULL)
  {
    return NULL;
  }
  else if(key < currNode->key)
  {
    currNode->left = deleteItemHelper(currNode->left, key);
  }
  else if(key > currNode->key)
  {
    currNode->right = deleteItemHelper(currNode->right, key);
  }
  else{
    //TODO Case : No child
    if(currNode->left == NULL && currNode->right == NULL)
    {
        return NULL;
    }
    //TODO Case : Only right child
    else if(currNode->left == NULL)
    {
      node *temp = currNode->right;
      free(currNode);
      return temp;
    }
    //TODO Case : Only left child
    else if(currNode->right == NULL)
    {
      node *temp = currNode->left;
      free(currNode);
      return temp;
    }
    //TODO Case: Both left and right child
    else
    {
      ///Replace with Minimum from right subtree
      node* temp = getMinValueNode(currNode->right);
      currNode->key = temp->key;
      currNode->right = deleteItemHelper(currNode->right, temp->key);
    }
  }
}

node* searchHelper(node* currNode, int key){
  if(currNode){
    if(currNode->key == key){
      return currNode;
    }
    searchHelper(currNode->left, key);
    searchHelper(currNode->right, key);
  }
  return NULL;
}

node* createNode(int key){
  node* newNode = new node;
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

node* insertHelper(node* currNode, int key){
  if(currNode == NULL){
    return createNode(key);
  }
  else if(currNode->key > key){
    insertHelper(currNode->left, key);
  }
  else if(currNode->key < key){
    insertHelper(currNode->right, key);
  }
  return currNode;
}

HashTable::HashTable(int bsize){
  this->tableSize = bsize;
  table = new node*[tableSize];
  for(int i=0;i<bsize;i++)
      table[i] = nullptr;
}


unsigned int HashTable::hashFunction(int key){
  return (key % tableSize);
}

node* HashTable::searchItem(int key){
  int index = hashFunction(key);
  node* giveBack = searchHelper(table[index], key);
  return giveBack;
}
bool HashTable::insertItem(int key){
  if(searchItem(key) == NULL){
    int index = hashFunction(key);
    node* root = table[index];
    table[index] = insertHelper(root, key);
    return true;
  }
  else{
    return false;
  }

}

void HashTable::deleteItem(int key){
  int index = hashFunction(key);
  deleteItemHelper(table[index], key);
}
