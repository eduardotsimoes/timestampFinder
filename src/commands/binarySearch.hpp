
#pragma once

class SortedCollectionInterface;

/*! \brief Binary Search.
 *         function responsible to implement the binary search in a file.
 *
 *  This function is responsible for binary search in a file. 
 *  It uses the interface SortedCollectionInterface to extract the timestamp from the file in a specfic position.
 */
int binarySearch(int target, SortedCollectionInterface *collection);
