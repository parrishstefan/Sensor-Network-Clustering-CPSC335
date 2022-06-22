#pragma once
#include <string>
#include <unordered_map>
using std::string;
 
//******************************
// Struct and classes
//******************************

// struct to store all the info about a particular NIC
struct Item{
  string itemName_;
  string nic_;
  Item(string itemName="", string nic="100000");
};

// TO BE COMPLETED: unary function to return the hash value based on
// the first digit of some unique 6-character key
unsigned int hashfct1(string);

// TO BE COMPLETED: unary function to return the hash value based on
// the second digit of some unique 6-character key
unsigned int hashfct2(string);

// TO BE COMPLETED: unary function to return the hash value based on
// the third digit of some unique 6-character key
unsigned int hashfct3(string);

// TO BE COMPLETED: unary function to return the hash value based on
// the fourth digit of some unique 6-character key
unsigned int hashfct4(string);

// TO BE COMPLETED: unary function to return the hash value based on
// the fifth digit of some unique 6-character key
unsigned int hashfct5(string);

// TO BE COMPLETED: unary function to return the hash value based on
// the sixth digit of some unique 6-character key
unsigned int hashfct6(string);

//******************************
// Typedef for custom hash table
//******************************
typedef std::unordered_map<string, Item, decltype(&hashfct1)> CustomHashTable;


// class to store the NICs
class SensorNIC {
public:
  // function that adds the specified NIC to the sensor network. TO BE COMPLETED
  void addItem(string itemName, string nic);

  // removes a specified NIC from the sensor network; if successful,
  // then it returns true; TO BE COMPLETED
  bool removeItem(string nic);

  // identifies which hash function (among the six provided, fct1 - fct6)
  // computes the most balanced hash table; TO BE COMPLETED
  unsigned int bestHashing();

  // Load information from a text file
  // with the given filename; THIS FUNCTION IS COMPLETE
  void readTextfile(string filename);

  // size of a hashtable. Throws exception if the sizes differ. Completed
  size_t size();

  // constructor that initializes six hashtables with different hash functions
  SensorNIC():
    hT1{16,hashfct1},
    hT2{16,hashfct2},
    hT3{16,hashfct3},
    hT4{16,hashfct4},
    hT5{16,hashfct5},
    hT6{16,hashfct6}{ }

private:
  CustomHashTable hT1, hT2, hT3, hT4, hT5, hT6;
  // add other private member variables as needed
};
