#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,sum=0,o,pos; cin>>n;
    vector<ll>v(n);
    for(ll &x: v){
        cin>>x;
        sum+=x;
    }
    cin>>o;
    pos=n*(ll)(o/sum);
    sum*=(ll)(o/sum);
    //cout<<sum<<" "<<pos<<"\n";
    for(ll i=0;i<n;i++){
        if(sum<=o){
            sum+=v[i];
            pos++;
        }
        else break;
    }
    cout<<pos;


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}