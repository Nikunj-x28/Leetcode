#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<vector<int>> &v,int l,int &n,int num){
        int r=n-1;
        int ans=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid][0]>=num){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        int n=startTime.size();
        for(int i=0;i<n;i++){
            v.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(v.begin(),v.end());
        vector<int> dp(n,0);
        dp[n-1]=v[n-1][2];
        for(int i=n-2;i>=0;i--){
            dp[i]=dp[i+1];
            int pos=search(v,i+1,n,v[i][1]);
            if(pos==n) dp[i]=max(dp[i],v[i][2]);
            else dp[i]=max(dp[i],v[i][2]+dp[pos]);
        }
        return dp[0];
    }
};