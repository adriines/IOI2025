#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int T[4*N];
vector<int>a(1e6,1e9+5);
void build(int i, int l, int r){
    if(l==r){
        T[i]=a[l];
        return;
    }
    int m=(l+r)/2; //Intervalos
    build(2*i+1,l,m);
    build(2*i+2,m+1,r);
    T[i]=min(T[2*i+1],T[2*i+2]);
}
void update(int pos, int i, int l, int r, int v){
    if(l==r){
        T[i]=v;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m) update(pos, 2*i+1,l,m,v);
    else update(pos, 2*i+2,m+1,r,v);
    T[i]=min(T[2*i+1],T[2*i+2]);
}
int querie(int i, int l, int r, int lq, int rq){
    if(r<lq || rq<l) return 1e9+5;
    if(lq<=l && rq>=r) return T[i];  
    int m=(l+r)/2;
    return min(querie(2*i+1,l,m,lq,rq),querie(2*i+2,m+1,r,lq,rq));
}

void solve(){
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(0,1,n);
    while(q--){
        int t; cin>>t;
        if(t==1){
            int pos,v; cin>>pos>>v;
            update(pos,0,1,n,v);
        }
        else{
            int a,b; cin>>a>>b;
            cout<<querie(0,1,n,a,b)<<"\n";
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