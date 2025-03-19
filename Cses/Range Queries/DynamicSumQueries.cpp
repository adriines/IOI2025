#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6;
ll T[4*N];
vector<ll>a(1e6,0);
void build(ll i,ll l, ll r){
    if(l==r){
        T[i]=a[l];
        return;
    }
    ll m=(l+r)/2;
    build(2*i+1,l,m);
    build(2*i+2,m+1,r);
    T[i]=T[2*i+1]+T[2*i+2];
}
ll querie(ll i, ll l, ll r, ll lq, ll rq){
    if(l>rq || lq>r) return 0;
    if(lq<=l && r<=rq) return T[i]; // CONDICIONAAAAL
    ll m=(l+r)/2;
    return querie(2*i+1,l,m,lq,rq)+querie(2*i+2,m+1,r,lq,rq);
}
void update(ll pos, ll i, ll l, ll r, ll v){
    if(l==r){
        T[i]+=v;
        return;
    }
    ll m=(l+r)/2;
    if(pos<=m) update(pos,2*i+1,l,m,v);
    else update(pos,2*i+2,m+1,r,v);
    T[i]=T[2*i+1]+T[2*i+2];
}
void solve(){
    ll n,q; cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    build(0,1,n);
    while(q--){
        ll t; cin>>t;
        if(t==1){
            ll pos,v; cin>>pos>>v;
            update(pos,0,1,n,v-a[pos]); //Actualizar a
            a[pos]=v;
        }
        else{
            ll a,b; cin>>a>>b;
            cout<<querie(0,1,n,a,b)<<"\n";
        }
    }

    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}