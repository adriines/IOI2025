#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
void solve(){
    int n; cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0]!='*') dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='*') continue;
            if(i-1>=0) dp[i][j]+=dp[i-1][j]%MOD;
            if(j-1>=0) dp[i][j]+=dp[i][j-1]%MOD;
        }
    }
    cout<<dp[n-1][n-1]%MOD;
    

    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}