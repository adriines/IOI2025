#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll binpow(vector<vector<ll>>a,ll b){
    vector<vector<ll>>res;
    res.push_back({1,0});
    res.push_back({0,1});
    while(b){
        vector<vector<ll>>aux(2,vector<ll>(2));
        if(b&1){
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    aux[i][j]=0;
                    for(int k=0;k<2;k++){
                        aux[i][j]+=res[i][k]*a[k][j];
                        aux[i][j]%=MOD;
                    }
                }
            }
            swap(aux,res);
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                aux[i][j]=0;
                for(int k=0;k<2;k++){
                    aux[i][j]+=a[i][k]*a[k][j];
                    aux[i][j]%=MOD;
                }
            }
        }
        swap(aux,a);
        b>>=1;

    }
    return res[0][1]%MOD;
}
void solve(){
    ll n,a,b; cin>>n;
    if(n<2){
        if(n==0) cout<<"0\n";
        if(n==1) cout<<"2\n";
        return;
    }
    vector<vector<ll>>f;
    f.push_back({1,1});
    f.push_back({1,0});
    a=binpow(f,n+3);
    cout<<a<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}