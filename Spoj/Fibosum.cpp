#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll binpow(vector<vector<ll>>a,ll b){
    vector<vector<ll>>res;
    res.push_back({1,0});
    res.push_back({0,1});
    while(b){
        if(b&1){
            vector<vector<ll>>aux(2,vector<ll>(2));
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
        vector<vector<ll>>aux(2,vector<ll>(2));
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
    ll l, r; cin>>l>>r;
    vector<vector<ll>>a;
    a.push_back({1,1});
    a.push_back({1,0});
    r=binpow(a,r+2);
    a.clear();
    a.push_back({1,1});
    a.push_back({1,0});
    l=binpow(a,l+1);
    cout<<(r-l+MOD)%MOD<<"\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}