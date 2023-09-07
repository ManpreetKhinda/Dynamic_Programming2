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

int f(int ind, int prev_ind, vi&arr, int n,vvi &dp){
    if(ind==n)return 0;
    if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
    int len=f(ind+1,prev_ind,arr,n,dp);
    if(prev_ind==-1||arr[ind]>arr[prev_ind]){
        len=max(len,1+f(ind+1, ind,arr,n,dp));
    }
    return dp[ind][prev_ind+1]=len;
}
int lis(vi&arr, int n){
    // vvi dp(n,vi(n+1,-1));
    // return f(0,-1,arr,n,dp);
    // vvi dp(n+1,vi(n+1,0));
    // for(int i=n-1;i>=0;i--){
    //     for(int prev=i-1;prev>=-1;prev--){
    //         int len=dp[i+1][prev+1];
    //         if(prev==-1||arr[i]>arr[prev]){
    //             len=max(len,1+dp[i+1][i+1]);
    //         }
    //         dp[i][prev+1]=len;
    //     }
    // }
    // return dp[0][0];


    // vi dp(n,1);
    // int maxi=1;
    // for(int i=0;i<n;i++){
    //     for(int prev=0;prev<i;prev++){
    //         if(arr[prev]<arr[i])dp[i]=max(dp[i],1+dp[prev]);
    //     }
    //     maxi=max(maxi,dp[i]);
    // }
    // return maxi;

/* largest divisible subset is same as lis with arr sorted and condition of
divisiblity added*/
/*largest string chain is same as lis with compare function to check for
string if string differ by one insertion*/

/*
*/
    vi dp(n,1), hash(n);
    int maxi=1;
    int lastindex=0;
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i] && 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastindex=i;
        }
    }
    vector<int> lis;
    lis.push_back(arr[lastindex]);
    while(hash[lastindex]!=lastindex){
        lastindex=hash[lastindex];
        lis.push_back(arr[lastindex]);
    }
    reverse(lis.begin(),lis.end());
    return maxi;
}
int lisbs(vi &arr, int n){
    vi temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }
        else {
            int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind]=arr[i];
        }
    }
    return temp.size();
}
/*longest possible string chain*/

bool compare(string&s, string&t){
      if(s.size()!=t.size()+1)return false;
      int first=0;
      int second=0;
      while(first<s.size()){
          if( second<t.size() &&s[first]==t[second]){
              first++;
              second++;
          }
          else{
              first++;
          }
      }
      if(first==s.size() && second==t.size())return true;
      return false;
  }
  static bool comp(string&s, string &t){
      return s.size()<t.size();
  }
  
    
    int longestChain(int n, vector<string>& arr) {
        // Code here
        vector<int> dp(n,1);
    int maxi=1;
    sort(arr.begin(),arr.end(),comp);
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(compare(arr[i],arr[prev]))dp[i]=max(dp[i],1+dp[prev]);
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
    }
/*longest bitonic subsequence*/
 

int lbs(vi& arr, int n){
    vi dp1(n,1);
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i])dp1[i]=max(dp1[i],1+dp1[prev]);
        }
    }
    vi dp2(n,1);
    for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--){
            if(arr[prev]<arr[i])dp2[i]=max(dp2[i],1+dp2[prev]);
        }
    }
    int maxi=1;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp1[i]+dp2[i]-1);
    }
    return maxi;
}

/*number of lis*/
int numberoflis(vi&arr, int n){
    vi dp(n,1), cnt(n,1);
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i] && 1+dp[prev]<dp[i]){
                dp[i]=1+dp[prev];
                cnt[i]=cnt[prev];
            }
            else if(arr[prev]<arr[i] && 1+dp[prev]==dp[i]){
                cnt[i]+=cnt[prev];
            }
        
        }
        maxi=max(maxi,dp[i]);

    
    }
    int nos=0;
    for(int k=0;k<n;k++){
        if(dp[k]==maxi)nos+=cnt[k];
    }
    return nos;
}