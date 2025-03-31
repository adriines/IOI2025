#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
   ll a,b; cin>>a>>b;
   if(a==1 or b==1) cout<<"1 1\n";
   else if(b%a==0 or a%b==0){
    cout<<min(a,b)<<" 1";
   }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}