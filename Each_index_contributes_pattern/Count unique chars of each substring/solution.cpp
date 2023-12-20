#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.size();
        int ans=0;
        for(char curr='A';curr<='Z';curr++){
            int i=0;
            while(i<n and s[i]!=curr) i++;
            int prev=0;
            int j=i+1;
            if(i<n){
                while(j<n){
                    while(j<n and s[j]!=curr) j++;
                    ans+=(j-i)*(i-prev+1);
                    prev=i+1;
                    i=j;
                    j++;
                }
                ans+=(n-i)*(i-prev+1);
            }   
        }
        return ans;
    }
};