#include "TimeStampCollection.hpp"
#include "readTimestamp.hpp"

TimeStampCollection::TimeStampCollection(std::istream &filename) : _stream(filename){};

TimeStampCollection::~TimeStampCollection(){};

int TimeStampCollection::getSize() const
{
    int acrualPosition = _stream.tellg();
    _stream.seekg(0, _stream.end);
    int length = _stream.tellg();
    _stream.seekg(acrualPosition, _stream.beg);
    return length;
}

int TimeStampCollection::getValue(int index) const
{
    return readTimestamp(index, _stream);
};
