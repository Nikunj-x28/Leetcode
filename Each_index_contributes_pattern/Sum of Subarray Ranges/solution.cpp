#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool sol(int a,int b,bool flag, char c){
           if(flag){
              if(c=='r'){
                 return a>=b;
              }
              else {
                  return a>b;
              }
           }
           else{
              if(c=='r'){
                 return a<=b;
              }
              else {
                  return a<b;
              }
           }
    }
     long long sum(vector<int>& arr, bool flag){
       // flag true for maximum of each subarray
       int n=arr.size();
       vector<int> right(n,0),left(n,0);
       stack<int> s;
       for(int i=n-1;i>=0;i--){
                while(!s.empty() and sol(arr[i],arr[s.top()],flag,'r')){
                    s.pop();
                }
                right[i]=s.empty()?n:s.top(); 
                s.push(i);
       }
       while(!s.empty()) s.pop();
       for(int i=0;i<n;i++){
                while(!s.empty() and sol(arr[i],arr[s.top()],flag,'l')){
                    s.pop();
                }
                left[i]=s.empty()?-1:s.top(); 
                s.push(i);
       }
       long long ans=0;
       for(long long i=0;i<n;i++){
                 ans+=arr[i]*(i-left[i])*(right[i]-i);
       }
       return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
       return sum(nums,true)-sum(nums,false);
    }
};