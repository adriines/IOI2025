#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int t,n,c; cin>>t>>n>>c; 
    vector<int>largo(n,0);
    for(int i=0;i<t;i++){
        int x; cin>>x;
        largo[x-1]++;
    }
    vector<vector<ll>>volumen(n,vector<ll>(c+1,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<=c;j++){
            if(j<largo[i]){
                int p=largo[i]/(j+1); //1e6
                int a=largo[i]%(j+1);
                ll vol=(j+1)*p*(p+1)/2;
                vol+=a*(p+1);
                volumen[i][j]=vol;
            }
        }
    }
    for(auto v: volumen){
        //for(ll x: v) cout<<x<<" ";
        //cout<<"\n";
    }

    vector<vector<ll>>dp(n+1,vector<ll>(c+1,1e18)); 
    dp[0][0]=0;
    for(int i=1;i<=n;i++){ //para cada edificio
        for(int j=0;j<=c;j++){ // j cortes;
            for(int k=0;k<=j;k++){ // formas de alcanzar la suma j
                if(volumen[i-1][k]==-1){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]);
                    continue;
                }
                dp[i][j]=min(dp[i][j],dp[i-1][j-k]+volumen[i-1][k]);

            }
        }
    }

    for(auto v: dp){
        //for(ll x: v) cout<<x<<" ";
        //cout<<"\n";
    }

    cout<<dp[n][c];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}