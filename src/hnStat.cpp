#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>

#include <unordered_set>
#include <unordered_map>
#include <queue>


#include "SortedCollectionInterface.hpp"
#include "readTimestamp.hpp"
#include "binarySearch.hpp"
#include "TimeStampCollection.hpp"


template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

int main( int argc , char *argv[]){
	

	for (int i=0; i < argc ; ++i){
		
		std::cout<< "i: "<< i << " argv: " << argv[i] << "\n";
	}
	std::cout << "\n\n";

	// Check mode of analysys :
	// 1 - distinct : list the distinct queries
	// 2 - top : list the frequency of the top queries	
	
	std::string mode;
	
	std::stringstream modeStream(argv[1]);
        modeStream >> mode;

	
	if(mode=="distinct"){
		std::cout << "distinct mode \n";

		if(argc < 6){
			std::cout << "Number of arguments  smaller than the minimum. Arugments : " << argc << ".\n"; 
			return 1;
		}
	
		int from, to;
		std::string fileName;
		
		// read the timestamp from	
		modeStream.clear();             
		modeStream.str(argv[3]);
        	modeStream >> from;
		
		// read the timestamp to
		modeStream.clear();
		modeStream.str(argv[5]);
		modeStream >> to;			
		
		// read the the file name	
		modeStream.clear();
		modeStream.str(argv[6]);
		modeStream >> fileName;			
		std::cout << "from : " << from <<" to: " << to << " filename: " << fileName <<  "\n";
		
		std::ifstream file( fileName , std::ifstream::binary );
		if (file)
		{

			TimeStampCollection ts(file);
			int position = binarySearch(to, &ts);

			// Change file position;
			file.seekg (position,  file.beg);
			int timestamp = 0;
			std::string buffer, link;

			std::unordered_set<std::string> distinctQueries;
			
			std::cout << "=== Loading entries ==" << "\n";    

			
			while (timestamp != from ) {

				std::getline (file,buffer);
				std::stringstream query(buffer);
				query >> timestamp >>  link;

				if(distinctQueries.find(link)==distinctQueries.end())
					distinctQueries.insert(link);
			}

			std::cout << distinctQueries.size() << "\n";    

			for (auto &query : distinctQueries) 
				std::cout << query << "\n";

		}

	
        file.close();

	} else if ( mode=="top") {

		std::cout << " top mode \n";
	
		if(argc < 7){
			std::cout << "Number of arguments  smaller than the minimum. Arugments : " << argc << ".\n"; 
			return 1;
		}
	
   	        int from, to, numberOfQueries;
		std::string fileName;
		
		// read the number ot top entries from	
		modeStream.clear();             
		modeStream.str(argv[2]);
        	modeStream >> numberOfQueries;
	
		// read the timestamp from	
		modeStream.clear();             
		modeStream.str(argv[4]);
        	modeStream >> from;
		
		// read the timestamp to
		modeStream.clear();
		modeStream.str(argv[6]);
		modeStream >> to;			
		
		// read the the file name	
		modeStream.clear();
		modeStream.str(argv[7]);
		modeStream >> fileName;			
		std::cout << " number of queries "<< numberOfQueries <<" from : " << from <<" to: " << to << " filename: " << fileName <<  "\n";
		
		std::ifstream file( fileName );
		if (file)
		{
			TimeStampCollection ts(file);
			int position = binarySearch(to, &ts);

			// Change file position;
			file.seekg (position,  file.beg);
			int timestamp = 0;
			std::string buffer, link;

			std::unordered_map<std::string,int> distinctQueries;
			
			std::cout << "=== Loading entries ==" << "\n";    

			
			while (timestamp != from ) {

				std::getline (file,buffer);
				std::stringstream query(buffer);
				query >> timestamp >>  link;

				if(distinctQueries.find(link)==distinctQueries.end()){
					distinctQueries.insert(std::make_pair(link,1));
				} else {
					++distinctQueries[link];
				}
					
			}

			typedef std::pair<std::string,int> pair;

			auto cmp = [](pair left, pair right) { return (left.second) > (right.second);};
			std::priority_queue<pair, std::vector<pair>, decltype(cmp)> q(cmp);

			std::cout << distinctQueries.size() << "\n";    

			// O(m*log(numberOfQueries))
			for (auto &query : distinctQueries) {

				q.push(query);	
				if(q.size()>numberOfQueries)	
					q.pop();
						
			}

			std::vector<pair> pairs;

			while(!q.empty()) {
				//std::cout << q.top().second  << " : " << q.top().first << "\n";
				pairs.push_back(q.top());
				q.pop();
    		}

			while(!pairs.empty()) {
				auto &back =pairs.back();
				std::cout << back.second  << " : " << back.first << "\n";
				pairs.pop_back();
    		}



		}

		file.close();


	} else {
		std::cout << "[ERROR]: arguments not accepted\n";
		return 1;	
	}	


}


