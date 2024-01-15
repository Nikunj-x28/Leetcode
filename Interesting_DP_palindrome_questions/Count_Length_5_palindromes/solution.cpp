#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod=1e9+7;
    int countPalindromes(string s) {
        int n=s.size();
        int pre[n][10][10],post[n][10][10];
        memset(pre,0,sizeof(pre));
        memset(post,0,sizeof(post));
        int count[10]={0};
        count[s[0]-'0']++;
        for(int i=1;i<n;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    if(s[i]-'0'==k){
                        pre[i][j][k]=count[j]+pre[i-1][j][k];
                    }else{
                        pre[i][j][k]=pre[i-1][j][k];
                    }
                }
            }
            count[s[i]-'0']++;
        }
        memset(count,0,sizeof(count));
        count[s[n-1]-'0']++;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    if(s[i]-'0'==k){
                        post[i][j][k]=count[j]+post[i+1][j][k];
                    }else{
                        post[i][j][k]=post[i+1][j][k];
                    }
                }
            }
            count[s[i]-'0']++;
        }
        int ans=0;
        for(int i=2;i<n-2;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    int num=(1ll*pre[i-1][j][k]*post[i+1][j][k])%mod;
                    ans = (0ll+ans+num)%mod;
                }
            }
        }
        return ans;


    }
};