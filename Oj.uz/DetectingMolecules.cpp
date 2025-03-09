#include "molecules.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
std::vector<int> find_subset(int l, int u, std::vector<int> w) {
    int n=w.size(),Ri=0,j=0;
    long long sum=0;
    vector<pair<int,int>>sw(n);
    for(int i=0;i<n;i++){
        sw[i]={w[i],i};
    }
    sort(sw.begin(),sw.end());
    bool b=false;
    for(int i=0;i<n;i++){
        while(j<n && sum<l){
            sum+=sw[j].first;
            j++;
        }
        if(sum<=u && sum>=l){
            Ri=i;
            b=true;
            break;
        }
        else{
            sum-=sw[i].first;
        }
    }
    vector<int>ans;
    if(b){
        for(int i=Ri;i<j;i++){
            ans.push_back(sw[i].second);
        }
        return ans;

    }
    return std::vector<int>(0);
}