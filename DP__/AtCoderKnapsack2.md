https://atcoder.jp/contests/dp/tasks/dp_e

### Problem Statement

There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of w_i and a value of v_i.

Taro has decided to choose some of the N items and carry them home in a knapsack. The capacity of the knapsack is
W, which means that the sum of the weights of items taken must be at most W.

Find the maximum possible sum of the values of items that Taro takes home.

### Constraints :

- 1≤N≤100
- 1≤W≤10^9
- 1≤w_i≤W
- 1≤v_i≤10^3

### Solution

We have solved knapsack in the past where we used the index and current weight as the states.
But here the value of weight is so large we cant possibly take it as a state.
This seems problematic as we know it can be solved by dp only and weight is a necessary factor here.

The way to go about these problems where your Constraints cannot fit in DP.
CHECK which other parameters are involved in the problem -> here value and index is there.
CAN we try to find optimal value of CONSTRAINT for these parameters ??
which transaltes to in this problem can we find the minimum weight for a given index and value ?
YES we can here as the total amount of values can just be 10^3 \* 100 so we can iterate over all these
for a single index and find the minimum weight for each.

IN this way we can use DP over index and value and still get the answer.

**THIS IS THE RARE PATTERN WHERE DP DOESNT RETURN THE ANSWER ASKED IN THE QUESTION**
**DP RETURNS SOME OTHER VALUE(HERE MIN WEIGHT) AND WE USE THAT TO REACH TO OUR ANSWER**
