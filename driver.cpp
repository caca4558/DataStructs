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
    cout << lpcount << endl;
    cout << ht.searchItem(22141995)->key << endl;
    int i = 0;
    while(i < 100)
    {
      double startTime, endTime;
      double execTime;
      startTime = clock();
      int randNum = rand() % (int)lpcount;
      cout << randNum << endl;
      ht.deleteItem(numbers[randNum]);
      endTime = clock();
      execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
      cout << "execution time: " << execTime << endl;
      cout << i << endl;
      i++;
    }

    lptestmean = meanCalc(nums);
    lpteststd = stdCalc(nums);
    cout << "Load Factor: " << lpcount/10009 << endl;
    cout << "Delete- mean: " << lptestmean << " standard dev: " << lpteststd << endl;
    cout << "Insert- mean: " << " standard dev: " << endl;
    cout << "Search- mean: " << " standard dev: " << endl;
    return 0;
}
