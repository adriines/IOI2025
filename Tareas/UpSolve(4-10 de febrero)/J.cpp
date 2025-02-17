#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
void solve(){
    int n; cin>>n;
    vector<int>v(n);
    for(int &x: v) cin>>x;
    cout<<n/2<<"\n";
    for(int i=0;i<n;i++){
        if(!(i&1) && i+1<n){
            cout<<i+1<<" "<<i+2<<" "<<min(v[i],v[i+1])<<" "<<MOD<<"\n";
        }
    }


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}