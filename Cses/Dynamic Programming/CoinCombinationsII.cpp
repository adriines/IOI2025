#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
void solve(){
    int n,s; cin>>n>>s;
    vector<int>dp(s+1,0);
    vector<int>v(n);
    dp[0]=1;
    for(int &x: v) cin>>x;
   for(int x: v){
    for(int i=x;i<=s;i++){
        dp[i]=(dp[i]+dp[i-x])%MOD;
    }
   }
   cout<<dp[s];

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}