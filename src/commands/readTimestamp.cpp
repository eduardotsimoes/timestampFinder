
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
// #define NDEBUG
#include <cassert>

int readTimestamp(int index, std::istream &stream ){
	
        //@TODO: add a buffer to the reverse reading.
        stream.seekg (index, stream.beg);
        char ch=stream.get();    
	
	while( index > 0 ) {
		
                stream.seekg(--index,stream.beg);
                ch=stream.get();
                        
                //std::cout << " postion : " << index << " char :  " << ch << "\n";

                if(ch=='\n'){
                        ++index;
                        break;
                }

	}
    
        // parse the time stamp 
        stream.seekg(index,stream.beg);
        int timeStamp; 
        stream>> timeStamp;
        //std::cout << " timestamp : " << timeStamp << "\n";			
        return timeStamp;
}