//Dennis Huang
//dlh4fx
//CS 2150 Lab Section 102
//hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class hashTable {

 public: 

int tableSize;

  unsigned int hash(string key); //hash method

  int wordLength;

  int capacity;

  void loadArray();

  void loadDict(string fileName);

  hashTable(string fileName); //constructor, sets the hash table's length

  void insert(string key); //adds item to hash table


  bool retrieve(string key); //returns item from table with key, returns false pointer if item isn't found



  

 private:
  

  int array[22];

  //string *table;

  //unsigned int * prime;

  vector<list<string> > theTable;

};

#endif
