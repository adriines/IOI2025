#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
void solve(){
    int n; cin>>n;
    vector<int>dp(n+1,1e6+5);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int m=1,a,x=n;
        //cout<<"I "<<endl;
        for(int j=1;j<=(int)log10(i)+1;j++){
            //cout<<j<<" ";
            a=i/m;
            x=i-(a%10);
            m*=10;
            dp[i]=min(dp[i],dp[x]+1);
            
        }
       
    }
    cout<<dp[n];

    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}