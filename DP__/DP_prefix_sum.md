Once you find DP recurrence relations like :-
dp[i][j] = dp[i+1][j]+dp[i+1][j-1]+....dp[i+1][some determinable value] // O(n)
or
dp[i][j] = dp[i+1][j]+dp[i+1][j+1]+....dp[i+1][some determinable value]

What we can use is after calculating the values of dp state at index 'i'
Calculate the prefix sum array for dp[i](or suffix sum)

then we can transform transitions as
dp[i][j] = prefix[i+1][j] - prefix[i+1][some determinable value-1] // O(1)

essentially reducing complexity of recurrence by a factor of n !!

Example question :- https://atcoder.jp/contests/dp/tasks/dp_m
Solution = >
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int main(){
int n,k;cin>>n>>k;
int arr[n];
for(int i=0;i<n;i++) cin>>arr[i];
vector<int> curr(k+1,0),next(k+1,0);
for(int i=0;i<=arr[n-1];i++){
next[i]=1;
}
for(int i=n-2;i>=0;i--){
for(int j=1;j<=k;j++){
next[j] = (0ll+next[j]+next[j-1])%mod;
}
for(int j=0;j<=k;j++){
if(arr[i]>=j){
curr[j]=next[j];
}else{
curr[j]=(0ll+next[j]-next[j-arr[i]-1]+mod)%mod;
}
}
next=curr;
}
cout<<next[k];
}
