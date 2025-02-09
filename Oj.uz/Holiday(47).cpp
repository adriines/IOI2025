#include"holiday.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long int findMaxAttraction(int n, int s, int d, int attraction[]) {
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        v[i]=attraction[i];
    }
    if(s==0){
        multiset<ll>ms;
        ll sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            ms.insert(v[i]);

            while(ms.size()>0 && ms.size()>d-i){
                sum-=*ms.begin();
                ms.erase(ms.begin());
            }
            ans=max(ans,sum);
        }
        return ans;
    }
    else{
        ll ans=0,dv;
        for(int i=0;i<n;i++){
            multiset<ll>ms;
            ll sum=0;
            for(int j=i;j<n;j++){
                sum+=v[j];
                ms.insert(v[j]);
                if(i<=s && j<=s){
                    dv=abs(s-i);
                }
                else if(i>=s && j>=s){
                    dv=abs(s-j);
                }
                else{
                    dv=2*abs(j-i)-max(abs(s-i),abs(s-j));
                }

                while(ms.size()>max(0ll,(d-dv))){
                    sum-=*ms.begin();
                    ms.erase(ms.begin());
                }
                ans=max(ans,sum);
            }

        }
        return ans;
    }

}