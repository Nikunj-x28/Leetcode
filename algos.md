(For contest usage)
# LINKS
1. [Trie](#trie)
2. [KMP](#kmp_algorithm)
3. [Z Array](#z_array)
4. [Rabin Karp](#rabinkarp)
5. [Binary Exponentiantion](#binary_exponentiantion)
6. [DSU](#dsu)
7. [Principal of inclusion exclusion](#pie)
8. [Bellman Ford](#bellman_ford)
9. [Smallest Prime factor](#spf)
10. [Tree Diameter Algorithm](#tree_diameter)
11. [Strongly Connected Components(kosaraju)](#scc)
12. [Find negative cycles](#negative_cycles)

# KMP_algorithm
## mark index of string s where pattern a is found.
```
    a is pattern string
    void getPatternMatchingIndex(string& s, string& a, vector<int>& v){
        string t = a + "@" + s;
        vector<int> lps(1, 0);
        for(int i = 1; i < t.size(); ++i){
            int ind = lps[i-1]; 
            while(ind > 0 && t[ind] != t[i]) { ind = lps[ind-1]; }
            lps.push_back((t[ind] == t[i])?ind + 1 : 0);
        }
        for(int i = 0; i < lps.size(); ++i){
            if(lps[i] == a.size()) v[i - 2*a.size()]=1;
        }
    } 
```

# Z_Array
```
    Examples :-
    aaaaa   - [0, 4, 3, 2, 1]
    aaabaab - [0, 2, 1, 0, 2, 1, 0]
    abacaba - [0, 0, 1, 0, 3, 0, 1]

    to find pattern P in string T
    find z_array of P#T where # is a character not in both P and T.
    for i in (P.length+1 , P.length+1+ T.length-1 ) 
        if z_array[i] = P.length pattern found at j = i-P.lenght-1 position of T.
    
    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
```

# Rabin_Karp
## aka rolling hash
## for lowercase character only strings 
```
    s is pattern string
    t is text string
    vector<int> rabin_karp(string const& s, string const& t) {
        const int p = 31; 
        const int m = 1e9 + 9;
        int S = s.size(), T = t.size();

        vector<long long> p_pow(max(S, T)); 
        p_pow[0] = 1; 
        for (int i = 1; i < (int)p_pow.size(); i++) 
            p_pow[i] = (p_pow[i-1] * p) % m;

        vector<long long> h(T + 1, 0); 
        for (int i = 0; i < T; i++)
            h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
        long long h_s = 0; 
        for (int i = 0; i < S; i++) 
            h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

        vector<int> occurrences;
        for (int i = 0; i + S - 1 < T; i++) {
            long long cur_h = (h[i+S] + m - h[i]) % m;
            if (cur_h == h_s * p_pow[i] % m)
                occurrences.push_back(i);
        }
        return occurrences;
    }
```

# Binary_Exponentiantion
```
    ll binexp(ll a, ll b,ll m=1e9+7)
    {
    ll ex = 1;
    while (b)
    {
        if (b & 1)
        {
        ex = (ex * a)%m;
        }
        a = (a * a)%m;
        b >>= 1;
    }
    return ex%m;
    }
```

# DSU
```
class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}
    
	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};
```

# Trie
```
class Node {
    public:
    Node *links[26];
    bool isend;
    int count;
    Node(){
        isend=false;
        count=0;
        for(int i=0;i<26;i++) links[i]=NULL;
    }
    bool haskey(char c){
        return links[c-'a']!=NULL;
    }
    Node *getkey(char c){
        return links[c-'a'];
    }
    void putkey(char c){
        links[c-'a']=new Node();
    }
    ~ Node(){
        for(int i=0;i<26;i++){
            delete links[i];
        }
    }
};
class Trie {
public:
    Node *root;
    Trie() {
        root=new Node();
    }
    
    void insert(string& word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->haskey(word[i])){
                node=node->getkey(word[i]);
            }else{
                node->putkey(word[i]);
                node=node->getkey(word[i]);
            }
            node->count++;
        }
        node->isend=true;
    }
    
    bool search(string& word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->haskey(word[i])){
                node=node->getkey(word[i]);
            }else{
                return false;
            }
        }
        return node->isend;
    }
    int countPrefixOccurence(string& word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->haskey(word[i])){
                node=node->getkey(word[i]);
            }else{
                return false;
            }
        }
        return node->isend;
    }
    
    bool startsWith(string& prefix) {
        Node *node=root;
        for(int i=0;i<prefix.size();i++){
            if(node->haskey(prefix[i])){
                node=node->getkey(prefix[i]);
            }else{
                return false;
            }
        }
        return true;
    }
     ~Trie(){
        delete root;
    }
};

```

# Pie
```
use bitmask for all the combinations
for(int mask=1;mask<(1<<n);mask++){
    
}
```

# Bellman_Ford
```
handles 1 based indexing also

const long long inf = 1e15;
vector<ll> Bellman(int src,vector<vector<int>> &edges){
    vector<ll> dist(n+1,inf); 
    dist[src]=0;
    for(int i=1;i<n;i++){
        for(auto &it:edges){
            int from = it[0];
            int to = it[1];
            ll weight = it[2];
            if(dist[from]!=inf and dist[from]+weight<dist[to]){
                dist[to] =dist[from]+weight;
            }
        }
    }
}
```

# SPF
```
#define MAXN 100001
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 2; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
            // if not marked by any smaller prime mark it
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
```

# Tree_Diameter
## T.C O(2*(V+E)) uses two BFS
## n is number of nodes in the tree 
```
vector<int> diameter(vector<int> adj[],int &n){
        if(n==1){
            return {0};
        }
        vector<int> vis(n,0);
        vis[0]++;
        queue<int> q;
        q.push(0);
        int start,end;
        while(!q.empty()){
            int node = q.front(); q.pop();
            start=node;
            for(auto &it:adj[node]){
                if(!vis[it]){
                    vis[it]++;
                    q.push(it);
                }
            }
        }
        vis[start]=0;
        q.push(start);
        vector<int> parent(n,-1);
        while(!q.empty()){
            int node = q.front(); q.pop();
            end=node;
            for(auto &it:adj[node]){
                if(vis[it]){
                    parent[it]=node;
                    vis[it]=0;
                    q.push(it);
                }
            }
        }
        vector<int> ans;
        while(end!=start){
            ans.push_back(end);
            end=parent[end];
        }
        ans.push_back(start);
        return ans;
}
```

# SCC
## finds strongly connected components by designating a root number to them
## number of scc = root count
## T.C = O(V+E)
```

void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &ord){
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ord);
        }
    }
    ord.push_back(node);
}

void revdfs(int node,vector<int> adj[],vector<int> &vis,int &kingdom){
    vis[node]=kingdom;
    for(auto &it:adj[node]){
        if(!vis[it]){
            revdfs(it,adj,vis,kingdom);
        }
    }
}

vector<int> scc(int n,vector<vector<int>> &edges){
	   // 1 based indexing modify if needed
       vector<int> adj[n+1],radj[n+1];
       vector<int> vis(n+1,0),ord;
       for(auto &it:edges){
        adj[it[0]].push_back(it[1]);
        radj[it[1]].push_back(it[0]);
       }
       for(int i=1;i<=n;i++){
            if(!vis[i])
                dfs(i,adj,vis,ord);
       }
       reverse(ord.begin(),ord.end());
       vector<int> roots(n+1,0);
       int root=0;
       for(auto &it:ord){
            if(!roots[it]){
                root++;
                revdfs(it,radj,roots,root);
            } 
       }
	   return roots;
}

```
# Negative_cycles
```
void solve(int n,vector<vector<int>> &edges){
  // 1 based nodes
  // The graph can be disconnected so assume an extra node 0 that is connected to all the other nodes
  // and thus dist[] value for each node is 0 in the beginning.
  // Thus relaxation would mean negative distances.

  // Bellman Ford 
  // ith iteration means relax all nodes using paths of length at most i.
  // nth iteration => path of length n => cycle => if it still relaxs => negative cycle
  vector<ll> dist(n+1,0);
  vector<int> parent(n+1,-1);
  int isCycle = 0;
  for(int i=1;i<=n;i++){
    isCycle=0;
    for(auto &it:edges){
      int from=it[0],to=it[1],wt=it[2];
      if(dist[from]+wt<dist[to]){
        dist[to]=dist[from]+wt;
        parent[to]=from;
        isCycle=to;
      }
    }
  }
  if(isCycle){
    cout<<"YES\n";
    vector<int> cycle;
    // a relaxed node could be a part of the cycle or it could be a node reachable through a cycle.
    // so if we go far back enough we will enter the cycle
    // But how far ?
    // If we go back n-1 times we are guaranteed to reach a cycle, assume a node with a self negative loop
    // how far a node that is connected to this self loop node can be ? 
    // at most n-1 steps so if we come back n-1 steps we are guaranteed to enter a cycle.

    for (int i = 0; i < n; ++i)
            isCycle = parent[isCycle];
    for(int v=isCycle;;v=parent[v]){
       cycle.push_back(v);
       if(v==isCycle and cycle.size() > 1)
          break;
    }
    reverse(cycle.begin(), cycle.end());
    for(auto &it:cycle) cout<<it<<" ";
  }else{
    cout<<"NO\n";
  }
}
```