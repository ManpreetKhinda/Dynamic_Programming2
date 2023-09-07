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
int f(int day, int last,vvi&points, vvi &dp){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1)return dp[day][last];
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point=points[day][task]+f(day-1,task,points,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]= maxi;
}
int ninjtraining(int n, vvi &points){
    vvi dp(n,vi(4,-1));
    return f(n-1,3,points,dp);
}
int ninjaTraining(int n, vvi &points){
    vvi dp(n, vi (4,0));
    dp[0][0]=max(points[0][1], points[0][2]);
    dp[0][1]=max(points[0][0], points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max({points[0][0], points[0][1], points[0][2]});
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}
int ninjatrainng2(int n, vvi& points){
    vi prev(4,0);
    prev[0]=max(points[0][1], points[0][2]);
    prev[1]=max(points[0][0], points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max({points[0][0], points[0][1], points[0][2]});
    for(int day=1;day<n;day++){
        vi temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    temp[last]=max(temp[last],points[day][task]+prev[task]);
                }
            }

        }
        prev=temp;
    }
    return prev[3];
}
