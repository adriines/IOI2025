#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string s; cin>>s;
    bool b=false;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            b=true;
            break;
        }
    }
    if(b) cout<<"1\n";
    else cout<<s.size()<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}