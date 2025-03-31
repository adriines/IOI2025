#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
   ll q; cin>>q;
   bool f=false; //cambiados
   ll x,y; cin>>x>>y;
   if((x%2==0 && y%2==0) or (x&1 && y&1)) f=true;
   //cout<<f<<"\n";
   while(q--){
    ll a,b;
    char c,ans; cin>>a>>b>>c;
    if(!f){
        if((a%2==0 && b%2==0) or (a&1 && b&1)) ans='B';
        else ans='N';
        //cout<<":)";
    }
    else{
        if((a%2==0 && b%2==0) or (a&1 && b&1)) ans='N';
        else ans='B';
    }
    //cout<<ans<<"\n";
    if(ans==c) cout<<"NO\n";
    else cout<<"SI\n";

   }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}