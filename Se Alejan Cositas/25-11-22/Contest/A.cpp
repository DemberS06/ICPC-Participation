#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N=112345, M=1123, mod=1e9+7, inf=1e18+1234;

void solve(){
    int n, m, l, x, y;

    cin>>n>>m>>l>>x>>y;

    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>> (4, {inf, inf}));
    vector<vector<ll>> vis(n, vector<ll> (4, 0)), vv=vis;
    vector<vector<vector<pair<pair<ll, ll>, pair<ll, ll>>>>> adj(n, vector<vector<pair<pair<ll, ll>, pair<ll, ll>>>> (4));
    //id   flag   to     edge  id
    for(int i=0; i<n; i++){
        adj[i][1].push_back({{i,2},{x, y}});
        adj[i][2].push_back({{i,1},{x, y}});
    }
    for(int i=0, p, q, w, h; i<m; i++){
        cin>>p>>q>>w>>h; p--;q--;
        adj[p][1].push_back({{q, 1},{w, h}});
        adj[q][1].push_back({{p, 1},{w, h}});
    }

    for(int i=0, p, q, w, h; i<l; i++){
        cin>>p>>q>>w>>h; p--;q--;
        adj[p][2].push_back({{q, 2},{w, h}});
        adj[q][2].push_back({{p, 2},{w, h}});
    }


    adj[0][0].push_back({{0,1},{x, y}});
    adj[0][0].push_back({{0,2},{x, y}});
    adj[0][0].push_back({{0,3},{x, y}});

    adj[n-1][1].push_back({{n-1,3},{x, y}});
    adj[n-1][2].push_back({{n-1,3},{x, y}});

    function<bool(int, int)> dfs= [&](int p, int q){
        vv[p][q]=1;
        if(p==n-1 && q==3)return 1;

        for(auto& [id, _]:adj[p][q]){
            if(vv[id.first][id.second])continue;
            if(dfs(id.first, id.second))return 1;
        }

        return 0;
    };

    if(!dfs(0, 0)){
        cout<<"-1\n";
        return;
    }

    set<pair<pair<ll, ll>, pair<ll, ll>>> f;
    f.insert({{0,0},{0,0}});

    while(!f.empty()){
        auto [peso, id]=*f.begin();
        f.erase({peso, id});
        auto& [i, j] = id;
        if(vis[i][j])continue;
        vis[i][j]=1;

        for(auto& [ID, W]:adj[i][j]){
            auto& [w, h]=W;
            auto& [p, q]=ID;
            if(vis[p][q])continue;
            f.erase({dp[p][q], {p, q}});
            dp[p][q]=min(dp[p][q], {peso.first+w, peso.second+h});
            f.insert({dp[p][q],{p, q}});
        }
    }

    auto& [p, q]=dp[n-1][3];
    cout<<p<<' '<<q<<"\n";

    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t=1;
    cin>>t;

    while(t--)solve();

    return t+1;
}
