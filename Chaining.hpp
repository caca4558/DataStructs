#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTable
{
    int tableSize;

    node* *table;

    node* createNode(int key, node* next);
public:
    HashTable(int bsize);
    unsigned int hashFunction(int key);
    node* searchItem(int key);
    bool insertItem(int key);
    void deleteItem(int key);
    void printTable();
};

#endif
