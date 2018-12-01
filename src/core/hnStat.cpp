#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>

#include <unordered_set>
#include <unordered_map>
#include <queue>

#include "../commands/SortedCollectionInterface.hpp"
#include "../commands/readTimestamp.hpp"
#include "../commands/binarySearch.hpp"
#include "../commands/TimeStampCollection.hpp"
#include "../commands/argumentParser.hpp"

void topQuery(std::ifstream &file,int timestamp , int to, int numberOfTopQueries) {

	std::unordered_map<std::string,int> distinctQueries;

	/// TODO : Ideally the map should be reserved to avoid realocation. So, add a clever way to reserve the container.	

	std::string buffer, link;

	///////////////////////////
	// Counting frequency
	///////////////////////////

	while (timestamp != to && !file.eof()) {

		std::getline (file,buffer);
		std::stringstream query(buffer);
		query >> timestamp >>  link;

		if(distinctQueries.find(link)==distinctQueries.end()){
			distinctQueries.insert(std::make_pair(link,1));
		} else {
			++distinctQueries[link];
		}
			
	}

	///////////////////////////
	// Filling Priority Queue
	///////////////////////////

	typedef std::pair<std::string,int> pair;

	auto cmp = [](pair left, pair right) { return (left.second) > (right.second);};
	std::priority_queue<pair, std::vector<pair>, decltype(cmp)> q(cmp);

	std::cout << distinctQueries.size() << "\n";    

	for (auto &query : distinctQueries) {
		q.push(query);	
		if(q.size()>numberOfTopQueries)	
			q.pop();
	}

	///////////////////////////
	// Print Priority Queue
	///////////////////////////

	std::vector<pair> pairs;

	while(!q.empty()) {
		pairs.push_back(q.top());
		q.pop();
	}

	while(!pairs.empty()) {
		auto &back =pairs.back();
		std::cout << back.second  << " : " << back.first << "\n";
		pairs.pop_back();
	}
}

void distinctQuery(std::ifstream &file,int timestamp , int to ) {

	std::unordered_set<std::string> distinctQueries;
	  
	std::string buffer, link;

	///////////////////////////
	// Add distinct queries
	///////////////////////////

	while (timestamp != to && !file.eof()) {

		std::getline (file,buffer);
		std::stringstream query(buffer);
		query >> timestamp >>  link;

		if(distinctQueries.find(link)==distinctQueries.end())
			distinctQueries.insert(link);
	}

	///////////////////////////
	// Print distinct queries
	///////////////////////////

	std::cout << distinctQueries.size() << "\n";    

	for (auto &query : distinctQueries) 
		std::cout << query << "\n";					
}

int main( int argc , char *argv[]){
	
	context cnt;

    if(argumentParser(argc,argv,cnt)){

			std::ifstream file( cnt.fileName , std::ifstream::binary );
			if (file)
			{

				///////////////////////////
				// Binary Search
				///////////////////////////

				TimeStampCollection ts(file);
				int position = binarySearch(cnt.from, &ts);
				
				///////////////////////////
				// Change File Strem position
				///////////////////////////

				file.seekg (position,  file.beg);
				int timestamp = 0;
				std::string buffer, link;

				///////////////////////////
				// Enter Distinct/Top block
				///////////////////////////

				// -1: not defined;
				//  1: top;
				//  2: distinct
				if (cnt.mode==1) {
			
					topQuery(file, timestamp , cnt.to, cnt.numberOfTopQueries);

				} else if (cnt.mode==2) {

					distinctQuery(file, timestamp,cnt.to);

				} else {
					return 1;	
				}

			} else {
				std::cout << "File couldn't be open";
			}
			
			file.close();

	} else {
		return 1;
	}

}


