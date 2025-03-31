#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    while(cin>>n){
        vector<vector<int>>m(n+1,vector<int>(n+1,0));
        vector<vector<int>>prefix(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>m[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+m[i][j];
            }
        }
        ll maxsum=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int x=i;x<=n;x++){
                    for(int y=j;y<=n;y++){
                        ll sum=prefix[x][y]-prefix[i-1][y]-prefix[x][j-1]+prefix[i-1][j-1];
                        maxsum=max(maxsum,sum);
                        
                        
                    }
                }
            }
        }
        cout<<maxsum<<"\n";
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}