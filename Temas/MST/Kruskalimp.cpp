#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int v,e;
vector<int>parent;
int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}
void Union(int u, int v){
    int a=find(u);
    int b=find(v);
    if(a!=b) parent[a]=b;
    
}

void solve(){
    cin>>v>>e;
    parent.resize(v);
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    vector<tuple<int,int,int>>el(e);
    for(int i=0;i<e;i++){
        int u,v,w; cin>>u>>v>>w;
        el[i]={w,u,v};
    }
    sort(el.begin(),el.end());

    int wt=0,ne=0;
    for(auto it:el){
        int w = get<0>(it); 
        int u = get<1>(it); 
        int v = get<2>(it); 
        if(find(u)==find(v)) continue;
        wt+=w;
        ne++;
        Union(u,v);
        if(ne==v-1) break;
    }
    cout<<wt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}