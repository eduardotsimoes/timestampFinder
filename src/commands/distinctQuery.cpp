
#include "distinctQuery.hpp"

#include <unordered_set>
#include <queue>
#include <iostream>
#include <vector>
#include <sstream>

void distinctQuery(std::istream &file, int timestamp, int to)
{

	std::unordered_set<std::string> distinctQueries;

	std::string buffer, link;

	///////////////////////////
	// Add distinct queries
	///////////////////////////
	std::getline(file, buffer); // Jump first line

	while (timestamp <= to && !file.eof())
	{

		std::getline(file, buffer);
		std::stringstream query(buffer);
		std::cout<< buffer << std::endl ;
		query >> timestamp >> link;

		if (distinctQueries.find(link) == distinctQueries.end())
			distinctQueries.insert(link);
	}

	///////////////////////////
	// Print distinct queries
	///////////////////////////

	std::cout << distinctQueries.size() << "\n";

	for (auto &query : distinctQueries)
		std::cout << query << "\n";
}