#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=112345, M=1123, mod=1e9+7, inf=1e18+1234;
ll n, m, k, ans, sumx, sumy;

void solve(){
    cin>>n;
    vector<long double> X(n), Y(n);

    for(int i=0; i<n; i++){
        cin>>X[i]>>Y[i];
        sumx+=X[i], sumy+=Y[i];
    }

    long double l1=(X[0]+X[1])/2;
    long double l2=(X[2]+X[1])/2;
    long double r1=(Y[0]+Y[1])/2;
    long double r2=(Y[2]+Y[1])/2;

    long double t1=Y[1]-Y[0], t2=Y[2]-Y[1];
    long double t3=X[0]-X[1], t4=X[1]-X[2];
    long double jaimito=( (l2-l1)*t3 + (r1-r2)*t1 )/( t2*t3 - t4*t1 );

    long double cx=l2+jaimito*(Y[1]-Y[2]), cy=r2+jaimito*(X[2]-X[1]);

    ll x=cx, y=cy;
    //cout<<cx<<" "<<cy<<"\n";

    if(cx!=x || cy!=y){cout<<"-1"; return;}

    set<ll> f;

    for(int i=0; i<n; i++){
        ll p=X[i], q=Y[i];
        f.insert((x-p)*(x-p)+(y-q)*(y-q));
    }

    if(f.size()!=1){
        cout<<"-1";
        return;
    }

    long double a=1, b=1, c=*f.begin();

    a*=sumx; b*=sumy,
    a/=n, b/=n, c=sqrt(c)*n;

    cout<<fixed<<setprecision(8)<<x<<' '<<y<<'\n'<<c;

    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t=1;
    //cin>>t;

    while(t--)solve();

    return t+1;
}
