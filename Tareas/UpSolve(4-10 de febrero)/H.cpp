#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n; cin>>n;
    multiset<ll>ms;
    vector<ll>v(n);
    for(ll &x: v) cin>>x;
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum+=v[i];
        ms.insert(v[i]);
        if(sum<0){
            sum=sum-*ms.begin();
            ms.erase(ms.begin());
        }
    }
    cout<<ms.size();


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}