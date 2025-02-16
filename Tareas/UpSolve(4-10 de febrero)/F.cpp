#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    unordered_map<char,int>mp;
    unordered_map<char,int>v;
    for(int i=0;i<n;i++){
        char c=s[i];
        mp[c]++;
    }
    int y,x;
    bool b=true;
    y=abs(mp['N']-mp['S']);
    if(y&1) b=false;
    x=abs(mp['E']-mp['W']);
    if(x&1) b=false;
    //cout<<x<<" "<<y<<" "<<min(mp['N'],mp['S'])<<" "<<min(mp['E'],mp['W'])<<"\n";
    if(b){
        if(x+y+min(mp['N'],mp['S'])+min(mp['E'],mp['W'])<=1) b=false;
        if(b){
            if(x+y==0){
                if(min(mp['N'],mp['S'])>0){
                    v['N']=v['S']=1;
                }
                else{
                    v['E']=v['W']=1;
                }
            }
            else{
                if(mp['N']>mp['S']){
                    v['N']=y/2;
                }
                else v['S']=y/2;
                if(mp['E']>mp['W']){
                    v['E']=x/2;
                }
                else v['W']=x/2;
            }
        }
    }
    if(b){
        for(int i=0;i<n;i++){
            if(v[s[i]]==0) cout<<"R";
            else{
                cout<<"H";
                v[s[i]]--;
            }
        }
        cout<<"\n";
    }
    else cout<<"NO\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}