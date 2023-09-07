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

int f(int i,vector<int>&num,int k,vector<int>&dp){
    if(i==num.size())return 0;
    int len=0;
    int maxval=INT_MIN;
    int maxpart=INT_MIN;
    if(dp[i]!=-1)return dp[i];
    for(int j=i;j<min(i+k,num.size());j++){
        len++;
        maxval=max(maxval,num[j]);
        int sum=len*maxval+f(j+1,num,k,dp);
        maxpart=max(maxpart,sum);
    }
    return dp[i]=maxpart;
}
int maximumsubarray(vector<int>& num, int k){
    int n=num.size();
    vector<int> dp(n,-1);
    return f(0,num,k,dp);
}
int maxisumsubarr(vector<int>&num, int k){
    int n=num.size();
    vector<int> dp(n+1,0);
    dp[n]=0;
    
    for(int i=n-1;i>=0;i--){
        int len=0;
        int maxval=INT_MIN;
        int maxpart=INT_MIN;
        for(int j=i;j<min(i+k,num.size());j++){
            len++;
            maxval=max(maxval,num[j]);
            int sum=len*maxval+dp[j+1];
            maxpart=max(maxpart,sum);
        }
        dp[i]=maxpart;
    }
    return dp[0];
}