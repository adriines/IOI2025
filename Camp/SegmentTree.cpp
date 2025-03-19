#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
int T[4*N];
vector<int>a;
void build(int i,int l, int r){
    if(l==r){
        T[i]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(2*i+1,l,m);
    build(2*i+2,m+1,r);
    T[i]=T[2*i+1]+T[2*i+2];
}
int querie(int i,int l, int r, int lq, int rq){
    if(lq>r || rq<l) return 0; //valor "neutro"
    if(l>=lq && r<=rq) return T[i]; //Revisar condicionales lq - (l r) - rq
    int m=(l+r)/2;
    return querie(2*i+1,l,m,lq,rq)+querie(2*i+2,m+1,r,lq,rq);
}
void update(int pos, int i, int l, int r, int v){ //void
    //i -> ST .... pos -> array(para actualizar)
    // Afecta solo donde esta, se "propaga" el valor
    if(l==r){
        T[pos]+=v;
        return;
    }
    int m=(l+r)/2;
    if(i<=m) update(pos,2*i+1,l,m,v);
    else update(pos,2*i+2,m+1,r,v);
    T[i]=T[2*i+1]+T[2*i+2];

}
void solve(){
   
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}