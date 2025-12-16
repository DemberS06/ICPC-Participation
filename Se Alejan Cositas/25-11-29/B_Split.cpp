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
    cin>>n; ans=0;

    map<int, ll> mp, fr;

    for(int i=0, x; i<2*n; i++){
        cin>>x;
        mp[x]++;
    }
    for(auto& [_, x]:mp)fr[x%4]++;

    ans=2*(fr[2])+fr[1]+fr[3]+4*(fr[0]/2);
    if(fr[0]%2==1 && (fr[3]>0 || fr[1]>1))ans+=2;

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