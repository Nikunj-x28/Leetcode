#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string &s){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1,s);
        else{
            int ans=1+solve(i,j-1,s);
            ans=min(ans,1+solve(i+1,j,s));
            return dp[i][j]=ans;
        }
    }
    int minInsertions(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,s);
    }
};