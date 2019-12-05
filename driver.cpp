#include<iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
/*#include "Chaining.hpp"
#include "bst.hpp"*/
#include "linProbing.hpp"
using namespace std;

float stdCalc(vector<int> nums)
{
  float sum = 0.0;
  float mean;
  float standardDeviation = 0.0;
  int i;
  for(i = 0; i < nums.size(); ++i)
  {
        sum += nums[i];
  }
  mean = sum/nums.size();
  for(i = 0; i < nums.size(); ++i)
      standardDeviation += pow(nums[i] - mean, 2);
  return sqrt(standardDeviation / nums.size());
}

float meanCalc(vector<int> nums)
{
  float sum = 0.0;
  float mean;
  int i;
  for(i = 0; i < nums.size(); ++i)
  {
        sum += nums[i];
  }
  mean = sum/nums.size();
  return mean;
}

int main(int argc, char* argv[])
{
    string fileName = argv[1];
    string temp;
    string choice;
    vector <int> numbers;
    string t;
    string type;
    float llcount = 0;
    float bstcount = 0;
    float coocount = 0;
    float lpcount = 0;
    int index;
    HashTable ht(10009);
    vector<int> nums;
    float lptestmean;
    float lpteststd;
    ifstream table (fileName);
    cout << "Please choose the collision resolution method:" << endl;
    cout << "1. Chaining with a linked list" << endl;
    cout << "2. Chaining with a BST" << endl;
    cout << "3. Linear Probing" << endl;
    cout << "4. Cuckoo Hashing" << endl;
    getline(cin,type);
    switch(stoi(type))
    {
      case 1:
        //HashTable ht(10009);
        /*cout<< "Contents of the hash table are"<<endl;
        ht.printTable();
        cout<<endl;*/
        while (getline(table, temp)){
          istringstream iss(temp);
          string t;
          while(getline(iss, t, ','))
          {
            numbers.push_back(stoi(t));
          }
        }
        /*int index=0;
        while(llcount/10009 < 0.1)
        {
          ht.insertItem()
        }*/
        cout << "Load Factor: " << llcount/10009 << endl;
        cout << "Delete- mean: " << " standard dev: " << endl;
        cout << "Insert- mean: " << " standard dev: " << endl;
        cout << "Search- mean: " << " standard dev: " << endl;
        break;
      case 2:
        //HashTable ht(10009);
        /*cout<< "Contents of the hash table are"<<endl;
        ht.printTable();
        cout<<endl;*/
        while (getline(table, temp)){
          istringstream iss(temp);
          string t1;
          while(getline(iss, t1, ','))
          {
            numbers.push_back(stoi(t1));
          }
        }
        cout << "Load Factor: " << bstcount/10009 << endl;
        cout << "Delete- mean: " << " standard dev: " << endl;
        cout << "Insert- mean: " << " standard dev: " << endl;
        cout << "Search- mean: " << " standard dev: " << endl;
        break;
      case 3:
        /*cout<< "Contents of the hash table are"<<endl;
        ht.printTable();
        cout<<endl;*/
        while (getline(table, temp)){
          istringstream iss(temp);
          string t2;
          while(getline(iss, t2, ','))
          {
            numbers.push_back(stoi(t2));
          }
        }
        index=0;
        while(lpcount/10009 < 0.1)
        {
            ht.insertItem(numbers[index]);
            index++;
            lpcount++;
        }
        cout << "point 1" << endl;
        for(int i = 0; i < 100; i++)
        {
          int startTime, endTime;
          double execTime;
          int randNum = rand() % (int)lpcount;
          startTime = clock();
          ht.deleteItem(numbers[randNum]);
          endTime = clock();
          execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
          nums.push_back(execTime);
        }
        cout << "point 2" << endl;
        lptestmean = meanCalc(nums);
        lpteststd = stdCalc(nums);
        cout << "Load Factor: " << lpcount/10009 << endl;
        cout << "Delete- mean: " << lptestmean << " standard dev: " << lpteststd << endl;
        cout << "Insert- mean: " << " standard dev: " << endl;
        cout << "Search- mean: " << " standard dev: " << endl;
        break;
      case 4:
        //HashTable ht(10009);
        /*cout<< "Contents of the hash table are"<<endl;
        ht.printTable();
        cout<<endl;*/
        while (getline(table, temp)){
          istringstream iss(temp);
          string t3;
          while(getline(iss, t3, ','))
          {
            numbers.push_back(stoi(t3));
          }
        }

        cout << "Load Factor: " << coocount/10009 << endl;
        cout << "Delete- mean: " << " standard dev: " << endl;
        cout << "Insert- mean: " << " standard dev: " << endl;
        cout << "Search- mean: " << " standard dev: " << endl;
        break;
      default:
        cout << "Not Valid" << endl;
    }
    return 0;
}
