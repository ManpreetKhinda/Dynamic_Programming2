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

/*minimum path sum in a grid*/
int f(int i, int j, vvi &grid, vvi &dp){
    if(i==0 &&j==0)return grid[i][j];
    if(i<0||j<0)return INT_MAX;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=grid[i][j]+f(i-1,j,grid,dp);
    int left=grid[i][j]+f(i,j-1,grid,dp);
    return dp[i][j]= min(left,up);
}
int minsum(vvi &grid){
    int n=grid.size();
    int m=grid[0].size();
    vvi dp(n,vi(m,0));
    // return f(n-1,m-1,grid,dp);
    vi prev(m,0);
    for(int i=0;i<n;i++){
        vi curr(m,0);
        for(int j=0;j<m;j++){
            if(i==0||j==0)curr[j]=grid[i][j];
            else{
                int up=grid[i][j];
                if(i>0)up+=prev[j];
                else up+=1e9;
                int left=grid[i][j];
                if(j>0)left+=curr[j-1];
                else up+=1e9;
                curr[j]=min(left,up);
            }
        }
        prev=curr;
    }
    return prev[m-1];
    
}