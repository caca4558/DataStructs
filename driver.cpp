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
    while(llcount/10009 < 0.2)
    {
        if(ht.insertItem(numbers[index]) == true)
        {
          llcount++;
        }
        index++;
    }
    float startTime02, endTime02;
    float execTimedel02;
    i = 0;
    startTime02 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.deleteItem(numbers[randNum]);
      i++;
    }
    endTime02 = clock();
    execTimedel02 = (endTime02-startTime02)/CLOCKS_PER_SEC;
    float startTime102, endTime102;
    float execTimesearch02;
    i = 0;
    startTime102 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.searchItem(numbers[randNum]);
      i++;
    }
    endTime102 = clock();
    execTimesearch02 = (endTime102-startTime102)/CLOCKS_PER_SEC;
    float startTime202, endTime202;
    float execTimeinsert02;
    i = 0;
    startTime202 = clock();
    while(i < 100)
    {
      if(ht.insertItem(numbers[index]) == true)
      {
        llcount++;
      }
      index++;
      i++;
    }
    endTime202 = clock();
    execTimeinsert02 = (endTime202-startTime202)/CLOCKS_PER_SEC;
    cout << "Load Factor: " << llcount/10009 << endl;
    cout << "Delete- mean: " << execTimedel02/100.000 << endl;
    cout << "Search- mean: " << execTimesearch02/100.000 << endl;
    cout << "Insert- mean: " << execTimeinsert02/100.000 << endl;
    while(llcount/10009 < 0.5)
    {
        if(ht.insertItem(numbers[index]) == true)
        {
          llcount++;
        }
        index++;
    }
    float startTime05, endTime05;
    float execTimedel05;
    i = 0;
    startTime05 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.deleteItem(numbers[randNum]);
      i++;
    }
    endTime05 = clock();
    execTimedel05 = (endTime05-startTime05)/CLOCKS_PER_SEC;
    float startTime105, endTime105;
    float execTimesearch05;
    i = 0;
    startTime105 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.searchItem(numbers[randNum]);
      i++;
    }
    endTime105 = clock();
    execTimesearch05 = (endTime105-startTime105)/CLOCKS_PER_SEC;
    float startTime205, endTime205;
    float execTimeinsert05;
    i = 0;
    startTime205 = clock();
    while(i < 100)
    {
      if(ht.insertItem(numbers[index]) == true)
      {
        llcount++;
      }
      index++;
      i++;
    }
    endTime205 = clock();
    execTimeinsert05 = (endTime205-startTime205)/CLOCKS_PER_SEC;
    cout << "Load Factor: " << llcount/10009 << endl;
    cout << "Delete- mean: " << execTimedel05/100.000 << endl;
    cout << "Search- mean: " << execTimesearch05/100.000 << endl;
    cout << "Insert- mean: " << execTimeinsert05/100.000 << endl;
    while(llcount/10009 < 0.7)
    {
        if(ht.insertItem(numbers[index]) == true)
        {
          llcount++;
        }
        index++;
    }
    float startTime07, endTime07;
    float execTimedel07;
    i = 0;
    startTime07 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.deleteItem(numbers[randNum]);
      i++;
    }
    endTime07 = clock();
    execTimedel07 = (endTime07-startTime07)/CLOCKS_PER_SEC;
    float startTime107, endTime107;
    float execTimesearch07;
    i = 0;
    startTime107 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.searchItem(numbers[randNum]);
      i++;
    }
    endTime107 = clock();
    execTimesearch07 = (endTime107-startTime107)/CLOCKS_PER_SEC;
    float startTime207, endTime207;
    float execTimeinsert07;
    i = 0;
    startTime207 = clock();
    while(i < 100)
    {
      if(ht.insertItem(numbers[index]) == true)
      {
        llcount++;
      }
      index++;
      i++;
    }
    endTime207 = clock();
    execTimeinsert07 = (endTime207-startTime207)/CLOCKS_PER_SEC;
    cout << "Load Factor: " << llcount/10009 << endl;
    cout << "Delete- mean: " << execTimedel07/100.000 << endl;
    cout << "Search- mean: " << execTimesearch07/100.000 << endl;
    cout << "Insert- mean: " << execTimeinsert07/100.000 << endl;
    while(llcount/10009 < 0.9)
    {
        if(ht.insertItem(numbers[index]) == true)
        {
          llcount++;
        }
        index++;
    }
    float startTime09, endTime09;
    float execTimedel09;
    i = 0;
    startTime09 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.deleteItem(numbers[randNum]);
      i++;
    }
    endTime09 = clock();
    execTimedel09 = (endTime09-startTime09)/CLOCKS_PER_SEC;
    float startTime109, endTime109;
    float execTimesearch09;
    i = 0;
    startTime109 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.searchItem(numbers[randNum]);
      i++;
    }
    endTime109 = clock();
    execTimesearch09 = (endTime109-startTime109)/CLOCKS_PER_SEC;
    float startTime209, endTime209;
    float execTimeinsert09;
    i = 0;
    startTime209 = clock();
    while(i < 100)
    {
      if(ht.insertItem(numbers[index]) == true)
      {
        llcount++;
      }
      index++;
      i++;
    }
    endTime209 = clock();
    execTimeinsert09 = (endTime209-startTime209)/CLOCKS_PER_SEC;
    cout << "Load Factor: " << llcount/10009 << endl;
    cout << "Delete- mean: " << execTimedel09/100.000 << endl;
    cout << "Search- mean: " << execTimesearch09/100.000 << endl;
    cout << "Insert- mean: " << execTimeinsert09/100.000 << endl;
    while(llcount/10009 < 1)
    {
        if(ht.insertItem(numbers[index]) == true)
        {
          llcount++;
        }
        index++;
    }
    float startTime01, endTime01;
    float execTimedel01;
    i = 0;
    startTime01 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.deleteItem(numbers[randNum]);
      i++;
    }
    endTime01 = clock();
    execTimedel01 = (endTime01-startTime01)/CLOCKS_PER_SEC;
    float startTime101, endTime101;
    float execTimesearch01;
    i = 0;
    startTime101 = clock();
    while(i < 100)
    {
      int randNum = rand() % (int)llcount;
      ht.searchItem(numbers[randNum]);
      i++;
    }
    endTime101 = clock();
    execTimesearch01 = (endTime101-startTime101)/CLOCKS_PER_SEC;
    float startTime201, endTime201;
    float execTimeinsert01;
    i = 0;
    startTime201 = clock();
    while(i < 100)
    {
      if(ht.insertItem(numbers[index]) == true)
      {
        llcount++;
      }
      index++;
      i++;
    }
    endTime201 = clock();
    execTimeinsert01 = (endTime201-startTime201)/CLOCKS_PER_SEC;
    cout << "Load Factor: " << llcount/10009 << endl;
    cout << "Delete- mean: " << execTimedel01/100.000 << endl;
    cout << "Search- mean: " << execTimesearch01/100.000 << endl;
    cout << "Insert- mean: " << execTimeinsert01/100.000 << endl;
    return 0;
}
