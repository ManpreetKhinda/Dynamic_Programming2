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
/* given array of heights a frog can jump expendng energy equal 
to height diff, can jum 1 or 2 pos return min energy*/
int f(int ind, vi &heights, vi&dp){
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int left=abs(heights[ind]-heights[ind-1])+f(ind-1,heights, dp );
    int right=INT_MAX;
    if(ind>1)int right=abs(heights[ind]-heights[ind-2])+f(ind-2,heights,dp);
    return dp[ind]=min(left,right);
}
int main(){
    int n;
    vi height;
    vi dp(n+1,-1);
    cout<< f(n-1,height, dp);
    vi t(n,0);
    t[0]=0;
    for(int i=1;i<n;i++){
        int fs=abs(height[i]-height[i-1])+dp[i-1];
        int ss=INT_MAX;
        if(i>1)int ss=abs(height[i]-height[i-2])+dp[i-2];
        dp[i]=min(fs,ss);
    }
    cout<< dp[n-1];
    int prev2=0,prev1=0;
    for(int i=1;i<n;i++){
        int fs=abs(height[i]-height[i-1])+prev1;
        int ss=INT_MAX;
        if(i>1)int ss=abs(height[i]-height[i-2])+prev2;
        int curri=min(fs,ss);
        prev2=prev1;
        prev1=curri;
        
    }
    cout<<prev1;

}