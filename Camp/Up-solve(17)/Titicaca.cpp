#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>>grid;
int dX[]={0,0,1,-1};
int dY[]={1,-1,0,0};
int n,m;
void dfs(int i,int j){
    if(grid[i][j]==false) return;
    grid[i][j]=false;
    for(int k=0;k<4;k++){
        int nX=i+dX[k],nY=j+dY[k];
        if(nX<n && nY<m && nX>=0 && nY>=0){
            if(grid[nX][nY]!=false) dfs(nX,nY);
        }
    }
}

void solve(){
    cin>>n>>m;
    grid.assign(n+1, vector<bool>(m+1, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin>>c;
            bool d = true;
            if (c == '0')
                d = false;
            grid[i][j]=d;
        }
    }
    for(int i=0;i<n;i++){
        if(grid[i][0]!=false){
            dfs(i,0);
        }
        if(grid[i][m-1]!=false){
            dfs(i,m-1);
        }
    }
    for(int i=0;i<m;i++){
        if(grid[0][i]!=false){
            dfs(0,i);
        }
        if(grid[n-1][i]!=false){
            dfs(n-1,i);
        }

    }
    int cont=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=false){
                cont++;
                dfs(i,j);
            }
        }
    }
    cout<<cont<<"\n";
}
int main(){
    solve();
    return 0;
}
///MALDITA N