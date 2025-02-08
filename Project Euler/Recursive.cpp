#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll binpow(ll a, ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}

ll valor(ll n){
    ll r,s;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n&1){
        s=n-1;
        s=s>>1;
        r=valor(s)-3*valor(s+1);
    }
    else{
        s=n>>1;
        r=2*valor(s);
    }
    return r;
}
void solve(){
    ll n,ans,c; 
    n=binpow(5,12);
    ans= valor(n);
    c=binpow(2,11);
    ans=ans*c;
    ans=4-ans;
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}