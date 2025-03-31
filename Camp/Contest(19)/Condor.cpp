#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>>adj;
vector<vector<int>>up;
vector<int>dis,tin,tout;
int t=0;
void dfs(int u, int p, int d){
    tin[u]=++t;
    dis[u]=d;
    up[u][0]=p;
    for(int i=1;i<=20;i++){
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(int v: adj[u]){
        if(v!=p){
            dfs(v,u,d+1);
        }
    }
    tout[u]=++t;
}
bool ancestor(int u, int v){
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}
int lca(int u, int v){
    if(ancestor(u,v)) return u;
    else if(ancestor(v,u)) return v;
    else{
        for(int i=20; i>=0; i--){
            if(!ancestor(up[u][i],v)){
                //cout<<up[u][i]<<" "<<i<<"\n";
                u=up[u][i];
            }
        }
        return up[u][0];
    }
}
void solve(){
   int n,q; cin>>n>>q;
   up.assign(n+1,vector<int>(21));
   adj.resize(n+1);
   dis.resize(n+1);
   tin.resize(n+1);
   tout.resize(n+1);

   for(int i=1;i<n;i++){
    int a,b; cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   dfs(1,1,0);
   //cout<<lca(6,8);
   while(q--){
    int u,v; cin>>u>>v;
    //cout<<dis[u]<<" "<<dis[v]<<" "<<2*dis[lca(u,v)]<<"\n";
    ll ans=dis[u]+dis[v]-2*dis[lca(u,v)];
    cout<<ans<<"\n";
   }
   
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

