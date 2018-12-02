
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <cassert>

int readTimestamp(int index, std::istream &stream)
{

        //@TODO: add a buffer to the reverse reading.
        stream.seekg(index, stream.beg);
        char ch = stream.get();

        while (index > 0)
        {

                stream.seekg(--index, stream.beg);
                ch = stream.get();

                if (ch == '\n')
                {
                        ++index;
                        break;
                }
        }

        // parse the time stamp
        stream.seekg(index, stream.beg);
        int timeStamp;
        stream >> timeStamp;
        return timeStamp;
}