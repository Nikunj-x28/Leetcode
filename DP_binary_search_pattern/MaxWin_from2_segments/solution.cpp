#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& v,int l,int &n,int num){
        int r=n-1;
        int ans=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid]<=num){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n=prizePositions.size();
        int dp[n+1];
        dp[n]=0;
        int ans=1;
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int pos=search(prizePositions,0,n,prizePositions[i]+k);
            ans=max(ans,pos-i+1+dp[pos+1]);
            dp[i]=max(dp[i+1],pos-i+1);
        }
        return ans;
    }
};