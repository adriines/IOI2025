#include<bits/stdc++.h>
using namespace std;
int N=1000; //Head ->color
int size[N],chainI[N],Headc[N],pos[N];//a que cadena pertenece, cabeza de la cadena
int chain=0;
void dfs(int u, int p){
    size[u]=1;
    for(int v: adj[u]){
        if(v!=p){
            size[u]+=size[p];
        }
    }
}
void hld(int cur,int parent){
    chainI[cur]=chain;
    if(Headc[cur]==-1) Headc[cur]=chain;
    ///???
    int hchild=-1,Msize=0;
    for(int x: adj[cur]){
        if(Msize<size[x]){
            Msize=size[x];
            hchild=x;
        }
    }
    if(hchild!=-1){
        hld(hchild,cur);
    }
    for(int x:adj[cur]){
        if(hchild!=x && x!=parent){
            chain++;
            hld(x,cur);
        }
    }
}
int head(int x){
    return Headc[chainI[x]];
}
void path(int x, int y){
    if(dep[x]>dep[y]) swap(x,y);
    int res=-1;
    while(head(x)!=head(y)){
        res=max(res,querie(pos[head(y)],pos[y]));
    }
    if(dep[x]>dep[y]) swap(x,y);
    res=max(res,querie(pos[x],pos[y]));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}