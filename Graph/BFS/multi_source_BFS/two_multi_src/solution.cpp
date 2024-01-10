#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<ll> city(n+1);
    for (int i = 1; i <= n;i++){
        cin >> city[i];
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<pair<int,int>> q;
    map<pair<int,int>,int> vis;
    for(int i=1;i<=n;i++){
      if(city[i]!=0){
        q.push({city[i],i});
        vis[{city[i],i}]=0;
      }
    }
    int level=0;
    while(!q.empty()){
      int a=q.size();
      for(int i=0;i<a;i++){
          int color=q.front().first;
          int city=q.front().second;
          q.pop();
          for(auto&it:adj[city]){
            if(vis.find({color,it})==vis.end()){
              int alt= color==1?2:1;
              if(vis.find({alt,it})==vis.end()) {
                  q.push({color,it});
                  vis[{color,it}]=level+1;
              }else {
                if(vis[{alt,it}]== level+1)
                  cout<<level+1<<'\n';
                else cout<<level+0.5<<'\n';
                return;
              }
            }
          }
      }
      level++;
    }
    cout<<-1<<'\n';
}