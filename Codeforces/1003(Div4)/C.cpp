#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,m; cin>>n>>m;
    vector<ll>v(n),aux(n);
    for(ll &x: v) cin>>x;
    ll r; cin>>r;
    if(n==1){
        cout<<"YES\n";
        return;
    }
    ll a;
    v[0]=min(r-v[0],v[0]);
    a=v[0];

    for(ll i=1;i<n;i++){
        if(min(r-v[i],v[i])>=a){
            v[i]=min(r-v[i],v[i]);
        }
        else v[i]=max(r-v[i],v[i]);
        a=v[i];
    }
    
    bool ans=true;
    for(ll i=1;i<n;i++){
       if(v[i-1]>v[i]){
        ans=false;
        break;
       }
    }
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}