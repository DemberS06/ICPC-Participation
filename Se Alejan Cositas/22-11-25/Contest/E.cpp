#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N=112345, M=1123, mod=1e9+7, inf=1e18+1234;

int n, m, k, ans;

void solve(){
    int par=0, imp=0, ans=0;
    cin>>n;

    for(int i=0, x;i<n;i++){
        cin>>x;
        if(x&1)imp++;
        else par++;
    }

    ans=n;

    ans+=max(0, par-imp-1);
    ans+=max(0, imp-par);

    cout<<ans<<'\n';

    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t=1;
    //cin>>t;

    while(t--)solve();

    return t+1;
}
