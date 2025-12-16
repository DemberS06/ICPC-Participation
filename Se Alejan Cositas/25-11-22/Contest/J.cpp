#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N=112345, M=1123, mod=1e9+7, inf=1e18+1234;

int n, m, k, ans;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, 1, -1};

void solve(){
    int n, m; ans=0;
    cin>>n>>m;
    m=m*2+1; n++;

    vector<vector<vector<pair<int, int>>>> adj(n+5, vector<vector<pair<int, int>>> (m+5));
    vector<vector<int>> vis(n+5, vector<int> (m+5, 0));

    cin.ignore();

    for(int i=1;i<=n;i++){
        string s;
        getline(cin, s);
        for(int j=1;j<m;j+=2){
            if(s[j]==' '){
                adj[i][j].push_back({i+1, j});
                adj[i+1][j].push_back({i, j});
            }
            if(s[j+1]==' '){
                adj[i][j].push_back({i, j+2});
                adj[i][j+2].push_back({i, j});
            }
        }
    }

    function<void(int, int, int, int)> dfs = [&](int x, int y, int p, int q){
        vis[x][y]=1;
        for(auto [a, b]:adj[x][y]){
            if(a==p && b==q)continue;
            if(vis[a][b]){
                    ans=1;
                    return;
            }
            dfs(a, b, x, y);
        }
        return;
    } ;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(vis[i][j])continue;
            dfs(i, j, 0, 0);
        }
    }

    if(ans==0)cout<<"YES";
    else cout<<"NO";
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t=1;
    //cin>>t;

    while(t--)solve();

    return t+1;
}
