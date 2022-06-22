#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "SensorCluster.hpp"
 
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

/* function to convert a character into its digit; 'A' converts into 10; 'B' into 11, etc.
*/
unsigned int hexa_to_number(char ch) {
    unsigned int temp = 0;
    temp = ch;
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
  // TODO: implement this function, then delete the return statement below
  return hexa_to_number(nic[0]); 
}

// function to return the hash value based on the second digit
unsigned int hashfct2(string nic) {
  // TODO: implement this function, then delete the return statement below
  return hexa_to_number(nic[1]);  
}

// function to return the hash value based on the third digit
unsigned int hashfct3(string nic) {
   // TODO: implement this function, then delete the return statement below
  return hexa_to_number(nic[2]);
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(string nic) {
   // TODO: implement this function, then delete the return statement below
  return hexa_to_number(nic[3]);
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(string nic) {
    // TODO: implement this function, then delete the return statement below
  return hexa_to_number(nic[4]);
}

// function to return the hash value based on the sixth digit
unsigned int hashfct6(string nic) {
    // TODO: implement this function, then delete the return statement below
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
  // TO DO: implement this function, then delete the return statement below
  
   return;
}

// function that removes the sensor specified by the nic value from the network
// if sensor is found, then it is removed and the function returns true
// else returns false
bool SensorNIC::removeItem(string nic) {
   // TODO: implement this function, then delete the return statement below   
    return false;
}

// function that decides the best hash function, i.e. the ones among
// fct1-fct6 that creates the most balanced sensor network for the current
// set of NIC addresses, i.e. data member allItems

// Hints:
// Calculate the balance of each hashtable, one by one.
unsigned int SensorNIC::bestHashing() {
  // TODO: implement this function, then delete the return statement below
    
  
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance
    
    return 100;
}

// ALREADY COMPLETED
size_t SensorNIC::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) )
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
