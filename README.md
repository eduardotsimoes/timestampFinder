# timestampFinder

[![Build Status](https://travis-ci.com/eduardotsimoes/timestampFinder.svg?branch=master)](https://travis-ci.com/eduardotsimoes/timestampFinder)

## To compile the code:

```
mkdir build && cd build;
camke ..
make
```

## Algorithm:

1. Search the postion in the file that has the timestamp defined from the keyword __FROM__ using a Binary search. **Time Complexity: O(log(n)). Space Complexity : O(1)**

After the first step, then the code can run in __distinct mode__ or __top mode__.

### Distinct mode:

We use the data sturcture std::unstructured_set to keep distinct queries. This date structure is a hash_map;

2. Run a while loops to read distinct queries until the files end or find the timestamp "TO". Given __m__ as the number of line between the FROM and TO keywords, then : **time complexity : O(m). Space Complexity O(m) -> average case**.
3. Print the disctinct queries

So, depending of the size o n and m, the time complexity can be dominated by O(log(n)) or O(m). The space complexity will be O(m).

### Top mode:

We use a std::unstructured_map to count the frequency of each query.
After, to get the top entries, we use a priority queue.

2. Run a while loops to read distinct queries and count its frequency until the files end or find the timestamp "TO". **Time complexity : O(m)**. **Space Complexity O(m) -> average case**.
3. Run a loop in the for each distinct query (Worst case, size "m")  and add to the priority queue of size K (number of top queries): **Time complexity O(m*log(K)) . Space Complexity O(k)**.
4. Print the top queries

So, depending of the size o n and m, the time complexity can be dominated by O(log(n)) or O(m*log(k)). The space complexity will be O(m).