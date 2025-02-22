#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n,k; cin>>n>>k;
    vector<int>v(n);
    vector<int>aux;
    for(int &x: v) cin>>x;
    if(k==1 or n==1) cout<<"YES\n";
    else if(k==2){
        int f=n;
        int m=v[0];
        bool b=true;
        for(int i=1;i<n;i++){
            if(v[i]==m && v[i-1]!=m && b){
                f=i;
                b=false;
            }
        }
        for(int i=0;i<f;i++){
            aux.push_back(v[i]);
        }
        if(n%aux.size()!=0){
            cout<<"NO\n";
            return;
        }
        bool r=true;
        for(int i=0;i<n;i++){
            if(v[i]!=aux[i%aux.size()]) r=false;
        }
        if(r) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}