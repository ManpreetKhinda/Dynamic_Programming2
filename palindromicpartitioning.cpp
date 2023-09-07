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
#include <climits>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii vector<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

bool ispalindrome(int i, int j, string&s){
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
}
int f(int i, int n, string &s,vector<int>&dp){
    if(i==n)return 0;
    int mincost=INT_MAX;
    if(dp[i]!=-1)return dp[i];
    for(int j=i;j<n;j++){
        if(ispalindrome(i,j,s)){
            int cost=1+f(j+1,n,s,dp);
            mincost=min(mincost,cost);
        }
    }
    return dp[i]=mincost;
}
int palindromicpartitioning(string&s){
    int n=s.size();
    vector<int>dp(n,-1);
    return f(0,n,s,dp)-1;
}

int palindromicpartitioningtab(string &s){
    int n=s.size();
    vector<int>dp(n+1,0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int mincost=INT_MAX;
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)){
                int cost=1+dp[j+1];
                mincost=min(mincost,cost);
            }
        }
        dp[i]=mincost;
    }
    return dp[0]-1;

}