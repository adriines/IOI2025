#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    while(cin>>n && n!=0){
        vector<int>v(n);
        for(int &x: v) cin>>x;
        int ans=0, sum=0, maxsum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            maxsum=max(maxsum,sum);
            if(sum<0) sum=0;
        }
        if(maxsum==0) cout<<"Losing streak.\n";
        else cout<<"The maximum winning streak is "<<maxsum<<".\n";
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}