
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cassert>
#include <unordered_set>

#include "../commands/SortedCollectionInterface.hpp"
#include "../commands/readTimestamp.hpp"
#include "../commands/binarySearch.hpp"
#include "../commands/TimeStampCollection.hpp"
#include "../commands/argumentParser.hpp"
#include "../commands/topQuery.hpp"

#pragma GCC diagnostic ignored "-Wwrite-strings"

class Collection : public SortedCollectionInterface
{

    const std::vector<int> &_nums;

  public:
    Collection(const std::vector<int> &nums) : _nums(nums){};

    ~Collection(){};

    int getSize() const override
    {
        return _nums.size();
    }

    int getValue(int index) const override
    {
        return _nums[index];
    };
};

int main()
{

    const char *text =
        "1438387423	http%3A%2F%2Ftechacute.com%2F10-essentials-every-desk-needs%2F\n"
        "1438387423	%22http%3A%2F%2Fmiamiherald.typepad.com%2Fnakedpolitics%2F2015%2F07%2Fjeb-bushs-mixed-record-devolving-mount-tallahassee.html%22\n"
        "1438387425	http%3A%2F%2Fwebboard.yenta4.com%2Ftopic%2F419976\n"
        "1438387426	nixos\n"
        "1438387426	%22http%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3D-V9Ej78JbhY%22";

    std::istringstream stream(text);

    //////////////////////////////////////////////////
    // Time Stamp
    /////////////////////////////////////////////////

    // Test #2 line
    assert(readTimestamp(95, stream) == 1438387423);

    // Test #1 line
    assert(readTimestamp(30, stream) == 1438387423);

    // Test #3 line
    assert(readTimestamp(250, stream) == 1438387425);

    //////////////////////////////////////////////////
    // Binary Search
    /////////////////////////////////////////////////

    std::vector<int> v = {2, 3, 5, 6, 7, 8, 9};

    SortedCollectionInterface *vv = new Collection(v);

    assert(binarySearch(2, vv) == 0);

    /////////////////////////////////////////////////
    // Command line arguments
    /////////////////////////////////////////////////

    context cnt;

    int argc = 8;

    char *arg1[] = {"hnstat", "top", "10", "--from", "1438548177", "--to", "1438548188", "hn_logs.tsv"};

    assert(argumentParser(argc, arg1, cnt));

    argc = 7;
    char *arg2[] = {"hnstat", "distinct", "--from", "1438548177", "--to", "1438548188", "hn_logs.tsv"};

    assert(argumentParser(argc, arg2, cnt));

    argc = 5;
    char *arg3[] = {"hnstat", "distinct", "--to", "1438548188", "hn_logs.tsv"};

    assert(argumentParser(argc, arg3, cnt));

    argc = 5;
    char *arg31[] = {"hnstat", "distinct", "--from", "1438548188", "hn_logs.tsv"};

    assert(argumentParser(argc, arg31, cnt));

    argc = 3;
    char *arg4[] = {"hnstat", "distinct", "hn_logs.tsv"};

    assert(argumentParser(argc, arg4, cnt));

    argc = 2;
    char *arg5[] = {"hnstat", "distinct"};

    assert(!argumentParser(argc, arg5, cnt));

}

#pragma GCC diagnostic pop