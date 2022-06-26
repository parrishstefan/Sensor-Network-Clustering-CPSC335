#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "SensorCluster.hpp"
#include <climits>
 
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

/* function to convert a character into its digit; 'A' converts into 10; 'B' into 11, etc.
*/
unsigned int hexa_to_number(char ch) {
    unsigned int temp = 0;
    temp = ch;
    // Uses ASCII math to convert to HEX
    if(temp >=48 && temp <=57)
        temp = temp - 48;
    else if(temp >=65 && temp <=70)
        temp = temp - 55;
    else if(temp >=97 && temp <=102)
        temp = temp - 87;
    else {
        return 0;
    }

    return temp;
}
    

// function to return the hash value based on the first digit
unsigned int hashfct1(string nic) {
  return hexa_to_number(nic[0]); 
}

// function to return the hash value based on the second digit
unsigned int hashfct2(string nic) {
  return hexa_to_number(nic[1]);  
}

// function to return the hash value based on the third digit
unsigned int hashfct3(string nic) {
  return hexa_to_number(nic[2]);
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(string nic) {
  return hexa_to_number(nic[3]);
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(string nic) {
  return hexa_to_number(nic[4]);
}

// function to return the hash value based on the sixth digit
unsigned int hashfct6(string nic) {
  return hexa_to_number(nic[5]);
}

// Constructor for struct Item
Item::Item(string itemName, string nic):itemName_(itemName), nic_(nic)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void SensorNIC::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemName;
    string nic;
    while (myfile >> itemName >> nic) {
			if (itemName.size() > 0)
      	addItem(itemName, nic);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

// function that adds the specified NIC to the sensor network (i.e., to all hash tables)
void SensorNIC::addItem(string itemName, string nic) {
  // Adds the item and key to each network
  hT1.emplace(nic, Item(itemName, nic));
  hT2.emplace(nic, Item(itemName, nic));
  hT3.emplace(nic, Item(itemName, nic));
  hT4.emplace(nic, Item(itemName, nic));
  hT5.emplace(nic, Item(itemName, nic));
  hT6.emplace(nic, Item(itemName, nic));

}

// function that removes the sensor specified by the nic value from the network
// if sensor is found, then it is removed and the function returns true
// else returns false
bool SensorNIC::removeItem(string nic) {
   // Checks if the item was in the networks
   // only need to call this once since the hash is added to all hash functions
   bool erased = hT1.erase(nic) == 1 ? true:false;
   hT2.erase(nic);
   hT3.erase(nic);
   hT4.erase(nic);
   hT5.erase(nic);
   hT6.erase(nic);

  return erased;
}

// function that decides the best hash function, i.e. the ones among
// fct1-fct6 that creates the most balanced sensor network for the current
// set of NIC addresses, i.e. data member allItems

// Hints:
// Calculate the balance of each hashtable, one by one.
unsigned int SensorNIC::bestHashing() {
  unsigned int lowestSize = UINT_MAX; // comparing variable initialized to the max size of unsigned in
  unsigned int highestSize = 0;       // comparing variable initialized to the max size of unsigned in
  int tableIndex;                     // table that has the best balance
  int bestBalance;                    // value of the best balance
  int tempBalance;                    // comparison for best balance


  for (unsigned i = 0; i < 0x10; i++) {
    // if current bucket size is less than the lowest size
    // replace lowest size
    if (lowestSize > hT1.bucket_size(i)) {
      lowestSize = hT1.bucket_size(i);
    }
    // if current bucket size is greater than the highest size
    // replace highest size
    if (highestSize < hT1.bucket_size(i)) {
      highestSize = hT1.bucket_size(i);
    }
  }
  // initially sets the first to best balance since there is nothing to compare to
  bestBalance = highestSize - lowestSize;
  // sets the table to hT1 since it is currently the best balance table
  tableIndex = 1;
///////////////////////
  // reset the highest/lowest sizes for comparing the next table
  highestSize = 0;
  lowestSize = 99999;
  for (unsigned i = 0; i < 0x10; i++) {
    if (lowestSize > hT2.bucket_size(i)) {
      lowestSize = hT2.bucket_size(i);
    }
    if (highestSize < hT2.bucket_size(i)) {
      highestSize = hT2.bucket_size(i);
    }
  }
  tempBalance = highestSize - lowestSize;
  // checks if current balance is greater than the comparing table
  // if it is, replace best balance and change table index to current table
  if (tempBalance < bestBalance) {
    bestBalance = tempBalance;
    tableIndex = 2;
  }
/////////////////////////////
  highestSize = 0;
  lowestSize = 99999;
  for (unsigned i = 0; i < 0x10; i++) {
    if (lowestSize > hT3.bucket_size(i)) {
      lowestSize = hT3.bucket_size(i);
    }
    if (highestSize < hT3.bucket_size(i)) {
      highestSize = hT3.bucket_size(i);
    }
  }
  tempBalance = highestSize - lowestSize;
  if (tempBalance < bestBalance) {
    bestBalance = tempBalance;
    tableIndex = 3;
  }
/////////////////////////////
  highestSize = 0;
  lowestSize = 99999;
  for (unsigned i = 0; i < 0x10; i++) {
    if (lowestSize > hT4.bucket_size(i)) {
      lowestSize = hT4.bucket_size(i);
    }
    if (highestSize < hT4.bucket_size(i)) {
      highestSize = hT4.bucket_size(i);
    }
  }
  tempBalance = highestSize - lowestSize;
  if (tempBalance < bestBalance) {
    bestBalance = tempBalance;
    tableIndex = 4;
  }
/////////////////////////////
  highestSize = 0;
  lowestSize = 99999;
  for (unsigned i = 0; i < 0x10; i++) {
    if (lowestSize > hT5.bucket_size(i)) {
      lowestSize = hT5.bucket_size(i);
    }
    if (highestSize < hT5.bucket_size(i)) {
      highestSize = hT5.bucket_size(i);
    }
  }
  tempBalance = highestSize - lowestSize;
  if (tempBalance < bestBalance) {
    bestBalance = tempBalance;
    tableIndex = 5;
  }
/////////////////////////////
  highestSize = 0;
  lowestSize = 99999;
  for (unsigned i = 0; i < 0x10; i++) {
    if (lowestSize > hT6.bucket_size(i)) {
      lowestSize = hT6.bucket_size(i);
    }
    if (highestSize < hT6.bucket_size(i)) {
      highestSize = hT6.bucket_size(i);
    }
  }
  tempBalance = highestSize - lowestSize;
  if (tempBalance < bestBalance) {
    bestBalance = tempBalance;
    tableIndex = 6;
  }

  //returns the table index with the best balance
  return tableIndex;
}

// ALREADY COMPLETED
size_t SensorNIC::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) )
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
