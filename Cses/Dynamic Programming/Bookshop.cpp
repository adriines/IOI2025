#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,x; cin>>n>>x;
    vector<ll>c(n),v(n);
    vector<vector<ll>>dp(n+1,vector<ll>(x+1,0));
    for(ll &x: c) cin>>x;
    for(ll &x: v) cin>>x;

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=x;j++){
            if(j-c[i-1]>=0) dp[i][j]=max(dp[i-1][j-c[i-1]]+v[i-1],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    for(auto v: dp){
        //for(ll x: v) cout<<x<<" ";
        //cout<<"\n";
    }
    cout<<dp[n][x];

}
int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    solve();
}