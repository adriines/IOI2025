#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n,t,ans=0; cin>>n>>t;
    unordered_set<int>s;
    while(t--){
        int x; cin>>x;
        if(s.find(x)!=s.end()){
            ans++;
            s.clear();
            s.insert(x);
        }
        else{
            if(x>0) s.insert(x);
            else s.erase(abs(x));
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