#include<iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Chaining.hpp"
//#include "bst.hpp"*/
//#include "linProbing.hpp"
using namespace std;

float stdCalc(vector<float> nums)
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

float meanCalc(vector<float> nums)
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
    ifstream table (fileName);
    while (getline(table, temp)){
      istringstream iss(temp);
      string t2;
      while(getline(iss, t2, ','))
      {
        numbers.push_back(stoi(t2));
      }
    }
    index=0;
    while(llcount/10009 < 0.1)
    {
        if(ht.insertItem(numbers[index]) == true)
        {
          llcount++;
        }
        index++;
    }
    cout << "idk";
    float startTime, endTime;
    float execTimedel;
    int i = 0;
    startTime = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.deleteItem(numbers[randNum]);
      i++;
    }
    endTime = clock();
    execTimedel = (endTime-startTime)/CLOCKS_PER_SEC;
    cout << "lol" << endl;
    float startTime1, endTime1;
    float execTimesearch;
    i = 0;
    startTime1 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.searchItem(numbers[randNum]);
      i++;
    }
    endTime1 = clock();
    execTimesearch = (endTime1-startTime1)/CLOCKS_PER_SEC;
    cout << "lol1" << endl;
    float startTime2, endTime2;
    float execTimeinsert;
    i = 0;
    startTime2 = clock();
    while(i < 100)
    {
      if(ht.insertItem(numbers[index]) == true)
      {
        llcount++;
      }
      index++;
      i++;
    }
    endTime2 = clock();
    execTimeinsert = (endTime2-startTime2)/CLOCKS_PER_SEC;
    cout << "Load Factor: " << llcount/10009 << endl;
    cout << "Delete- mean: " << execTimedel/100.000 << endl;
    cout << "Search- mean: " << execTimesearch/100.000 << endl;
    cout << "Insert- mean: " << execTimeinsert/100.000 << endl;
    return 0;
}
