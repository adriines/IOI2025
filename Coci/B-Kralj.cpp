#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n; cin>>n;
    set<int>mejor;
    vector<int>contra(n),f(n),f1(n);
    for(int &x: contra) cin>>x;
    for(int &x: f) cin>>x;
    for(int &x: f1){
        cin>>x;
        mejor.insert(x);
    }
    sort(f.begin(),f.end());
    int ans=0;
    for(int x: f){
        auto it=mejor.upper_bound(x);
        if(it!=mejor.end()){
            ans++;
            mejor.erase(it);
        }
    }
    cout<<ans;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}