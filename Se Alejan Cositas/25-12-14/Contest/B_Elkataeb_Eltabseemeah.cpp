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
    cin>>n>>k; ans=0;
    multiset<pair<ll, ll>> f;
    vector<int> a(n, 0);

    for(ll i=0, x; i<n; i++){
        cin>>x;
        k-=x/2;
        f.insert({x/3, i});
        f.insert({x/6, i});
    }

    while(!f.empty()){
        auto [x, i]=*f.begin();
        f.erase(f.begin());
        if(x>k)continue;
        ans++;
        a[i]++;
        k-=x;
    }

    
    cout<<50*n+25*ans<<"\n";
    for(auto& u:a){
        if(u==0)cout<<"2 ";
        if(u==1)cout<<"1.5 ";
        if(u==2)cout<<"1 ";
    }cout<<"\n";
    
    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t=1; 
    cin>>t;
    
    while(t--)solve();

    return t+1;
}