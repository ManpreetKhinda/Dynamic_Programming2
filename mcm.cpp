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

int f(int i,int j, vector<int>&arr,vector<vector<int>>&dp){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}
int mcm(vector<int>&arr,int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(1,n-1,arr,dp);
}
int mcmtab(vi&arr, int n){
    int dp[n][n];
    for(int i=0;i<n;i++)dp[i][i]=0;
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini=1e9;
            for(int k=i;k<j;k++){
                int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini=min(mini,steps);
            }
            dp[i][j]=mini;
        }
    }
}