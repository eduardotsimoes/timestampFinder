#pragma once

class SortedCollectionInterface {

    public:

        SortedCollectionInterface(){};

        virtual ~SortedCollectionInterface(){};

        virtual int getSize() const = 0 ;

        virtual int getValue(int index) const = 0; 

};