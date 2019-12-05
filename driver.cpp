#include<iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include "bst.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    string fileName = argv[1];
    string temp;
    string choice;
    vector <int> numbers;
    HashTable ht(10009);
    ifstream inFile(fileName);
    while (getline(inFile, temp)){
      istringstream iss(temp);
      string t;
      while(getline(iss, t, ','))
      {
        numbers.push_back(stoi(t));
      }
    }
    bool check = true;
    while(check)
    {
      int sum = 0;
      cout << "Please choose which operation to implement:" << endl;
      cout << "1. Insert" << endl;
      cout << "2. Lookup" << endl;
      cout << "3. Delete" << endl;
      cout << "4. Quit" << endl;
      getline(cin,choice);
      switch(stoi(choice))
      {
        case 1:
          for(int i = 0; i < 100; i++)
          {
            int startTime, endTime;
            double execTime;
            startTime = clock();
            /*
            EVALUATION CODE GOES HERE
            */
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            sum += execTime;
          }
          cout << sum/100 << endl;
          break;
        case 2:
          for(int i = 0; i < 100; i++)
          {
            int startTime, endTime;
            double execTime;
            startTime = clock();
            /*
            EVALUATION CODE GOES HERE
            */
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            sum += execTime;
          }
          cout << sum/100 << endl;
          break;
        case 3:
          for(int i = 0; i < 100; i++)
          {
            int startTime, endTime;
            double execTime;
            startTime = clock();
            /*
            EVALUATION CODE GOES HERE
            */
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            sum += execTime;
          }
          cout << sum/100 << endl;
          break;
        case 4:
          check = false;
          break;
        default:
          cout << "Not a valid choice" << endl;
      }
    }
    return 0;
}
