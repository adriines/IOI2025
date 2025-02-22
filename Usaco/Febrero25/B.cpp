#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n; cin>>n;
    vector<int>v(n,0);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mp[x]++;
    }
    if(mp[0]>0) v[0]=1;
    for(int i=1;i<n;i++){
        if(mp[i]>0) v[i]=v[i-1]+1;
        else v[i]=v[i-1];
        //cout<<v[i]<<endl;
    }

    cout<<mp[0]<<"\n";
    for(int i=1;i<=n;i++){
        int r=i-v[i-1];
        cout<<max(mp[i],r)<<"\n";
    }


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}