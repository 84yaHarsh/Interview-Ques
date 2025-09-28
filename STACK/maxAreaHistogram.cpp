/*Max area histogram */
#include<bits/stdc++.h>
using namespace std;
vector<int>NSL(vector<int>&arr){
    vector<int> left ;
    stack<pair<int,int>>s;
    int pseudoIdx = -1;
    for(int i=0; i<arr.size(); i++){
       if(s.empty()){
         left.push_back(pseudoIdx);
       }
       else if(!s.empty() && s.top().first<=arr[i]){
          left.push_back(s.top().second);
       }
       else if(!s.empty() && s.top().first > arr[i]){
        while(!s.empty() && s.top().first > arr[i]){
            s.pop();
        }
       if(s.empty()){
        left.push_back(pseudoIdx);
       }
       else {
           left.push_back(s.top().second);
       }
    }
    s.push({arr[i],i});
    }
    return left;
}
vector<int>NSR(vector<int>&arr){
     vector<int> right ;
    stack<pair<int,int>>s;
    int pseudoIdx = arr.size();
    for(int i=arr.size()-1; i>=0; i--){
       if(s.empty()){
         right.push_back(pseudoIdx);
       }
       else if(!s.empty() && s.top().first<=arr[i]){
          right.push_back(s.top().second);
       }
       else if(!s.empty() && s.top().first > arr[i]){
        while(!s.empty() && s.top().first > arr[i]){
            s.pop();
        }
       if(s.empty()){
        right.push_back(pseudoIdx);
       }
       else {
           right.push_back(s.top().second);
       }
    }
    s.push({arr[i],i});
    }
    reverse(right.begin(),right.end());
    return right;
}
int maxAreaHistogram(vector<int>&v){
    vector<int>left = NSL(v);
    vector<int>right = NSR(v);
    int maxArea = 0;
    for(int i=0; i<left.size(); i++){
        int area = (right[i]-left[i]-1) * v[i];
        maxArea = max(maxArea,area);
    }
    return maxArea;
}

int main(){
    vector<int>v= {6,2,5,4,5,1,6};
    cout<<"max area of histogram is :"<< maxAreaHistogram(v);
    return 0;
}