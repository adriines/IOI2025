#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,g; cin>>n>>g;
    vector<int>v(n),dp(n,0); 
    for(int &x: v) cin>>x;
    dp[0]=v[0];
    for(int i=0;i<n;i++){
        int maxv=0;
        for(int k=i;k<min(i+g,n);k++){
            maxv=max(maxv,v[k]);
            if(i!=0) dp[k]=max(dp[k],dp[i-1]+maxv*(k-i+1));
            else dp[k]=max(dp[k],maxv*(k-i+1));
        }
    }
    cout<<dp[n-1];

}
int main(){
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}