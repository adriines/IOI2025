#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
int T[4*N];
vector<int>a(1e6,1e9+5);
// l^r limites del array original a
void build(int i, int l, int r){ // i->ST
    if(l==r){
        T[i]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(2*i+1,l,m);
    build(2*i+2,m+1,r);  //que hace i??
    T[i]=min(T[2*i+1],T[2*i+2]);
}
int querie(int i, int l, int r, int lq, int rq){
    if(lq>r || rq<l) return 1e9+5;
    if(l>=lq && r<=rq) return T[i];//lq l r rq
    int m=(l+r)/2;
    return min(querie(2*i+1,l,m,lq,rq),querie(2*i+2,m+1,r,lq,rq)); //sumar ambas queries

}
void update(int pos, int i, int l, int r, int v){ //i->ST pos->a
    if(l==r){
        T[i]+=v;
        return; //return
    }
    int m=(l+r)/2;
    if(pos<=m) update(pos,2*i+1,l,m,v); //condicional pos
    else update(pos,2*i+2,m+1,r,v);    // dif: pos-i
    T[i]=min(T[2*i+1],T[2*i+2]);
}
void solve(){
   int n,q; cin>>n>>q;
   for(int i=1;i<=n;i++){
        cin>>a[i];
   }
   build(0,1,n);
   while(q--){
    int a,b; cin>>a>>b;
    cout<<querie(0,1,n,a,b)<<"\n";
   }
   
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}