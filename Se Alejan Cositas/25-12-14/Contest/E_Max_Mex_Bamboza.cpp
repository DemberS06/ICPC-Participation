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

ll n, m, k;
ll ans;

void solve(){
    cin>>n>>k;

    vector<ll> a(n), fr(n+7, 0);

    for(auto& u:a){
        cin>>u; if(u<n+7)fr[u]++;
    }

    ans=k;
    if(fr[0]==n)ans=0;

    for(int i=0; i<=n+7; i++){
        if(fr[i])continue;
        ans=min(ans, i+1ll);
    }

    cout<<ans<<"\n";
    
    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t=1; 
    cin>>t;
    
    while(t--)solve();

    return t+1;
}