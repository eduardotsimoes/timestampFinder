#pragma once

#include <string>
#include <climits>

struct context{

    int mode = -1 ; // -1 : not defined; 1: top; 2: distinct
    int numberOfTopQueries = -1;
    int from = -1;
    int to = INT_MAX;
    std::string fileName = "";

};

bool argumentParser( int argc , char* argv[] , context &cnt);