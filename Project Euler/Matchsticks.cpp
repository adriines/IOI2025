#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    vector<ll>dp(1e6+1,0);
    vector<ll>v={6,2,5,5,4,5,6,3,7,6};
    for(ll i=0;i<10;i++){
        dp[i]=v[i];
    }
    string n;
    for(ll i=10;i<=1e6;i++){
        n=to_string(i);
        for(char c: n){
            dp[i]+=dp[c-'0'];
        }
    }
    ll ans=0;
    for(ll i=10;i<=1e6;i++){
        for(ll j=2;j*j<=i;j++){
            if(i%j==0){
                ll x=i/j;
                dp[i]=min(dp[i],2+dp[x]+dp[j]);

            }
        }

    }
    for(ll i=1;i<=1e6;i++){
        if(dp[i]<=18){
            for(ll j=1;j<=1e6;j++){
                if(i+j>1e6){
                    break;
                }
                if(i+j>9) dp[i+j] = min(dp[i+j],2+dp[i]+dp[j]);
            } 
        }
    }
    ans=0;
    for(int i=1;i<=1e6;i++){
        ans+=dp[i];
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
