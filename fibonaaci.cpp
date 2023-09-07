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
int f(int n, vi &dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=f(n-1,dp)+f(n-2,dp);

}
int main(){
    int n=5;
    vi dp(n+1,-1);
    cout<<f(n,dp);
    dp[0]=0;dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
    int prev2=0, prev1=1;
    for(int i=2;i<=n;i++){
        int curri=prev1+prev2;
        prev2=prev1;
        prev1=curri;
    }
    cout<<prev1;

}