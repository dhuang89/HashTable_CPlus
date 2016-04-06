//Dennis Huang
//dlh4fx 
//CS 2150 Lab Section 102
//hashTable.cpp

#include "hashTable.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

hashTable :: hashTable (string fileName) {
  int w = 0;
  ifstream file;
  string str;
file.open(fileName.c_str());
  while (!file.eof()) {
    getline(file, str);
    w++;
  }
  file.close();
  tableSize = (w*2) / 0.5;
  theTable.resize(tableSize);
 



}

void hashTable :: loadArray() {
  int x = 1;
  for (int i = 0; i < 22; i++) {
    array[i] = x;
    x = 37 * x;
  }
}

void hashTable :: loadDict(string fileName) {
  ifstream file;
  string str;


  file.open(fileName.c_str());
  while (!file.eof()) {
    getline(file, str);
    insert(str);
  }
  file.close();

}


unsigned int hashTable :: hash (string key) {
  unsigned int hashVal = 0;
  

  for (int i = 0; i < key.length(); i++) {
    hashVal = hashVal + (((int)key[i] - 97) * array[i]);
  
  
  }
  hashVal = hashVal % tableSize;
  return hashVal;
}

void hashTable :: insert(string key) {
  int value = hash(key);
  theTable[value].push_back(key);
  
  //cout << theTable[value].back() << endl;



  /*if (!(this -> retrieve(key))) {
    list<string> & theList = theTable -> at(hash(key));
    theList.push_back(key);

    if (key.length() > wordLength) {
      wordLength = key.length();
    }
    return true;
  }
  return false;*/



}



bool hashTable :: retrieve (string key) {
  int value = hash(key);
  if (theTable[value].size() == 0) {
    return false;
  }


  for (list<string> :: iterator it = theTable[value].begin(); it != theTable[value].end(); it++) {
    if (key == *it) {
      return true;
    }
    
  }
  return false;

  //list<string> & theList = theTable -> at(hash(key));
  //return (find(theList.begin(), theList.end(), key) != (theList.end()));
    }



