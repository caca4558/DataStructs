#ifndef BST_HPP
#define BST_HPP

#include <string>

struct node
{
    int key;
    node* left = NULL;
    node* right = NULL;
};

class HashTable
{
    int tableSize;

    node* *table;

    node* createNode(int key);
public:
    HashTable(int bsize);
    ~HashTable();
    unsigned int hashFunction(int key);
    node* searchItem(int key);
    void insertItem(int key);
    void deleteItem(int key);
};

#endif
