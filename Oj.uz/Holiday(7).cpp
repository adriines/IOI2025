#include"holiday.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long int findMaxAttraction(int n, int s, int D, int attraction[]) {
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        v[i]=attraction[i];
    }
    ll ans=0;
    for(int x=0;x<n;x++){
        ll d=D-abs(s-x);
        if(d>0){
        vector<vector<ll>>dp(n,vector<ll>(d+1,-1));
        dp[x][0]=0;
        dp[x][1]=v[x];
        for(ll i=x+1;i<n;i++){
            for(ll j=0;j<=d;j++){
                if(i-1>=0 && dp[i-1][j]!=-1){
                    if(j+2<=d){
                        dp[i][j+2]=max(dp[i][j+2], dp[i-1][j]+v[i]);
                        ans=max(ans,dp[i][j+2]);
                    }
                    if(j+1<=d){
                        dp[i][j+1]=max(dp[i][j+1], dp[i-1][j]);
                        ans=max(ans,dp[i][j+1]);
                    }
                }
            }
        }
       dp.clear();
       dp.assign(n,vector<ll>(d+1,-1));
        dp[x][0]=0;
        dp[x][1]=v[x];
        for(ll i=x-1;i>=0;i--){
            for(ll j=0;j<=d;j++){
                if(i+1<n && dp[i+1][j]!=-1){
                    if(j+2<=d){
                        dp[i][j+2]=max(dp[i][j+2], dp[i+1][j]+v[i]);
                        ans=max(ans,dp[i][j+2]);
                    }
                    if(j+1<=d){
                        dp[i][j+1]=max(dp[i][j+1], dp[i+1][j]);
                        ans=max(ans,dp[i][j+1]);
                    }
                }
            }
        }
        }
        

    }
    return ans;
}