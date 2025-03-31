#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>mp1,mp;
void init(){
    double temp=0;
    for(int i=1;i<=7;i++){
        temp+=log10(i);
    }
    for(int i=8;i<=1e6;i++){
        temp+=log10(i);
        ll d=temp;
        //if(i==8) cout<<d;
        mp[d+1]=i;
    }
    //cout<<mp[5]<<"\n";


}
void solve(){
    string n;
    while(cin>>n){
        if(n=="1") cout<<"1\n";
        else if(n=="2") cout<<"2\n";
        else if(n=="6") cout<<"3\n";
        else if(n=="24") cout<<"4\n";
        else if(n=="120") cout<<"5\n";
        else if(n=="720") cout<<"6\n";
        else if(n=="5040") cout<<"7\n";
        else cout<<mp[n.size()]<<"\n";

    }
    
        
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}