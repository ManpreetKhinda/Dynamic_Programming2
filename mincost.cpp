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
int f(int i, int j, vector<int>&cuts, vector<vector<int>>&dp){
    if(i>j)return 0;
    int mini=INT_MAX;
    if(dp[i][j]!=-1)return dp[i][j];
    for(int k=i;k<=j;k++){
        int cost=cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
        mini=min(mini,cost);
    }
    return dp[i][j]= mini;
}
int cost(int n, int c, vector<int>&cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>>dp(c+1, vector<int>(c+1,-1));
    return f(1,c,cuts,dp);
}
int costtocut(int n,int c,vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>>dp(c+2, vector<int>(c+2,0));
    for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(i>j)continue;
            int mini=INT_MAX;
            if(dp[i][j]!=-1)return dp[i][j];
            for(int k=i;k<=j;k++){
                int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                mini=min(mini,cost);
            }
            dp[i][j]= mini;
        }
    }
}