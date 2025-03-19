#include<bits/stdc++.h>
using namespace std;
vector<vector<string>>res(100);
void init(){
    res[3]={"169","196","961"};
    for(int i=5;i<=99;i+=2){
        vector<string>antes=res[i-2];
        for(string x: antes){
            string s=x+"00";
            res[i].push_back(s);
        }
        string s1="1";
        for(int j=0;j<(i-3)/2;j++){
            s1=s1+"0";
        }
        s1=s1+"6";
        for(int j=0;j<(i-3)/2;j++){
            s1=s1+"0";
        }
        s1=s1+"9";
        res[i].push_back(s1);
        s1.clear();

        s1="9";
        for(int j=0;j<(i-3)/2;j++){
            s1=s1+"0";
        }
        s1=s1+"6";
        for(int j=0;j<(i-3)/2;j++){
            s1=s1+"0";
        }
        s1=s1+"1";
        res[i].push_back(s1);

    }

}
void solve(){
    int n; cin>>n;
    if(n==1) cout<<"1\n";
    else{
        for(string s: res[n]){
            cout<<s<<"\n"; 
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}