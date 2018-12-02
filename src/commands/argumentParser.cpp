
#include "argumentParser.hpp"
#include <string.h>
#include <iostream>

bool argumentParser(int argc, char *argv[], context &cnt)
{

    if (argc < 3)
    {

        std::cout << " error, arguments must be higher than 1 "
                  << "\n";
        return false;
    }
    else
    {

        for (int i = 1; i < argc - 1; ++i)
        {

            if (strcmp(argv[i], "top") == 0)
            {

                cnt.mode = 1;
                if (isdigit(*argv[i + 1]))
                {
                    cnt.numberOfTopQueries = std::stoi(argv[++i]);
                }
                else
                {
                    return false;
                }
            }
            else if (strcmp(argv[i], "distinct") == 0)
            {

                cnt.mode = 2;
            }
            else if (strcmp(argv[i], "--from") == 0)
            {

                if (isdigit(*argv[i + 1]))
                {
                    cnt.from = std::stoi(argv[++i]);
                }
                else
                {
                    return false;
                }
            }
            else if (strcmp(argv[i], "--to") == 0)
            {

                if (isdigit(*argv[i + 1]))
                {
                    cnt.to = std::stoi(argv[++i]);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                std::cout << " unknown arguments. Index : " << i << " value: " << argv[i] << "\n";
                return false;
            }
        }

        cnt.fileName = argv[argc - 1];
    }

    return true;
}