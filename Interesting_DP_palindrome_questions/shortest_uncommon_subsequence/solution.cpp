#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dp[500][500];
    int solve(string &S,string &T,int i,int j){
        if(i==S.size()) return S.size()+1;
        if(j==T.size()) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        // dont take S[i] in shortest uncommon subsequence
        int notTake=solve(S,T,i+1,j);
        int take=-1;
        // take S[i] in shortest uncommon subsequence
        for(int k=j;k<T.size();k++){
            if(T[k]==S[i]){
                take = 1 + solve(S,T,i+1,k+1);
                break;
            }
        }
        if(take==-1) return dp[i][j]=1;
        return dp[i][j]=min(take,notTake);
    }
    int shortestUnSub(string S, string T) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(S,T,0,0);
        return ans>S.size()?-1:ans;
    }
};