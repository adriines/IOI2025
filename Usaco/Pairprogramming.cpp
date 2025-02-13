#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
void cambiar(string &s){
    string aux;
    for(char c: s){
        if(c=='1') continue;
        if(c=='0') aux.clear();
        if(c!='+') c='m';
        aux+=c;
    }
    s=aux;
}
void solve(){
    int n; cin>>n;
    string s1,s2; cin>>s1>>s2;
    cambiar(s1);
    cambiar(s2);

    vector<vector<vector<int>>>dp(s1.size()+1, vector<vector<int>>(s2.size()+1,vector<int>(2,0)));
    dp[0][0][0]=1;
    for(int i=0;i<=s1.size();i++){
        for(int j=0;j<=s2.size();j++){
            if(i<s1.size()){
                dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][0])%MOD; //bessie y bessie
            }
            if(j<s2.size()){
                dp[i][j+1][1]=(dp[i][j+1][1]+dp[i][j][1])%MOD; //elsie y elsie
            
                dp[i][j+1][1]=(dp[i][j+1][1]+dp[i][j][0])%MOD; //bessie y elsie
            }
            if(i<s1.size() && j>0 && s1[i]!=s2[j-1]){ //elsie y bessie (diferentes) 
                dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][1])%MOD;
            }
        }
    }
    int ans=(dp[s1.size()][s2.size()][0]+dp[s1.size()][s2.size()][1])%MOD;
    cout<<ans<<"\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}

 