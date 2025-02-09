#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,m; cin>>n>>m;
    vector<ll>v(n),r(m);
    for(ll &x: v) cin>>x;
    for(ll &x: r) cin>>x;
    if(n==1){
        cout<<"YES\n";
        return;
    }
    sort(r.begin(), r.end());
    ll a=v[0];
    for(ll i=0;i<m;i++){
        a=min(a,r[i]-v[0]);
    }
    v[0]=a;

    for(ll i=1;i<n;i++){
        ll b=a+v[i];
        //cout<<a<<" "<<b<<endl;
        auto it=lower_bound(r.begin(),r.end(),b);
        if(it!=r.end() && v[i]!=a){
            //cout<<"E"<<" "<<*it<<endl;
            if(min(*it-v[i],v[i])>=a){
                v[i]=min(*it-v[i],v[i]);
            }
            else v[i]=max(*it-v[i],v[i]);
        }
        a=v[i];
    }
    
    bool ans=true;
    for(ll i=1;i<n;i++){
       if(v[i-1]>v[i]){
        ans=false;
        break;
       }
    }
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}