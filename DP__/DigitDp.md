Example Problem -> https://atcoder.jp/contests/dp/tasks/dp_s

Digit DP general framwork ->
_Usually the numbers are so large that we need to store the number in a string._
Type 1 Question : Find number of digits that satisfy some condition for range 1 to N.
= say N = 345601
Now we need to generate all digits smartly such that we can find the answer within time constraints.
for each place we have two scenarios
i=0 -> 0,1,2,3
if we take 0,1 or 2 at place 0 we can choose all digits 0 to 9 for the remaining place because all the numbers
generated will be smaller than 345601.
But if we take i=0 to be 3 we have to limit ourselves so that the numbers generated stay within 345601.

Thus in our recursion we take not only the index i but another variable isTight.
isTight = 1 our range is limited.
isTight = 0 we are free.

so recursion states become f(index,isTight,\_\_\_)
the remaining space is usually information we need to store such as sum , modulo etc depending on the question. See the below solution for more clarity.

Type 2 Question : Find answer for range L to R.
= (ans(R) - ans(L-1) + mod)%mod.

Solution of above case:

```
int solve(int isTight,int prevRem,int i,int n,string &s,int &d,vector<vector<vector<int>>> &dp){
    if(i==n) return (prevRem==0);
    if(dp[i][prevRem][isTight]!=-1) return dp[i][prevRem][isTight];
    int ans=0;
    for(int j=0;j<=(isTight ? (s[i]-'0') :9);j++){
        ans=(ans+solve((isTight and j==(s[i]-'0')),(prevRem+j)%d,i+1,n,s,d,dp))%mod;
    }
    return dp[i][prevRem][isTight] = ans;
}
int main(){
        string s; cin>>s;
        int n = s.size();
        int d;cin>>d;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(d,vector<int>(2,-1)));
        // remove 0 case
        cout<<(solve(1,0,0,n,s,d,dp)-1+mod)%mod;
}
```
