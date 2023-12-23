#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        // mean absolute error is the least with median
        // ....  M  ....  -> see median always splits the array in two equal portions
        // so if we take mean around the median it will always be smaller than to 
        // either its right side or left side.

        // so the palindrome closest to median are the possible candidates.
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid;
        if(n&1) mid=nums[n/2];
        else mid=(nums[n/2]+nums[n/2-1])/2;


        // start of finding candidate palindromes //
        string s=to_string(mid);
        long long arr[5]={0};
        arr[0]=pow(10,s.size()-1)-1;
        arr[4]=pow(10,s.size());
        arr[4]++;
        string temp=s;
        n=s.size();
        for(int i=0;i<n/2;i++) temp[n-1-i]=temp[i];
        arr[2]=stoll(temp);
        int temp1=stoll(s.substr(0,(n+1)/2));
        string one=to_string(temp1-1);
        string two=to_string(temp1+1);
        for(int i=n/2-1;i>=0;i--) 
        {
           one.push_back(one[i]);
           two.push_back(two[i]);
        }
        arr[1]=stoll(one),arr[3]=stoll(two);
        //   end of finding all candidate palindromes //


        long long ans=LLONG_MAX;
        for(auto &it:arr){
            long long cur=0;
            for(auto &num:nums){
                cur+=abs(num-it);
            }
            ans=min(ans,cur);
        }
        return ans;
        
    }
};