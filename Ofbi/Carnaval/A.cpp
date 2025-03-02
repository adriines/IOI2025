#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int l,r,c; cin>>l>>r>>c;
    int aux=r/c;
    if(l>aux*c) cout<<"-1\n";
    else cout<<aux*c<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}