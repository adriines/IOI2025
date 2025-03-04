#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fenwick{
    vector<int>t;
    Fenwick(int n){
        t.assign(n+1,0);
    }
    void update(int pos, int val){
        while(pos<t.size()){
            t[pos]+=val;
            pos+=pos&-pos;
        };
    }
    ll querie(int r){
        int sum=0;
        while(r>0){
            sum+=t[r];
            r-=r&-r;
        }
        return sum;
    }
};
void solve(){
    int n; cin>>n;
    vector<ll>v(n);
    map<int,int>mp;
    for(ll &x: v){
        cin>>x;
        mp[x]=1;
    }
    ll cont=1;
    for(auto &it: mp){
        it.second=cont;
        cont++;
    }
    Fenwick f(n);
    vector<ll>ans(n,1);
    for(int i=n-1;i>=0;i--){
        ll x=0;
        if(mp[v[i]]>1) x=f.querie(mp[v[i]]-1);
        ans[i]*=x;
        f.update(mp[v[i]], 1); 
    }
    Fenwick f2(n);
    for(int i=0;i<n;i++){
        ll x=0;
        ll j=n-mp[v[i]]+1;
        if(j>1) x=f2.querie(j-1);
        ans[i]*=x;
        f2.update(j,1); 
    }
    ll r=0;
    for(ll x: ans) r+=x;
    cout<<r;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
