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

using namespace std;

void value(ll in){cout<<((in)?"YES\n":"NO\n");}

const ll N=2e5+5, M=3e3+5, mod=998244353, md=1e9+7, inf=1e18;

ll n, m, k;
ll ans;

vector<pair<int, int>> tr(string& s){
    vector<pair<int, int>> ans; ans.reserve(n);

    while(true){
        int i, j=0;
        for(i=0; i<n; i++){
            if(s[i]=='1')continue;
            j=i+1;
            while(j<n && s[j]=='1')j++;
            break;
        }
        if(i==n)break;
        if(j!=n){
            ans.push_back({i, j});
            for(int h=i; h<=j; h++){
                s[h]='1'+'0'-s[h];
            }
            continue;
        }
        if(i<=1)ans.push_back({i+1, n-1}), ans.push_back({i, n-1});
        else ans.push_back({0, i-1}), ans.push_back({0, i});
        break;
    }

    return ans;
}

void solve(){
    cin>>n;
    string s, t;
    cin>>s>>t;
    if(s==t){
        cout<<"0\n";
        return;
    }

    if(n==2 && (s[0]!=s[1] || t[0]!=t[1])){
        cout<<"-1\n";
        return;
    }
    if(n==3 && ((s[0]!=s[1] && s[0]==s[2]) || (t[0]!=t[1] && t[0]==t[2]))){
        if((s[0]!=s[1] && s[0]==s[2]) && (t[0]!=t[1] && t[0]==t[2])){
            cout<<"1\n1 3\n";
        }
        else cout<<"-1\n";
        return;
    }
        
    vector<pair<int, int>> a=tr(s), b=tr(t);;
    reverse(all(b));

    for(auto& u:b)a.push_back(u);
    cout<<a.size()<<"\n";
    for(auto& [l, r]:a)cout<<l+1<<' '<<r+1<<"\n";

    
    return;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t=1; 
    cin>>t;
    
    while(t--)solve();

    return t+1;
}