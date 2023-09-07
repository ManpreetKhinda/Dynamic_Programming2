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
int f(int ind, vi&nums, vi&dp){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int pick=f(ind-2,nums,dp)+nums[ind];
    int notpick=f(ind-1,nums,dp);
    return dp[ind]=max(pick,notpick);
}
int maximum(vi&nums){
    int n=nums.size();
    vi dp(n,-1);
    return f(n-1,nums,dp);
}
int main(){
    int n;
    vi nums;
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1)take+=prev2;
        int nottake=prev;
        int curri=max(take,nottake);
        prev2=prev;
        prev=curri;

    }
    return prev;
}