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
int largestrectangle(vi& heights){
    int n=heights.size();
    stack<int> st;
    int leftsmall[n],rightsmall[n];
    for(int i=0;i<n;i++){
        while(!st.empty() &&heights[st.top()]>=heights[i])st.pop();
        if(st.empty())leftsmall[i]=0;
        else leftsmall[i]=st.top()+1;
        st.push(i);
    }
    st=stack<int>();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
        if(st.empty())rightsmall[i]=n-1;
        else rightsmall[i]=st.top()-1;
        st.push(i);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,heights[i]*(rightsmall[i]-leftsmall[i]+1));
    }
    return ans;
}
/*single pass*/
int largestrectangle(vi&heights){
    stack<int> st;
    int ans=0;
    int n=heights.size();
    for(int i=0;i<=n;i++){
        while(!st.empty()&& (i==n||heights[st.top()]>=heights[i])){
            int height=heights[st.top()];
            st.pop();
            int width;
            if(!st.empty())width=i;
            else width=i-st.top()-1;
            ans=max(ans,width*height);
        }
        st.push(i);
    }
    return ans;
}