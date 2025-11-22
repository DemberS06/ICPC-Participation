#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N=112345, M=1123, mod=2e9+14, inf=4e18+1234;

ll dp[N][4], vis[N][4], vv[N][4];
vector<pair<pair<ll, ll>, ll>> adj[N][4];
ll n, m, l, x, y;

void solve(){
    cin>>n>>m>>l>>x>>y;
    
    for(int i=0; i<n; i++){
        adj[i][1].push_back({{i,2},mod*x+y});
        adj[i][2].push_back({{i,1},mod*x+y});
    }
    for(int i=0, p, q, w, h; i<m; i++){
        cin>>p>>q>>w>>h; p--;q--;
        adj[p][1].push_back({{q, 1},mod*w+h});
        adj[q][1].push_back({{p, 1},mod*w+h});
    }

    for(int i=0, p, q, w, h; i<l; i++){
        cin>>p>>q>>w>>h; p--;q--;
        adj[p][2].push_back({{q, 2},mod*w+h});
        adj[q][2].push_back({{p, 2},mod*w+h});
    }

    adj[0][0].push_back({{0,1},mod*x+y});
    adj[0][0].push_back({{0,2},mod*x+y});
    adj[0][0].push_back({{0,3},mod*x+y});

    adj[n-1][1].push_back({{n-1,3},mod*x+y});
    adj[n-1][2].push_back({{n-1,3},mod*x+y});

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

    set<pair<ll, pair<ll, ll>>> f;
    f.insert({0,{0,0}});

    while(!f.empty()){
        auto [peso, id]=*f.begin();
        f.erase(f.begin());
        auto& [i, j] = id;
        if(vis[i][j])continue;
        vis[i][j]=1;

        for(auto& [ID, w]:adj[i][j]){
            auto& [p, q]=ID;
            if(vis[p][q])continue;
            f.erase({dp[p][q], {p, q}});
            dp[p][q]=min(dp[p][q], peso+w);
            f.insert({dp[p][q],{p, q}});
        }
    }

    ll p=dp[n-1][3]/mod, q=dp[n-1][3]%mod;
    cout<<p<<' '<<q<<"\n";

    return;
}

void clean(){
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++)dp[i][j]=inf, vis[i][j]=vv[i][j]=0, adj[i][j].clear();
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    for(int i=0; i<N; i++){
        for(int j=0; j<4; j++)dp[i][j]=inf;
    }

    int t=1;
    cin>>t;

    while(t--)solve(), clean();

    return t+1;
}
