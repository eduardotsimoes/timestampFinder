
#pragma once

#include "SortedCollectionInterface.hpp"
#include <istream>

class TimeStampCollection : public SortedCollectionInterface {
    private:
    
    std::istream &_stream;
    
    public:
    
        TimeStampCollection(std::istream &filename);

        ~TimeStampCollection();

        int getSize() const override;
        int getValue(int index) const override ;

};