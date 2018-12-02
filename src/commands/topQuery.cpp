
#include "topQuery.hpp"

#include <unordered_map>
#include <queue>
#include <iostream>
#include <vector>
#include <sstream>

void topQuery(std::istream &file, int timestamp, int to, int numberOfTopQueries)
{

	std::unordered_map<std::string, int> distinctQueries;

	/// TODO : Ideally the map should be reserved to avoid realocation. So, add a clever way to reserve the container.

	std::string buffer, link;

	///////////////////////////
	// Counting frequency
	///////////////////////////

	std::getline(file, buffer); // Jump first line
	
	
	while (timestamp <= to && !file.eof())
	{

		std::getline(file, buffer);
		std::stringstream query(buffer);
		query >> timestamp >> link;

		if (distinctQueries.find(link) == distinctQueries.end())
		{
			distinctQueries.insert(std::make_pair(link, 1));
		}
		else
		{
			++distinctQueries[link];
		}
	}

	///////////////////////////
	// Filling Priority Queue
	///////////////////////////

	typedef std::pair<std::string, int> pair;

	auto cmp = [](pair left, pair right) { return (left.second) > (right.second); };
	std::priority_queue<pair, std::vector<pair>, decltype(cmp)> q(cmp);

	std::cout << distinctQueries.size() << "\n";

	for (auto &query : distinctQueries)
	{
		q.push(query);
		if (q.size() > numberOfTopQueries)
			q.pop();
	}

	///////////////////////////
	// Print Priority Queue
	///////////////////////////

	std::vector<pair> pairs;

	while (!q.empty())
	{
		pairs.push_back(q.top());
		q.pop();
	}

	while (!pairs.empty())
	{
		auto &back = pairs.back();
		std::cout << back.first << " " << back.second << "\n";
		pairs.pop_back();
	}
}