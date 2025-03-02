#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int t,tx=0,ty=0,tz=0; cin>>t;
    while(t--){
        int x,y,z; cin>>x>>y>>z;
        tx+=x;
        ty+=y;
        tz+=z;
    }
    if(tx==0 && ty==0 && tz==0) cout<<"YES\n";
    else cout<<"NO\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}