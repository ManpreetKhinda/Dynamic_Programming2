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
int f(int i, int j, vvi &dp){
    if(i==0 && j==0)return 1;
    if(i<0 ||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=f(i-1,j,dp);
    int left=f(i,j-1,dp);
    return up+left;
}
int uniquepaths(int m, int n){
    vvi dp(m,vi(n,-1));
    return f(m-1,n-1,dp);
}
int uniquepathstab(int m ,int n){
    // int dp[m][n];
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         if(mat[i][j]==-1)dp[i][j]=0;
    //         else if(i==0 &&j==0)dp[i][j]=1;
    //         else{
    //             int up=0;
    //             int left=0;
    //             if(i>0)up=dp[i-1][j];
    //             if(j>0)left=dp[i][j-1];
    //             dp[i][j]=up+left;
    //         }
    //     }
    // }
    // return dp[m-1][n-1];
    vi prev(n,0);
    rep(i,0,m){
        vi curr(n,0);
        rep(j,0,n){
            if(i==0&&j==0)curr[j]=1;
            else {
                int up=0;
                int left=0;
                if(i>0)up=prev[j];
                if(j>0)left=curr[j-1];
                curr[j]=up+left;
            }
        }
        prev=curr;
    }
    return prev[n-1];
}