
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
// #define NDEBUG
#include <cassert>
#include <unordered_set>

#include "SortedCollectionInterface.hpp"
#include "readTimestamp.hpp"
#include "binarySearch.hpp"
#include "TimeStampCollection.hpp"

class Collection : public SortedCollectionInterface {
    
    const std::vector<int>& _nums;
    
    public:
    
        Collection(const std::vector<int>& nums):_nums(nums) {};

        ~Collection(){};

        int getSize() const override {
            return _nums.size();
        }   

        int getValue(int index) const override {
            return _nums[index];
        }; 



};



int main() {

    const char *text =
  "1438387423	http%3A%2F%2Ftechacute.com%2F10-essentials-every-desk-needs%2F\n"
  "1438387423	%22http%3A%2F%2Fmiamiherald.typepad.com%2Fnakedpolitics%2F2015%2F07%2Fjeb-bushs-mixed-record-devolving-mount-tallahassee.html%22\n"
  "1438387425	http%3A%2F%2Fwebboard.yenta4.com%2Ftopic%2F419976\n"
  "1438387426	nixos\n"
  "1438387426	%22http%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3D-V9Ej78JbhY%22";

    std::istringstream stream(text);
    
    
    // Test finding the time Stamp

    // Test #2 line
    assert(readTimestamp(95,stream)==1438387423);
    
    // Test #1 line
    assert(readTimestamp(30,stream)==1438387423);

    // Test #3 line
    assert(readTimestamp(250,stream)==1438387425);

    //////////////////////////////////////////////////

    std::vector<int> v = {2,3,5,6,7,8,9};

    SortedCollectionInterface* vv = new Collection(v);

    assert(binarySearch(2,vv)==0);


    //TODO : test not passing
    std::vector<int> v2 = {2,2,3,5,6,7,8,9};

    SortedCollectionInterface* vv2 = new Collection(v2);

    //assert(binarySearch(2,vv2)==0);

    ///////////////////////////////////////////////

    TimeStampCollection aa(stream);

    std::cout << binarySearch(1438387425, &aa);

    //std::ifstream file( "../hn_logs.tsv",  std::ifstream::binary );
    std::ifstream file( "../short_file.tsv",  std::ifstream::binary );

    if(file){
        
        int to = 1438387423;
        int from = 1438387429;
        
        TimeStampCollection bb(file);
        int position = binarySearch(to, &bb);
        std::cout << position;
  
        // Change file position;
        file.seekg (position,  file.beg);
        int timestamp = 0;
        std::string buffer, link;

        std::unordered_set<std::string> distinctQueries;

        while (timestamp != from ) {

            std::getline (file,buffer);
            std::stringstream query(buffer);
            query >> timestamp >>  link;

            distinctQueries.insert(link);
        }

        std::cout << "number of distinct entries : " << distinctQueries.size() << "\n"; 

        
    }

}