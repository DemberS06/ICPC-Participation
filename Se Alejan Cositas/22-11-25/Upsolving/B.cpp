#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, ans;
vector<int> v;

bool sim(int k){
    int s=v[1], yupi=1;
    for(int i=2; i<=n; i++){
        if(v[i]>=s+k){
            yupi++;
            s=v[i];
        }
    }
    if(yupi>=m){return 1;}
    return 0;
}

void bin(int l, int r){
    if(l>r){return;}
    int k=(l+r)/2;

    if(sim(k)){ans=k; bin(k+1,r); return;}
    bin(l,k-1);
    return;
}

void sove(){
    int x;
    cin>>n>>m;
    v.resize(n+1);
    v[0]=0;
    for(int i=1; i<=n; i++){cin>>v[i];}
    sort(v.begin(),v.end());

    bin(0, (v[n]-v[1]+m-2)/(m-1) );
    cout<<ans<<'\n';

    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t=1;
    cin>>t;

    while(t--)sove();

    return t+1;
}
