#ifndef CUCKOO_HPP
#define CUCKOO_HPP

#include <string>

using namespace std;

struct node
{
    int key;
};

class HashTable
{
    int tableSize;

    node* *table1;
    node* *table2;

    node* createNode(int key);
public:
    HashTable(int bsize);
    ~HashTable();
    unsigned int hash1(int key);
    unsigned int hash2(int key);
    node* searchItem(int key);
    void insertItem(int key);
    void deleteItem(int key);
};

#endif
