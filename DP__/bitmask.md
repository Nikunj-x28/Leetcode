If you need to go over all combinations of elements in an array or similar data structure with size at most 24/25 you can use bitmask to go over all the combinations.

There are usually two ways in which we use bitmask

1. take a mask then try to add one more member to this mask to reach a new state.

2. take a mask and try all the possible masks it could have been formed from (one member less masks).

In both the above cases we try to maintain some optimal condition. It is good if you use a graph to visualize how bitmasks create new bitmasks that way its easy to find the recurrence relation.

both usually lead to the same answers and it is up to you to decide which is more convenient for you.

some good practice questions are :

- ATcoder dp contest O matching (beginner friendly)
- CSES elevator rides (a good practice)
