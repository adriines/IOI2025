#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fenwick{
    vector<int>t;
    Fenwick(int n){
        t.resize(n+1,0);
    }
    void update(int pos, int val){
        while(pos<t.size()){
            t[pos]+=val;
            pos+=pos &-pos;
        }
    }
    int querie(int l){
        int s=0;
        while(l>0){
            s+=t[l];
            l-=l &-l;
        }
        return s;
    }
    int sum(int l, int r){
        return querie(r)-querie(l-1);
    }

};

void solve(){
    int n;
    bool b=false;
    int cont=1;
    while(cin>>n && n!=0){
        if(b) cout<<"\n";
        else b=true;
        cout<<"Case "<<cont<<":\n";
        vector<int>v(n);
        for(int &x: v) cin>>x;
        string s;
        Fenwick f(n);
        for(int i=0;i<n;i++){
            f.update(i+1,v[i]);
        }
        while(cin>>s && s!="END"){
            if(s=="S"){
                int pos,val; cin>>pos>>val;
                f.update(pos,val-v[pos-1]);
                v[pos-1]=val;
            }
            else{
                int x,y; cin>>x>>y;
                cout<<f.sum(x,y)<<"\n";
            }
        }
        cont++;
    }


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

}