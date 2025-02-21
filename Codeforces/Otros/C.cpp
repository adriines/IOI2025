#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll binpow(vector<vector<ll>>a,ll b){
    vector<vector<ll>> res; //1,0 0,1
    res.push_back({1,0});
    res.push_back({0,1});
    while(b){
        if(b&1){
            //res*=a;
            vector<vector<ll>>aux(2,vector<ll>(2)); //tamaño
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
    ll n; cin>>n;
    vector<vector<ll>>a;
    a.push_back({1,1});
    a.push_back({1,0});
    cout<<binpow(a,n);

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}