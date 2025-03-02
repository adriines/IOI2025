#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n,ans=-1; cin>>n;
    string s; cin>>s;
    for(int i=0;i<(n-2);i++){
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
            ans=i+1;
            break;
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