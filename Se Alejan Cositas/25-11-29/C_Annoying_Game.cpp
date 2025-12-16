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

void value(ll in){cout<<((in)?"YES\n":"NO\n");}

const ll N=2e5+5, M=3e3+5, mod=998244353, md=1e9+7, inf=1e18;

ll n, m, k;
ll ans;

void solve(){
    cin>>n>>k; k&=1;
    vector<ll> pref(n+2, 0), suf(n+2, 0), a(n), b(n);

    for(auto& u:a)cin>>u;
    for(auto& u:b)cin>>u;

    for(ll i=1, x=0, mn=0; i<=n; i++){
        x+=a[i-1];
        mn=min(x, mn);
        pref[i]=x-mn;
    }

    
    for(ll i=n, x=0, mn=0; i>0; i--){
        x+=a[i-1];
        mn=min(x, mn);
        suf[i]=x-mn;
    }

    ans=a[0];
    for(int i=1; i<=n; i++){
        ans=max(ans, a[i-1]+k*b[i-1]+pref[i-1]+suf[i+1]);
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