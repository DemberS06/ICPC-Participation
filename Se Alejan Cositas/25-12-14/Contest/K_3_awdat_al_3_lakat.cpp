// hola soy Dember :D
// 20/08/2025
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const ll N=500, M=75e5+5, mod=998244353, md=1e9+7, inf=1e18;

ll n, m, k, xr[N][N], L[M], R[M];
ll ans, dp[N][N];

struct trie{
    int sz;

    trie(){
        sz=0;
        L[sz]=R[sz]=-1;sz++;
    }

    void clear(){
        sz=0;
        L[sz]=R[sz]=-1;sz++;
    }

    void push(int x){
        for(int h=29, p=0; h>=0; h--){
            if((x>>h)&1){
                if(L[p]==-1)L[p]=sz, L[sz]=R[sz]=-1, sz++;
                p=L[p];
            }
            else{
                if(R[p]==-1)R[p]=sz, L[sz]=R[sz]=-1, sz++;
                p=R[p];
            }
        }
    }

    int query(int x){
        int res=0;
        for(int h=29, p=0; h>=0; h--){
            if(((x>>h)&1)){
                if(R[p]!=-1)p=R[p];
                else res+=(1<<h), p=L[p];
            }
            else{
                if(L[p]!=-1)res+=(1<<h), p=L[p];
                else p=R[p];
            }
        }
        return res;
    }
};

trie TR;

void solve(){
    cin>>n>>k;

    vector<int> a(n);
    for(auto& u:a)cin>>u;

    for(int r=0; r<n; r++){
        TR.push(0);
        for(int l=r-1; l>=0; l--){
            xr[l][r]=a[l]^a[r]^TR.query(a[l]^a[r]);
            for(int i=l+1; i<=r; i++)TR.push(a[l]^a[i]);
        }
        //for(auto& [x,y]:TR.ch)cout<<x<<"<->"<<y<<' ';cout<<"\n";
        TR.clear();
    }

    for(int l=0; l<n; l++){
        for(int r=l+2; r<n; r++){
            xr[l][r]=max({xr[l][r], xr[l+1][r], xr[l][r-1]});
        }
    }

    for(int i=0; i<n; i++){
        dp[i][0]=xr[0][i];
        for(int j=1; j<k; j++){
            dp[i][j]=0;
            for(int l=j; l<=i; l++){
                dp[i][j]=max(dp[i][j], dp[l-1][j-1]+xr[l][i]);
            }
        }
    }

    cout<<dp[n-1][k-1];
    
    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t=1; 
    cin>>t;
    
    while(t--)solve();

    return t+1;
}