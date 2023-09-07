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

int f(int i,int j, string &s, string &t, vvi &dp){
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]= 1+f(i-1,j-1,s,t,dp);
    return dp[i][j]= max(f(i,j-1,s,t,dp), f(i-1,j,s,t,dp));
}
int lcs(string s,string t){
    // int n =s.size();
    // int m=t.size();
    // vvi dp(n, vi(m,-1));
    // return f(n-1,m-1,s,t,dp);

    
    int n =s.size();
    int m=t.size();
    vvi dp(n+1, vi(m+1,-1));
    rep(i,0,n+1)dp[i][0]=0;
    rep(j,0,m+1)dp[0][j]=0;
    rep(i,1,n+1){
        rep(j,1,m+1){
            if(s[i-1]==t[j-1])dp[i][j]= 1+dp[i-1][j-1];
            else dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];

    // int n =s.size();
    // int m=t.size();
    // vi prev(m+1,0), curr(m+1,0);
    
    // rep(j,0,m+1)prev[j]=0;
    // rep(i,1,n+1){
    //     rep(j,1,m+1){
    //         if(s[i-1]==t[j-1])curr[j]= 1+prev[j-1];
    //         else curr[j]= max(curr[j-1], prev[j]);
    //     }
    //     prev=curr;
    // }
    // return prev[m];
    int len=dp[n][m];
    string ans="";
    for(int i=0;i<len;i++){
        ans+='&';
    }
    int index=len-1;
    int i=n,j=m;
    while(i>0 &&j>0){
        if(s[i-1]==t[j-1]){
            ans[index]=s[i-1];
            index--;
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else j--;
    }
    /*string s is the lcs*/
}

int lcsubstr(string s, string t){
    int n=s.size();
    int m=t.size();
    vvi dp(n+1, vi(m+1,0));
    int ans=0;
    for(int j=0;j<=m;j++)dp[0][j]=0;
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    return ans;
}
/* minimum number of operation to make string 
palindrome = len-lcs*/
/* minimum number of operation(insertions/deletions)to 
convert a string a to b n+n-2*lcs*/

/* shortest common supersequence*/
/* len=m+n-lcs*/



/*
    generate the dp table 
    string ans="";
        int i=n,j=m;
        while(i>0 &&j>0){
            if(s[i-1]==t[j-1]){
                ans+=s[i-1];
                i--,j--;
            }
            else if(dp[i-1][j]> dp[i][j-1]){
                ans+=s[i-1];
                i--;
            }
            else {
                ans+=t[j-1];
                j--;
            }

        }
        while(i>0){
            ans+=s[i-1];i--;
        }
        while(j>0){
            ans+=t[j-1];j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;


*/