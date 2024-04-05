Sometimes it is better to utilize unordered maps to implement memoization.
We are tricked into thinking the dp array will time out or it cant be made due to large space allocation.

BUT the SEARCH SPACE is actually a small portion of all the possible values of STATE VARIABLES.

Following is a good question about this idea :-

You are given an integer array nums of length n, and a positive integer k.
The power of a subsequence is defined as the minimum absolute difference between any two elements in the
subsequence.
Return the sum of powers of all subsequences of nums which have length equal to k.
Since the answer may be large, return it modulo 10^9 + 7.

Constraints :
2 <= n == nums.length <= 50
-108 <= nums[i] <= 108 
2 <= k <= n

=  After trying a bit we can see that the states are
   - current index
   - current length
   - last index
   - current Min diff

   so if we make a DP array we get -->   dp[51][51][51][2*10^8];
   we will discard this solution BUT IT WILL BE A BIG MISTAKE !!
   TRUSTING THE LOGIC IS IMPRTANT. 
   SEE WHAT IS THE ACTUAL SEARCH SPACE
   - current index = AT MOST 50
   - current length = AT MOST 50
   - last index = AT MOST 50
   - current Min diff = THE MAXIMUM DIFFERENCE CAN BE 2*10^8 BUT TOTAL POSSIBLE DIFFERENCES CAN ONLY BE
     N*(N-1)/2 ~~= 2500
     SO THIS DP IS ABSOLUTELY FEASIBLE

     PROBLEM IS NOW WE HAVE SPACE CONSTRAINTS , WE CANNOT MAKE SUCH A LARGE ARRAY.
     WHAT IS THE SOLUTION ? 
     = USE A NESTED UNORDERED MAP.
     JOB DONE !!!!!!


*** MINIMUM DIFFERENCE CAN ALSO BE DONE AS = ELEMENT[INDEX1] - ELEMENT[INDEX2]
THUS WE CAN ALSO MAKE A DP ARRAY AND SOLVE THE PROBLEM.
SHIT THIS WAS GOOD.
   