#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(int l,int &n,vector<vector<int>>& events,int num){
        int r=n-1;
        int ans=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(events[mid][0]>num){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        int dp[n+1];
        dp[n]=0;
        dp[n-1]=events[n-1][2];
        int  ans=dp[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=max(events[i][2],dp[i+1]);
            int pos=search(i+1,n,events,events[i][1]);
            ans=max(ans,events[i][2]+dp[pos]);
        }
        return ans;
    }
};