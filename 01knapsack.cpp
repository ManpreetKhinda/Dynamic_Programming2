#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include<numeric>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii vector<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
int f(int i, int w, vi&wt, vi&val,vvi &dp){
    if(i==0){
        if(wt[0]<=w)return val[0];
        return 0;
    }
    if(dp[i][w]!=-1)return dp[i][w];
    int nottake=f(i-1,w,wt,val,dp);
    int take=INT_MIN;
    if(wt[i]<=w)take=val[i]+f(i-1,w-wt[i],wt,val,dp);
    return dp[i][w]=max(take,nottake);
}
int knapsack(vi &wt, vi&val, int n, int w){
    // vvi dp(n, vi(w+1,-1));
    // return f(n-1,w, wt,val,dp);
    vvi dp(n, vi(w+1,0));
    for(int W=wt[0];W<=w;W++)dp[0][W]=val[0];
    for(int i=1;i<n;i++){
        for(int W=0;W<=w;W++){
            int nottake=dp[i-1][W];
            int take=INT_MIN;
            if(wt[i]<=w)take=val[i]+dp[i-1][w-wt[i]];
            dp[i][w]=max(take,nottake);
        }
    }
    return dp[n-1][w];
}
int knapsackopti(vi &wt, vi&val, int n, int w){
    // vvi dp(n, vi(w+1,-1));
    // return f(n-1,w, wt,val,dp);
    vi prev(w+1,0),curr(w+1,0);
    for(int W=wt[0];W<=w;W++)prev[W]=val[0];
    for(int i=1;i<n;i++){
        for(int W=0;W<=w;W++){
            int nottake=prev[W];
            int take=INT_MIN;
            if(wt[i]<=W)take=val[i]+prev[W-wt[i]];
            curr[W]=max(take,nottake);
            /* no need of curr can use the prev instead*/
        }
        prev=curr;
    }
    return prev[w];
}
/* 0 N knapsack*/
int fknap(int i, int w,vi&val, vi&wt, vvi &dp){
    if(i==0){
        return ((int)(w/wt[0]))*val[0];
    }
    if(dp[i][w]!=-1)return dp[i][w];
    int nottake=fknap(i-1, w,val,wt,dp);
    int take=0;
    if(wt[i<=w])take=fknap(i,w-wt[i],val,wt,dp);
    return dp[i][w]=max(take,nottake);
}

int unboundedknap(int n, int w, vi& val, vi &wt){
    // vvi dp(n, vi(w+1,-1));
    // return fknap(n-1,w,val,wt,dp);


    // vvi dp(n, vi(w+1,0)); 
    // for(int W=0;W<=w;W++)dp[0][W]=((int)(W/wt[0]))*val[0];
    // for(int i=1;i<n;i++){
    //     for(int W=0;W<=w;W++){
    //         int nottake=dp[i-1][W];
    //         int take=0;
    //         if(wt[i]<=W)take=dp[i][W-wt[i]];
    //         return dp[i][W]=max(take,nottake);
    //     }
    // }
    // return dp[n-1][w];

    vi prev(w+1,0);
    for(int W=0;W<=w;W++)prev[W]=((int)(W/wt[0]))*val[0];
    for(int i=1;i<n;i++){
        for(int W=0;W<=w;W++){
            int nottake=prev[W];
            int take=0;
            if(wt[i]<=W)take=prev[W-wt[i]];
            prev[W]=max(take,nottake);
        }
    }
    return prev[w];
}

/* given coint denominations form sum t*/
int f(int i, int t, vi &coins, vvi&dp){
    if(i==0){
        if(t%coins[0]==0)return t/coins[0];
        return 1e8;
    }
    if(dp[i][t]!=-1)return dp[i][t];
    int nottake=f(i-1, t,coins,dp);
    int take=INT_MAX;
    if(coins[i]<=t)take=1+f(i, t-coins[i], coins,dp);
    return min(take,nottake);
}
int minimumcoins(vi &coins, int target){
    // int n=coins.size();
    // vvi dp(n,vi(target+1,-1));
    // int ans=f(n-1,target,coins,dp);
    // if(ans>=1e9)return -1;
    // return ans;
    int n=coins.size();
    vvi dp(n, vi(target+1,0));
    for(int t=0;t<=target;t++){
        if(t%coins[0]==0)dp[0][t]=t/coins[0];
        else dp[0][t]=1e9;
    }
    for(int i=1;i<n;i++){
        for(int t=0;t<=target;t++){
            int nottake=dp[i-1][t];
            int take=INT_MAX;
            if(coins[i]<=t)take=1+dp[i][t-coins[i]];
            dp[i][t]=min(take,nottake);
        }
    }
    int ans=dp[n-1][target];
    if(ans>=1e9)return -1;
    return ans;
}
int minimumcoins(vi &coins, int target){
    
    int n=coins.size();
    vi prev(target+1,0), curr(target+1,0);
    for(int t=0;t<=target;t++){
        if(t%coins[0]==0)prev[t]=t/coins[0];
        else prev[t]=1e9;
    }
    for(int i=1;i<n;i++){
        for(int t=0;t<=target;t++){
            int nottake=prev[t];
            int take=INT_MAX;
            if(coins[i]<=t)take=1+curr[t-coins[i]];
            curr[t]=min(take,nottake);
        }
        prev=curr;
    }
    int ans=prev[target];
    if(ans>=1e9)return -1;
    return ans;
}
/*count number of ways to achieve a target*/
int fcountways(int i, int t, vi&a, vvi&dp){
    if(i==0)return (t%a[0]==0);
    if(dp[i][t]!=-1)return dp[i][t];
    int nottake=fcountways(i-1,t, a,dp);
    int take=0;
    if(a[i]<=t)take=f(i,t-a[i],a,dp);
    return dp[i][t]=take+nottake;
}
int countways(vi&a, int n, int t){
    // vvi dp(n, vi(t+1,-1));
    // return fcountways(n-1,t,a);
    /*
    vector<long long int > dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=sum;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[sum];
    */
    vvi dp(n,vi(t+1,0));
    for(int T=0;T<=t;T++)dp[0][T]=(T%a[0]==0);
    for(int i=1;i<n;i++){
        for(int T=0;T<=t;T++){
            int nottake=dp[i-1][t];
            int take=0;
            if(a[i]<t)take=dp[i][t-a[i]];
            dp[i][t]=take+nottake;
        }
    }
    return dp[n-1][t];
}

/* rod cutting*/
int fcutrod(int i, int n, vi &prices, vvi &dp){
    if(i==0)return n*prices[0];
    if(dp[i][n]!=-1)return dp[i][n];
    int nottake=fcutrod(i-1,n,prices,dp);
    int take=INT_MIN;
    int rodlength=i+1;
    if(rodlength<=n)take=prices[i]+fcutrod(i,n-rodlength, prices,dp);
    return dp[i][n]= max(take, nottake);
}
int cutrod(vi&prices, int n){
    // vvi dp(n, vi(n+1,-1));
    // return fcutrod(n-1,n, prices,dp);
    vvi dp(n, vi(n+1,0));
    for(int i=0;i<n;i++)dp[0][i]=i*prices[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int nottake=dp[i-1][j];
            int take=INT_MIN;
            int rodlength=i+1;
            if(rodlength<=n)take=prices[i]+dp[i][j-rodlength];
            dp[i][n]= max(take, nottake);
        }
    }
    return dp[n-1][n];
}