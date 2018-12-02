#pragma once

#include <string>
#include <climits>

/*! \brief Argument Parsing.
 *         function responsible to parsing the inputs.
 *
 *  This function is responsible for parsing the input. The output is the context object.
 */

struct context
{

    int mode = -1; // -1 : not defined; 1: top; 2: distinct
    int numberOfTopQueries = -1;
    int from = -1;
    int to = INT_MAX;
    std::string fileName = "";
};

bool argumentParser(int argc,     /**< [in] size of input array argc. */
                    char *argv[], /**< [in] array of chars. */
                    context &cnt);