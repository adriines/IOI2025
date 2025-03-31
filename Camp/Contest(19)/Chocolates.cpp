#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,k; cin>>k>>n;
    vector<int>c(n),d(n);
    bool f=true;
    for(int &x: d){
        cin>>x;
        if(x<0) f=false;
    }

    for(int &x: c) cin>>x;
    if(n==1){
        if(c[0]<k) cout<<"-1";
        else cout<<abs(d[0]);
        return;
    }

    vector<pair<ll,ll>>v(n);
    for(int i=0;i<n;i++){
        v[i]={d[i],c[i]};
    }
    sort(v.begin(),v.end());

    ll sum=0,ans=1e9+5,ans2=0;
    for(int i=0;i<n;i++){
        if(v[i].first<0) continue;
        sum+=v[i].second;
        if(k<=sum){
            ans=v[i].first;
            break;
        }
    }
    if(f){
        if(ans!=1e9+5) cout<<ans;
        else cout<<"-1";
    }
    else{
        sum=0;
        sum+=v[0].second;
        if(k<=sum){
            ans2+=abs(v[0].first);
            cout<<min(ans,ans2)<<"\n";
            return;
        }
        for(int i=1;i<n;i++){
            sum+=v[i].second;
            if(k<=sum){
                ans2=v[i].first;
                break;
            }
        }
        //cout<<sum<<" "<<ans<<" "<<ans2<<"\n";
        if(sum<k){
            cout<<"-1";
            return;
        }
        ans2+=2*abs(v[0].first);
        cout<<min(ans,ans2);

    }
    

   
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
