#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n,m,q,s;
    priority_queue<pair<int,int>>pq;
    while(cin>>n>>m>>q>>s && (n!=0 || m!=0 || q!=0 || s!=0) ){
        //cout<<n<<"\n";
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dis(n,1e9+5);
        while(m--){
            int u,v,w; cin>>u>>v>>w;
            adj[u].push_back({v,w});
            //adj[v].push_back({u,w});
        }
        dis[s]=0;
        pq.push({-dis[s],s});
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto p: adj[u]){
                if(dis[u]+p.second<dis[p.first]){
                    dis[p.first]=dis[u]+p.second;
                    pq.push({-dis[p.first],p.first});
                }
            }
            
        }
        while(q--){
            int v; cin>>v;
            //cout<<v<<"\n";
            if(dis[v]!=1e9+5) cout<<dis[v]<<"\n";
            else cout<<"Impossible\n";
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}