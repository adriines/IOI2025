#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,k,s; cin>>n>>k>>s;
    int h=log2(k)+1;
    vector<vector<int>>padre(n+1,vector<int>(h+1));

    vector<int>v(n);
    vector<int>adj(n+1,-1);
    for(int &x: v) cin>>x;
    v.push_back(0);

    int sum=0,l=0;
    for(int i=0;i<=n;i++){
        if(v[i]>s){
            adj[i]=l;
            //cout<<i<<" "<<l<<endl;
            sum=0;
            l=i+1;
            continue;
        }
        sum+=v[i];
        //cout<<"S: "<<i<<" "<<sum<<endl;
        if(sum>s){
            adj[i]=l;
            //cout<<i<<" "<<l<<endl;
            sum=v[i];
            l=i;
        }
    }
    if(sum<=s) adj[n]=l;
    for(int i=0;i<=n;i++){
        if(adj[i]==-1) adj[i]=i;
    }
    for(int i=0;i<=n;i++){
        padre[i][0]=adj[i];
        for(int j=1;j<=h;j++){
            padre[i][j]=padre[padre[i][j-1]][j-1];           
        }
    }
    for(auto v: padre){
        //for(int x: v) cout<<x<<" ";
        //cout<<"\n";
    }

    int ans=0;
    for(int i=0;i<=n;i++){
        int a=0,kpos=i;
        int grupos=k;
        while(grupos){
            if(grupos&1){
                kpos=padre[kpos][a];
            }
            a++;
            grupos>>=1;
        }
        ans=max(ans,abs(kpos-i));
    }
    cout<<ans<<"\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}