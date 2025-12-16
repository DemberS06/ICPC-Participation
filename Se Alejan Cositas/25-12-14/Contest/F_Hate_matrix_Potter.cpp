// hola soy Dember :D
// 20/08/2025

#include <bits/stdc++.h>

#define ll long long 
#define pll pair<ll,ll>
#define F first
#define S second 
#define Z size()
#define pb push_back
#define bp pop_back
#define all(n) n.begin(), n.end()
#define lla(n) n.rbegin(), n.rend()
#define arr(x,y,z) x+y, x+y+z
#define quesito queue 
#define luisycarlossequieren cin
#define luisgay cout

using namespace std;

//using i128 = __int128_t;

void value(ll in){cout<<((in)?"YES\n":"NO\n");}

const ll N=2e5+5, M=3e3+5, mod=998244353, md=1e9+7, inf=1e18;

ll n, m, k, pre[N], pos[N], parent[N], sub[N];
ll ans;
vector<ll> adj[N];

void dfs(int x, int y){
    sub[x]=sub[y];
    parent[x]=y;
    pre[x]=++k;
    for(auto& u:adj[x]){
        if(u==y)continue;
        dfs(u, x);
    }
    pos[x]=++k;
}

int son(int x, int y){
    if(pre[x]<=pre[y] && pos[y]<=pos[x])return 1;
    return 0;
}

bool sp(int m, int x, int y){
    if(son(x, y)){
        
        if(son(m, x))return 1;
        if(son(y, m))return 1;
        if(m==parent[y])return 1;
        for(auto &u:adj[x]){
            if(son(u, y))continue;
            if(son(x, m))return 1;
        }
    }

    if(son(x, m) || son(y, m)){
        if(son(x, y) && son(y, m))return 1;
        if(son(x, m))return 0;
        if(son(y, m))return 1;
    }
    if(son(m, x) && son(x, y))return 0;
    if(son(m, parent[y]))return son(parent[y], x);
    
    for(auto& u:adj[parent[y]]){
        if(son(u, m) && son(u, x))return 0;
    }
    
    return 1;
}

void solve(){
    int x, y;
    cin>>m>>x>>y;

    if(x==y)return value(1);

    value(sp(m,x,y)||sp(m,y,x));
    
    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t=1; 
    cin>>n>>t;
    for(int i=1, x, y; i<n; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<adj[1].size(); i++)sub[adj[1][i]]=i+1;

    dfs(1, 1);
    
    while(t--)solve();

    return t+1;
}