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

/* string matching problems*/
int f(int i, int j, string s, string t, vvi dp){
    if(j<0)return 1;
    if(i<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s[j])return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    else return dp[i][j]=f(i-1,j,s,t,dp);
}
int num(string s, string t){
    int n=s.size(),m=t.size();
    // vvi dp(n,vi(m,-1));
    // return f(n-1,m-1,s,t,dp);
    vvi dp(n+1,vi(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int j=1;j<=m;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][m];

}
int distinctsubs(string s, string t){
    int n=s.size(),m=t.size();
    vi prev(m+1,0), curr(m+1,0);
    prev[0]=curr[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])curr[j]=prev[j]+prev[j-1];
            else curr[j]=prev[j];
        }
        prev=curr;
    }
    return prev[m];
} 
int fedit(int i,int j,string &s,string &t,vvi &dp){
if(i<0)return j+1;
if(j<0)return i+1;
if(dp[i][j]!=-1)return dp[i][j];
if(s[i]==t[j])return dp[i][j]= fedit(i-1,j-1,s,t,dp);
return dp[i][j]= 1+min({fedit(i-1,j,s,t,dp),fedit(i-1,j-1,s,t,dp),fedit(i,j-1,s,t,dp)});
}
int editdistance(string &s,string &t){
    int n=s.size();
    int m=t.size();
    // vvi dp(n, vi(m,-1));
    // return f(n-1,m-1,s,t,dp);
    // vvi dp(n+1,vi(m+1,0));
    // for(int i=0;i<=n;i++)dp[i][0]=i;
    // for(int j=0;j<=m;j++)dp[0][j]=j;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(s[i]==t[j])dp[i][j]= dp[i-1][j-1];
    //         else dp[i][j]= 1+min({dp[i-1][j],
    //         dp[i-1][j-1],dp[i][j-1]});
    //     }
    // }
    // return dp[n][m];

    vi prev(m+1,0), curr(m+1,0);
    
    for(int j=0;j<=m;j++)prev[j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==t[j])curr[j]= prev[j-1];
            else curr[j]= 1+min({prev[j],
            curr[j-1],prev[j-1]});
        }
        prev=curr;
    }
    return prev[m];
    
}
/*wild card matching*/
int fwild(int i, int j, string &p, string &t, vvi&dp){
    if(i<0 &&j<0)return 1;
    if(i<0 && j>=0)return 0;
    if(i>=0 &&j<0){
        for(int k=0;k<=i;k++){
            if(p[k]!='*')return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(p[i]==t[j]||p[i]=='?')return dp[i][j]=fwild(i-1,j-1,p,t,dp);
    else if(p[i]=='*'){
        return fwild(i-1,j,p,t,dp)|fwild(i,j-1,p,t,dp);
    }
    return dp[i][j]=false;
}
bool ismatching(string &p, string &t){
    // int n=p.size();
    // int m=t.size();
    // vvi dp(n,vi(m,-1));
    // return fwild(n-1,m-1,p,t,dp);
    int n=p.size();
    int m=t.size();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
    dp[0][0]=1;
    for(int i=1;i<=m;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int k=1;k<=i;k++){
            if(p[k-1]!='*'){
                flag=false;
                break;
            }
        }
        dp[i][0]=flag;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            if(p[i-1]==t[j-1]||p[i-1]=='?')dp[i][j]=dp[i-1][j-1];
            else if(p[i-1]=='*'){
            dp[i][j]=dp[i-1][j]|dp[i][j-1];
            }
            else dp[i][j]=false;
        }
    }
    return dp[n][m];
}
bool ismatchingopti(string&p, string&t){
    int n=p.size();
    int m=t.size();
    vector<bool> prev(m+1,0), curr(m+1,0);
    prev[0]=1;
    for(int i=1;i<=m;i++)prev[i]=0;
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int k=1;k<=i;k++){
            if(p[k-1]!='*'){
                flag=false;
                break;
            }
        }
        curr[0]=flag;
        for(int j=1;j<=m;j++){
            
            if(p[i-1]==t[j-1]||p[i-1]=='?')curr[j]=prev[j-1];
            else if(p[i-1]=='*'){
            curr[j]=prev[j]|curr[j-1];
            }
            else curr[j]=false;
        }
        prev=curr;
    }
    return prev[m];
}