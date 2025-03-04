#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool>prime(2e8+1,1);
void init(){
    prime[0]=prime[1]=0;
    for(int i=2;i<=2e4;i++){
        if(prime[i]){
            for(ll j=i*i; j<=2e8;j+=i){
                prime[j]=0;
            }
        }
        
    }
}

void solve(){
    ll ans=0;
    for(ll i=1;i<=1e8;i++){
        bool b=true;
        for(ll j=1;j*j<=i;j++){
            if(i%j==0){
                ll d=i/j;
                if(!prime[j+i] && !prime[d+j]){
                    b=false;
                    break;
                }
            }
        }
        if(b) ans+=i;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}