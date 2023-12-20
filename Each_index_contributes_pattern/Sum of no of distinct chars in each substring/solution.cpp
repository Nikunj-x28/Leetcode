#include<string>
using namespace std;
class Solution {
public:
    long long appealSum(string s) {
        int n=s.size();
        long long ans=0;
        for(char curr='a';curr<='z';curr++){
            int i=0;
            int prev=0;
            while(i<n){
                while(i<n and s[i]!=curr) i++;
                if(i<n){
                    ans+=(n-i)*(i-prev+1);
                    prev=i+1;
                    i++;
                }
            }
        }
        return ans;
    }
};