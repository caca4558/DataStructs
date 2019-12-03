#ifndef HASH_HPP
#define HASH_HPP

#include <string>

struct node
{
    int key;
};

class HashTable
{
    int tableSize;

    node* *table;

    node* createNode(int key);
public:
    HashTable(int bsize);
    ~hashDestructor();
    unsigned int hashFunction(int key);
    node* searchItem(int key);
    bool insertItem(int key);
    void deleteItem(int key);
};

#endif
