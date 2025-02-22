#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n,u; cin>>n>>u;
    vector<vector<int>>grid(n,vector<int>(n,0));
    vector<vector<int>>cont(n,vector<int>(n,0));
    vector<pair<int,int>>act;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c; cin>>c;
            if(c=='#') grid[i][j]=1;
        }
    }
    int t=u;
    while(t--){
        int i,j; cin>>i>>j;
        act.push_back({i-1,j-1});
    }

    int op=0;
    for(int i=0;i<n/2;i++){
        for(int j=n/2;j<n;j++){
            int c=grid[i][n-j-1]+ grid[n-i-1][j]+ grid[n-i-1][n-j-1]+ grid[i][j];
            if(c>2){
                op+=(4-c);
            }
            else{
                op+=c;
            }
        }
    }
    cout<<op<<"\n";

    for(int k=0;k<u;k++){
        int a=0,d=0;
        int i=act[k].first;
        int j=act[k].second;
        int c=grid[i][n-j-1]+ grid[n-i-1][j]+ grid[n-i-1][n-j-1]+ grid[i][j];
        if(c>2){
            a+=(4-c);
        }
        else{
            a+=c;
        }
        c=0;
        if(grid[i][j]==1) grid[i][j]=0;
        else grid[i][j]=1;
        
        c=grid[i][n-j-1]+ grid[n-i-1][j]+ grid[n-i-1][n-j-1]+ grid[i][j];
        if(c>2){
            d+=(4-c);
        }
        else{
            d+=c;
        }
        if(a>d) op--;
        else op++;
        cout<<op<<"\n";
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}