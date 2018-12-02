#pragma once

/*! \brief SortedCollectionInterface.
 *         Interface used by the binary search.
 *
 *  This interface is used by the bynary search to improve flexibilty in the file format the binary search works.
 */
class SortedCollectionInterface
{

  public:
    SortedCollectionInterface(){};

    virtual ~SortedCollectionInterface(){};

    virtual int getSize() const = 0;

    virtual int getValue(int index) const = 0;
};