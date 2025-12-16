#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N=112345, M=1123, mod=1e9+7, inf=1e18+1234;

int n, m, k, ans[M];

void solve(){
    cin>>n;

    set<int> f[10], g[10];

    for(int i=1; i<=n; i++){
        for(int h=0; h<10; h++){
            if((i>>h)&1)f[h].insert(i);
        }
    }

    for(int h=0, x; h<10; h++){
        if(f[h].empty())continue;
        cout<<f[h].size()<<" ";
        for(auto& u:f[h])cout<<u<<' ';cout<<endl;
        for(auto& u:f[h]){
            cin>>x;
            g[h].insert(x);
        }
    }

    for(int i=1; i<=n; i++){
        int idx=0;
        for(int h=0; h<10; h++){
            if(g[h].count(i))idx+=(1<<h);
        }
        ans[idx]=i;
    }

    cout<<"! ";
    for(int i=1; i<=n; i++)cout<<ans[i]<<' ';

    return;
}

int main(){
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t=1;
    //cin>>t;

    while(t--)solve();

    return t+1;
}
