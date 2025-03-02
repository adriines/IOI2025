#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n; cin>>n;
    vector<ll>v(n);
    for(ll &x: v) cin>>x;
    ll s=0;
    ll ans=2*n-1;
    for(ll i=0;i<(n-2);i++){
        if(v[i+1]-v[i]==v[i+2]-v[i+1]) s++;
        else{
            ans+=(s*(s+1))/2;
            s=0;
        }
    }
    ans+=(s*(s+1))/2;
    cout<<ans;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}