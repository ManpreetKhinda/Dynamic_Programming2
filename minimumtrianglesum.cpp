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
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii vector<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
int f(int i,int j, vvi&triangle, int n,vvi &dp){
    if(i==n-1)triangle[n-1][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int d=triangle[i][j]+f(i+1,j,triangle,n,dp);
    int dg=triangle[i][j]+f(i+1,j+1,triangle,n,dp);
    return  dp[i][j]=min(d,dg);
}
int minimum(vvi &triangle, int n){
    vvi dp(n,vi(n,-1));
    return f(0,0,triangle,n,dp);
}
int minimumtab(vvi&triangle, int n){
    // vvi dp(n,vi(n,0));
    // for(int i=0;i<n;i++)dp[n-1][i]=triangle[n-1][i];
    // for(int i=n-2;i>=0;i--){
    //     for(int j=i;j>=0;j--){
    //         int d=triangle[i][j]+dp[i+1][j];
    //         int dg=triangle[i][j]+dp[i+1][j+1];
    //         dp[i][j]=min(d,dg);
    //     }
    // }
    // return dp[0][0];
    vi front(n,0),curr(n,0);
    for(int i=0;i<n;i++)front[i]=triangle[n-1][i];
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j++){
            int d=triangle[i][j]+front[j];
            int dg=triangle[i][j]+front[j+1];
            curr[j]=min(d,dg);
        }
    }
    return front[0];


}