#include<bits/stdc++.h>
using namespace std;
// runs in O(n) average and O(n*n) Worst
// random pivot choosing makes the algorithm closer to O(n)

class Solution {
public:
    int kthlargest(vector<int>& nums, int k)
    {      
        // first find a random pivot in the vector/array
        // making it random avoids having worst case of O(n*n)
        // **statistically
    // it avoids picking up the smallest or largest element which does give worst case
    // if the size of vector is large enough **statistically      
            int pivot=nums[rand()%nums.size()];
     // small stores smaller elements than pivot large stores larger equal stores same
            vector<int> small,equal,large;
    // we iterate once through our given vector and put elements in their respective 
    // vectors
            for(auto i:nums){
                if(i<pivot) small.push_back(i);
                else if(i==pivot) equal.push_back(i);
                else large.push_back(i);
            }
    // if size of large vector is greater or equal to kth largest element
    // of course the KLM must be in this vector so recursively call function for large
            if(k<=large.size()) return kthlargest(large,k);

   // if size of large plus equal is less than KLM than it must be in small
   // but wait we need to modify k's value too as we are basically removing
   // large.size+equal.size from K than finding the updated K in small
   // e.g.   large= 6,9,5
            //  equal= 3,3
            //  small= 1,2,0
            //  K=6
            //  now 6th Lar.Ele. must be in small 
            //  but in small do we again find the 6th no!! 
            //  we find 6-2-3 that is 1st largest element.
    if(k>large.size()+equal.size()) return kthlargest(small,k-large.size()-equal.size());

  // else return pivot
    return pivot;
    }
    int findKthLargest(vector<int>& nums, int k) {
            return kthlargest(nums,k);
    }
};