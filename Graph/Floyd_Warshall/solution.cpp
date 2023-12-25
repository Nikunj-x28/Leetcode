#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ct=0;
    // its vv imp that we pass distance matrix as a copy here
    // so that for different cases it doesnt get updated
    // this caused a whooping 12 wrong submissions 😣
    bool valid(vector<int> &v,int &maxDist,vector<vector<int>> dist){
            int i, j, k;
            int V=v.size();
            for (k = 0; k < V; k++) {
                if(v[k]==0) continue;
                for (i = 0; i < V; i++) {
                    if(v[i]==0) continue;
                    for (j = 0; j < V; j++) {
                        if(v[j]==0) continue;
                        if (dist[i][j] > (dist[i][k] + dist[k][j]))
                            dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
            for (k = 0; k < V; k++) {
                if(v[k]==0) continue;
                for (i = 0; i < V; i++) {
                    if(v[i]==0 or i==k) continue;
                    if(dist[k][i]>maxDist or dist[k][i]==100001) return false;
                }
            }
            return true;

    }
    void solve(int i,vector<int> &v,int &k,vector<vector<int>> &adj){
        if(i==v.size()){
            if(valid(v,k,adj)) ct++;
            return;
        }
        //nottake
        solve(i+1,v,k,adj);
        //take
        v[i]=1;
        solve(i+1,v,k,adj);
        v[i]=0;
    }
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<int> v(n,0);
        vector<vector<int>> adj(n,vector<int>(n,100001));
        for(auto &it:roads){
                    adj[it[0]][it[1]]=min(adj[it[0]][it[1]],it[2]);
                    adj[it[1]][it[0]]=adj[it[0]][it[1]];
        }
        solve(0,v,maxDistance,adj);
        return ct;
    }
};