#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N=112345, M=1123, mod=1e9+7, inf=1e18+1234;

ll fac[N], rev[N];
ll n, m;

ll expbin(ll x, ll y){
    ll res=1;
    while(y){
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return res;
}

ll nenk(ll n, ll k){
    if(k>n)return 0;
    return (fac[n]*rev[k]%mod)*rev[n-k]%mod;
}

void solve(){
    cin>>n>>m;

    ll ans=nenk(m-n-1, n-1)*fac[n]%mod;;
    ans=ans*m%mod;
    ans=ans*expbin(n, mod-2)%mod;
    if(n==1 && m==1)ans=1;
    
    cout<<(ans+mod)%mod<<"\n";
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    fac[0]=rev[0]=1;
    for(int i=1; i<N; i++)fac[i]=fac[i-1]*i%mod, rev[i]=expbin(fac[i], mod-2);

    int t=1;
    cin>>t;

    while(t--)solve();

    return t+1;
}
