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

const ll N=2e6+5, M=3e3+5, mod=998244353, md=1e9+7, inf=1e18;

ll n, m, k;
vector<ll> pr, ans;
ll crib[N];

void solve(){
    cin>>n;
    for(int i=0; i<n-1; i++)cout<<ans[i]<<' ';cout<<ans[n-1]<<"\n";
    
    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    pr.reserve(N); ans.reserve(N);
    pr.push_back(1);
    for(int i=2; i<N; i++){
        if(crib[i])continue;
        pr.push_back(i);
        for(int j=i; j<N; j+=i)crib[j]=1;
    }
    ans.push_back(1);
    for(int i=1; i<pr.size(); i++){
        ans.push_back(pr[i]*pr[i-1]);
        if(i)ans.push_back(pr[i]*pr[i-1]);
    }
    
    int t=1; 
    cin>>t;
    
    while(t--)solve();

    return t+1;
}