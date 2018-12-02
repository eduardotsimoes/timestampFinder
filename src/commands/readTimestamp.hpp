
#pragma once

#include <istream>

/*! \brief Read Time Stamp.
 *         function responsible to find the timestamp in file.
 *
 *  This function is responsible to find a timestamp in a file.
 *  It goes backwards to fine the timestamp from the actual block in the current position.
 */
int readTimestamp(int index, std::istream &stream);
