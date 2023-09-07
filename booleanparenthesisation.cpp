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
#define long long ll
int mod=1e9+7;
long long  f(int i, int j, string &s, ll req,vector<vector<vector<ll>>>&dp){
    if(i>j)return 0;
    if(i==j){
        if(req)return s[i]=='T';
        else return s[i]=='F';}
    ll ways =0;
    if(dp[i][j][req]!=-1)return dp[i][j][req];
    for(int k=i+1;k<=j-1;k+=2){
        ll lefttrue=f(i,k-1,s,1,dp);
        ll leftfalse=f(i,k-1,s,0,dp);
        ll righttrue=f(k+1,j,s,1,dp);
        ll rightfalse=f(k+1,j,s,0,dp);
        if(s[k]=='&'){
            if(req){
                ways=(ways+ (lefttrue*righttrue)%mod)%mod;}
            else ways=(ways+(lefttrue*rightfalse)%mod+(leftfalse*righttrue)%mod
            +(leftfalse*rigthfalse)%mod)%mod;}
        else if(s[k]=='|'){
            if(req){
                ways=(ways+(lefttrue*righttrue)%mod+(leftfalse*righttrue)%mod
                +(lefttrue*rightfalse)%mod)%mod;
            }
            else ways=(ways+(leftfalse*rightfalse)%mod)%mod;
        }
        else {
            if(req){
                ways=(ways+(leftfalse*righttrue)%mod+(lefttrue*rightfalse)%mod)%mod;
            }
            else{
                ways=(ways+(lefttrue*righttrue)%mod+(leftfalse*rightfalse)%mod)%mod;
            }
        }
    }
    return dp[i][j][req]=ways;
}
int evaluate(string &s){
    int n=s.size();
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    return f(0,n-1,s,1,dp);
}
int evaluatetab(string &s){
    int n=s.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    for(int k=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i=j){
                dp[i][i][0]=(s[i]=='F');
                dp[i][i][1]=(s[i]=='T');
            }
            else{
                for(int req=0;req<=1;req++){
                    int ways=0;
                for(int k=i+1;k<=j-1;k+=2){
                    int lefttrue=dp[i][k-1][1];
                    int leftfalse=dp[i][k-1][0];
                    int righttrue=dp[k+1][j][1];
                    int rightfalse=dp[k+1][j][0];
                    if(s[k]=='&'){
                        if(req){    
                            ways=(ways+ (lefttrue*righttrue)%mod)%mod;
                        }
                        else ways=(ways+(lefttrue*rightfalse)%mod+(leftfalse*righttrue)%mod
                                +(leftfalse*rigthfalse)%mod)%mod;
                        }
                    else if(s[k]=='|'){
                        if(req){
                            ways=(ways+(lefttrue*righttrue)%mod+(leftfalse*righttrue)%mod
                            +(lefttrue*rightfalse)%mod)%mod;
                        }
                            else ways=(ways+(leftfalse*rightfalse)%mod)%mod;
                        }
                    else {
                        if(req){
                            ways=(ways+(leftfalse*righttrue)%mod+(lefttrue*rightfalse)%mod)%mod;
                        }
                        else{
                            ways=(ways+(lefttrue*righttrue)%mod+(leftfalse*rightfalse)%mod)%mod;
                        }
                    }
                }
                dp[i][j][req]=ways;
                }
            }
            
        }
    }
    return dp[0][n01][1];
}

