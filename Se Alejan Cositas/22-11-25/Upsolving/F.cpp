// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
const long long md=1e9+7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
 
    auto mult = [](vector<vector<long long>>& a, vector<vector<long long>>& b){
        a={
            {(a[0][0]*b[0][0]+a[0][1]*b[1][0])%md, (a[0][0]*b[0][1]+a[0][1]*b[1][1])%md}, 
            {(a[1][0]*b[0][0]+a[1][1]*b[1][0])%md, (a[1][0]*b[0][1]+a[1][1]*b[1][1])%md}};        
    };
 
    function<long long(long long)> expbin = [&](long long y){
        vector<vector<long long>> x={{1, 1}, {1, 0}}, ans={{1, 0}, {0, 1}};
        while(y){
            if(y&1)mult(ans, x);
            mult(x, x);
            y/=2;
        }
        return ans[0][0];
    };
    
    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;
        cout<<expbin(2*n-2)<<"\n";
    }
    
    return t+1;
}
