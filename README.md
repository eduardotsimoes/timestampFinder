# timestampFinder

[![Build Status](https://travis-ci.com/eduardotsimoes/timestampFinder.svg?branch=master)](https://travis-ci.com/eduardotsimoes/timestampFinder)


## To compile the code:

```
mkdir build && cd build;
camke ..
make
```

## Algorithm:

1. Search the postion in the file that has the timestamp defined from the keyword "FROM" using a Binary search. **Time Complexity: O(log(n)). Space Complexity : O(1)**

### Distinct mode:

We use the data sturcture std::unstructured_set to keep distinct queries. This date structure is a hash_map;

2. Run a while loops to read distinct queries until the files end or find the timestamp "TO". **time complexity : O(m). Space Complexity O(m) -> average case**.
3. Print the disctinct queries


### Top mode:

We use a std::unstructured_map to count the frequency of each query.
After, to get the top entries, we use a priority queue.

2. Run a while loops to read distinct queries and count its frequency until the files end or find the timestamp "TO". **Time complexity : O(m)**. **Space Complexity O(m) -> average case**.
3. Run a loop in the for each distinct query (Worst case, size "m")  and add to the priority queue of size K (number of top queries): **Time complexity O(m*log(K)) . Space Complexity O(k)**.
4. Print the top queries
