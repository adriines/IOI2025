#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
   int n; cin>>n;
   map<ll,bool>mp;
   queue<pair<ll,int>>q;
   q.push({n,0});
   while(!q.empty()){
        int v=q.front().first;
        int p=q.front().second;
        q.pop();
        if(mp.count(v)) continue;
        mp[v]=true;
        if(v==0){
            cout<<p;
            return;
        }
        q.push({v-1,p+1});
        q.push({v+1,p+1});
        q.push({2*v,p+1});
        int exp=3;
        while(v%exp==0){
            exp*=3;
        }
        exp/=3;
        if(v%exp==0 and exp!=1) q.push({v/exp,p+1});
   }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}