#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;

bool valido(string s){
    int cont=0;
    for(char c: s){
        if(c=='(') cont++;
        else cont--;
        if(cont<0) return 0;
    }
    return cont==0;
}
int cambios(string s, int i){
    if(i==s.size()){
        cout << "Probando: " << s << " -> " << valido(s) << endl; // Agrega esto
        return valido(s);
    }
    if(s[i]!='x') return cambios(s,i+1);

    int cont=0;
    s[i]='(';
    cont=(cont+cambios(s,i+1))%MOD;
    s[i]=')';
    cont=(cont+cambios(s,i+1))%MOD;
    s[i]='x';
    return cont;
}
void solve(){
    int n; cin>>n;
    string st; cin>>st;
    set<string>dif;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string s=st;
            for(int k=i;k<=j;k++){
                if(s[k]=='(') s[k]=')';
                if(s[k]==')') s[k]='(';
            }
            if(dif.count(s)) continue;
            dif.insert(s);
            ans=(ans+cambios(s,0))%MOD;
        }
    }
    cout<<ans;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}