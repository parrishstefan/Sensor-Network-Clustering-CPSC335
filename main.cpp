#include <iomanip>
#include <iostream>
#include <cassert>
 
#include "rubrictest.hpp"
#include "SensorCluster.hpp"

int main() {
	
  Rubric rubric;
  
  // test hash functions
  rubric.criterion("hash function 1 on item 123456 returns 1", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct1(123456)", 1, hashfct1("123456") );
		   });
  
  rubric.criterion("hash function 2 on item 123456 returns 2", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct2(123456)", 2, hashfct2("123456") );
		   });
  
  rubric.criterion("hash function 3 on item 123456 returns 3", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct3(123456)", 3, hashfct3("123456") );
		   });
  
  rubric.criterion("hash function 4 on item 123456 returns 4", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct4(123456)", 4, hashfct4("123456") );
		   });
  
  rubric.criterion("hash function 5 on item 123456 returns 5", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct5(123456)", 5, hashfct5("123456") );
		   });
  
  rubric.criterion("hash function 6 on item 123456 returns 6", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct6(123456)", 6, hashfct6("123456") );
		   });
  
  rubric.criterion("hash function 1 on item 6789AB returns 6", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct1(678901)", 6, hashfct1("6789AB") );
		   });
  
  rubric.criterion("hash function 2 on item 6789AB returns 7", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct2(6789AB)", 7, hashfct2("6789AB") );
		   });
  
  rubric.criterion("hash function 3 on item 6789AB returns 8", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct3(6789AB)", 8, hashfct3("6789AB") );
		   });
  
  rubric.criterion("hash function 4 on item 6789AB returns 9", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct4(6789AB)", 9, hashfct4("6789AB") );
		   });
  
  rubric.criterion("hash function 5 on item 6789AB returns 10", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct5(6789AB)", 10, hashfct5("6789AB") );
		   });
  
  rubric.criterion("hash function 6 on item 6789AB returns 11", 1,
		   [&]() {
		     TEST_EQUAL( "hashfct6(6789AB)", 11, hashfct6("6789AB") );
		   });
  
  SensorNIC network1;
  network1.addItem("Velocity sensor", "123456");
  network1.addItem("Particle sensor", "234567");
  rubric.criterion("New network. Size is 2 after adding two NICs: Velocity sensor 123456 and Particle sensor 234567", 1,
		   [&]() {
      TEST_EQUAL( "size after adding two NICs", 2, network1.size() );
		   });

  SensorNIC network2;
  network2.readTextfile("in1.txt");
  rubric.criterion("New network. Size is 30 after reading in1.txt", 1,
		   [&]() {
      TEST_EQUAL( "size after reading in1.txt", 30, network2.size() );
           });
  
  rubric.criterion("BestHashing() for in1.txt returns 2", 1,
		   [&]() {
     TEST_EQUAL( "bestHashing() for in1.txt", 2, network2.bestHashing() );
		   });
  
  SensorNIC network3;
  network3.readTextfile("in2.txt");
  rubric.criterion("New network. Size is 37 after reading in2.txt", 1,
		   [&]() {
      	     TEST_EQUAL( "size after reading in2.txt", 37, network3.size());
		   });
  
  rubric.criterion("BestHashing() for in2.txt returns 2", 1,
                   [&]() {
      	     TEST_EQUAL( "bestHashing() for in2.txt", 2, network3.bestHashing());
                   });
  
  SensorNIC changed_network3;
  changed_network3.readTextfile("in2.txt");
  changed_network3.removeItem("110987");
  changed_network3.removeItem("210FED");
  rubric.criterion("New network then read in2.txt. Then remove two NICs: 110987 and 210FED. Size becomes 35", 1,
		   [&]() {
      TEST_EQUAL( "size after removing 110987 and 210FED", 35, changed_network3.size() );
		   });
  
  rubric.criterion("hash function 1", 1,
		   [&]() {
TEST_EQUAL( "BestHashing() for this network returns 3", 3, changed_network3.bestHashing() );
		   });
    
  return rubric.run();
}
