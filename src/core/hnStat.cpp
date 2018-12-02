#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "../commands/readTimestamp.hpp"
#include "../commands/binarySearch.hpp"
#include "../commands/TimeStampCollection.hpp"
#include "../commands/argumentParser.hpp"
#include "../commands/topQuery.hpp"
#include "../commands/distinctQuery.hpp"

int main(int argc, char *argv[])
{
	// This object keeps the information read from the arguments

	context cnt;

	std::cout << "Parse args" << std::endl;

	if (argumentParser(argc, argv, cnt))
	{

		std::ifstream file(cnt.fileName, std::ifstream::binary);
		if (file)
		{

			///////////////////////////
			// Binary Search
			///////////////////////////
			std::cout << "BS " << std::endl;
			TimeStampCollection ts(file);
			int position = binarySearch(cnt.from, &ts);
			std::cout << position << " end" << std::endl;

			///////////////////////////
			// Change File Strem position
			///////////////////////////
			int timestamp = 0;
			std::cout << "TS " << std::endl;
			timestamp = readTimestamp(position, file);
			std::cout << timestamp << " end" << std::endl;
			std::string buffer, link;

			if (file.eof())
				return 1;

			///////////////////////////
			// Enter Distinct/Top block
			///////////////////////////

			// -1: not defined;
			//  1: top;
			//  2: distinct
			if (cnt.mode == 1)
			{

				topQuery(file, timestamp, cnt.to, cnt.numberOfTopQueries);
			}
			else if (cnt.mode == 2)
			{
				std::cout << "DQ" << std::endl;
				distinctQuery(file, timestamp, cnt.to);
				std::cout << " end" << std::endl;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			std::cout << "File couldn't be open";
		}

		file.close();
	}
	else
	{
		return 1;
	}
}
