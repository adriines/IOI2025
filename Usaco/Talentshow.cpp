#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int c=1e9;

void solve(){
    int n,W,tt=0; cin>>n>>W;
    vector<int>v(n+1),w(n+1);
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
        tt+=v[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(tt+1,c));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=tt;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=v[i] && dp[i-1][j-v[i]]!=1e9){
                if(dp[i-1][j-v[i]]+w[i]<dp[i-1][j]){
                    dp[i][j]=dp[i-1][j-v[i]]+w[i];
                }
            }
        }
    }
    
    int ans=0;
    for(int i=1;i<=tt;i++){
        if(dp[n][i]>=W){
            ans=max(ans,(1000*i)/dp[n][i]);
        }
    }
    cout<<ans;

}
int main(){
    freopen("talent.in","r",stdin);
    freopen("talent.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}