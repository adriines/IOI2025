#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int pos(char c){
    if(c=='a') return 0;
    if(c=='e') return 1;
    if(c=='i') return 2;
    if(c=='o') return 3;
    if(c=='u') return 4;
}
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int q; cin>>q;
    vector<vector<int>>r(n+1,vector<int>(5,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++){
            r[i][j]=r[i-1][j];
        }
        r[i][pos(s[i-1])]++;
    }
    
    for(int i=0;i<q;i++){
        int l,d; cin>>l>>d;
        vector<int>aux(5);
        for(int j=0;j<5;j++){
            aux[j]=r[d][j]-r[l-1][j];
            //cout<<j<<" "<<aux[j];
        }
        int ans=1e5;
        for(int j=0;j<5;j++){
            ans=min(ans,aux[j]);
        }
        cout<<ans+1<<"\n";
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}