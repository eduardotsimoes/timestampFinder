
#pragma once

#include "SortedCollectionInterface.hpp"
#include <istream>

/*! \brief TimeStampCollection.
 *         Implementation of the Interface used by the binary search.
 *
 *  Implementation of the Interface used by the binary search. 
 * It uses the readTimeStamp to find the actual timeStamp in a specific position in the file.
 */
class TimeStampCollection : public SortedCollectionInterface
{
private:
  std::istream &_stream;

public:
  TimeStampCollection(std::istream &filename);

  ~TimeStampCollection();

  int getSize() const override;
  int getValue(int index) const override;
};