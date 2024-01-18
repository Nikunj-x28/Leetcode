#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[1000][1000][4];
    const int mod=1e9+7;
    int solve(string &s,int i,int j,char value){
        if(i>j) return 0;
        if(i==j) return s[i]==value;
        if(dp[i][j][value-'a']!=-1) return dp[i][j][value-'a'];
        if(s[i]==value and s[j]==value){
            long long ans=2;
            for(int k=0;k<4;k++){
                ans+=solve(s,i+1,j-1,'a'+k);
                ans%=mod;
            }
           return dp[i][j][value-'a']=ans;
        }else{
            return dp[i][j][value-'a']=(0ll+solve(s,i,j-1,value)+solve(s,i+1,j,value)-solve(s,i+1,j-1,value))%mod;
        }

    }
    int countPalindromicSubsequences(string s) {

        // dp relation is defined as
        // number of distinct pali subsequences being bordered by 'value'
        // which is a fixed character

        memset(dp,-1,sizeof(dp));
        int n=s.size();
        long long ans=0;
        for(int i=0;i<4;i++){
            ans+=solve(s,0,n-1,'a'+i);
            ans%=mod;
        }
        return ans;
    }
};