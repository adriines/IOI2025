#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;

bool valido(string st){
    int r=0,n=st.size();
    int cont=0;
    bool b=true;
    for(char c: st){
        if(c=='(') cont++;
        else cont--;
        if(cont<0) b=false;
    }
    if(cont==0 && b) return 1;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string s=st;
            for(int k=i;k<=j;k++){
                if(s[k]=='(') s[k]=')';
                else if(s[k]==')') s[k]='(';
            }
            int cont=0;
            bool b=true;
            for(char c: s){
                if(c=='(') cont++;
                else cont--;
                if(cont<0) b=false;
            }
            if(cont==0 && b) return 1;
            
        }
    }
    return 0;
   
}
ll cambios(string s, int i){
    if(i==s.size()){
        return valido(s);
    }
    if(s[i]!='x') return cambios(s,i+1);
    ll cont=0;
    s[i]='(';
    cont=(cont+cambios(s,i+1))%MOD;
    s[i]=')';
    cont=(cont+cambios(s,i+1))%MOD;

    return cont%MOD;
}
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    if(n&1){
        cout<<0;
        return;
    }
    ll ans=0;
    ans=cambios(s,0);
    cout<<ans%MOD;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}