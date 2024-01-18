#include<bits/stdc++.h>
using namespace std;
// just similar to lcs one xtra condition is to check that we should never compare same indices.
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n=str.size();
		    vector<vector<int>> dp(n,vector<int>(n,0));
		    int ans=0;
		    for(int i=1;i<n;i++){
		        if(str[i]==str[0]) dp[0][i]=1;
		    }
		    for(int i=1;i<n;i++){
		        int prev_max=0;
		        for(int j=0;j<n;j++){
		            if(i==j or str[i]!=str[j]){
		                dp[i][j]=dp[i-1][j];
		            }else {
		                dp[i][j]=1+prev_max;
		            }
		            prev_max=max(prev_max,dp[i-1][j]);
		            ans=max(ans,dp[i][j]);
		        }
		        
		    }
		    return ans;
		}
};