#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string s; cin>>s;
    string aux;
    for(int i=0;i<s.size()-2;i++){
        aux=aux+s[i];
    }
    cout<<aux<<"i"<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}