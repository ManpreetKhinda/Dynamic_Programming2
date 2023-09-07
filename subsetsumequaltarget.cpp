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
bool f(int i, int t, vi &arr, vvi&dp){
    if(t==0)return true;
    if(i==0)return (arr[0]==t);
    if(dp[i][t]!=-1)return dp[i][t];
    bool nottake=f(i-1,t, arr,dp);
    bool take=false;
    if(arr[i]<=t)take=f(i-1,t-arr[i], arr,dp);
    return dp[i][t]=take|nottake;

}

bool subsetsumequals(int n,int k, vi &arr){
    // vvi dp(n,vi(k+1,-1));
    // return f(n-1,k,arr,dp);
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)dp[i][0]=true;
    dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int t=1;t<=k;t++){
            bool nottake=dp[i-1][t];
            bool take=false;
            if(arr[i]<=t)take=dp[i-1][t-arr[i]];
            dp[i][t]=take|nottake;
        }
    }
    return dp[n-1][k];

}
bool subsetsumequalsopti(int n,int k, vi &arr){
    vector<bool> prev(k+1,0), curr(k+1,0);
    prev[0]=curr[0]=1;
    prev[arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int t=1;t<=k;t++){
            bool nottake=prev[t];
            bool take=false;
            if(arr[i]<=t)take=prev[t-arr[i]];
            curr[t]=take|nottake;
        }
        prev=curr;
    }
    return prev[k];
}

/* partition into minimal 2 subseq 
with minimal abs diff*/
int minimalsum(vi &arr){
    int s=accumulate(arr.begin(),arr.end(),0);
    vector<bool> prev(s+1,0), curr(s+1,0);
    prev[0]=curr[0]=0;
    prev[arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int t=1;t<=s;t++){
            bool nottake=prev[t];
            bool take=false;
            if(arr[i]<=t)take=prev[t-arr[i]];
            curr[t]=take|nottake;
        }
        prev=curr;
    }
    int mini=INT_MAX;
    for(int i=0;i<=s;i++){
        if(prev[i])mini=min(mini, abs(s-2*i));
    }
    return mini;
}
/*count all subsets of the given array with a sum equal to k*/
int perfectSum(int arr[], int n, int k)
	{
        // Your code goes here
    int mod=1e9+7;
    sort(arr,arr+n);
    reverse(arr,arr+n);
    vector<int> prev(k+1,0), curr(k+1,0);

    prev[0]=curr[0]=1;
    if(arr[0]<=k)prev[arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int t=0;t<=k;t++){
            int nottake=prev[t];
            int take=0;
            if(arr[i]<=t)take=prev[t-arr[i]];
            curr[t]=(take+nottake)%mod;
        }
        prev=curr;
    }
    return prev[k];
	}

/* given diff d, count number of diff in which
S1 is  greater than or equal to S2 and diff between 
s1 ans s2 is d

given an array of intergers and target,
built an expression out of '+','-',  such that
after doing operation its equal to target
*/
    int findTargetSumWays(vector<int>&arr ,int d) {
        int n=arr.size();
        int s=accumulate(arr.begin(), arr.end(),0);
        if(d>s||(s+d)%2)return 0;
        int s1=(s+d)/2;
        vector<int> prev(s1+1,0), curr(s1+1,0);
        if(arr[0]==0)prev[0]=2;
        else prev[0]=1;
        if(arr[0]!=0 && arr[0]<=s1) prev[arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int t=0;t<=s1;t++){
                int nottake=prev[t];
                int take=0;
                if(arr[i]<=t)take=prev[t-arr[i]];
                curr[t]=(nottake+take);
            }
            prev=curr;
        }
        
        return prev[s1];
    }

