#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    const int m=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
       int n=arr.size();
       vector<int> right(n,0),left(n,0);
       stack<int> s;
       for(int i=n-1;i>=0;i--){
                while(!s.empty() and arr[i]<=arr[s.top()]){
                    s.pop();
                }
                right[i]=s.empty()?n:s.top(); 
                s.push(i);
       }
       while(!s.empty()) s.pop();
       for(int i=0;i<n;i++){
                while(!s.empty() and arr[i]<arr[s.top()]){
                    s.pop();
                }
                left[i]=s.empty()?-1:s.top(); 
                s.push(i);
       }
       long long ans=0;
       for(long long i=0;i<n;i++){
                 ans+=((arr[i]*(i-left[i]))%m*(right[i]-i)%m);
                 ans%=m;
       }
       return ans;
    }
};
