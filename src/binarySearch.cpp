
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
// #define NDEBUG
//#include <cassert>

#include "binarySearch.hpp"

#include "SortedCollectionInterface.hpp"

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

int binarySearch(int target, SortedCollectionInterface* collection)
{
    // find the section with closest timestamp bigger or closep 

    // we think of floorIndex as leftmost edge of the possible positions
    // of our target and ceilingIndex as "wall" on the right of it
    int floorIndex = 0;
    int ceilingIndex = collection->getSize();

    std::cout <<  "floor index : " << floorIndex << " ceiling index : " << ceilingIndex << "\n";

    // find at least the closest 
    while (floorIndex < ceilingIndex) { // 

        // find the index ~halfway between the floor and ceiling
        // we use integer division, so we'll never get a "half index"
        int distance = ceilingIndex - floorIndex;
        int halfDistance = distance / 2;
        int guessIndex = floorIndex + halfDistance;
	
	// change the stream position
        int guessValue = collection->getValue(guessIndex);

        std::cout <<  "floor index : " << floorIndex << " ceiling index : " << ceilingIndex << " guess index : "<< guessIndex <<" guessValue: "<< guessValue <<"\n";


	// Compare the timestamps
        if (guessValue == target) {
            return guessIndex;
        }

        if (guessValue > target) {
            // target is to the left, so move ceiling to the left
            ceilingIndex = guessIndex;
        }
        else {
            // target is to the right, so move floor to the right
            floorIndex = guessIndex + 1;
        }
    }

    return ceilingIndex;
}


// int main(){

//     std::vector<int> v = {2,3,5,6,7,8,9};

//     SortedCollectionInterface* vv = new Collection(v);

//     if(binarySearch(1,vv)==0)
//         std::cout << "WPWP" ;

//     return 0;
// }