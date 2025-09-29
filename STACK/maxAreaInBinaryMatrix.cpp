/*MAX AREA REACTANGLE IN BINARY MATRIX */
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
int MAH(vector<int>&v){
    vector<int>left = NSL(v);
    vector<int>right = NSR(v);
    int maxArea = 0;
    for(int i=0; i<left.size(); i++){
        int area = (right[i]-left[i]-1) * v[i];
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int MABH(vector<vector<int>>&arr){
     vector<int>v;
     for(int j=0; j<arr.size(); j++){
        v.push_back(arr[0][j]);
     }
     int maxi = MAH(v);
     for(int i =1; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            if(arr[i][j]==0){
               v[j] == 0;
            }
            else{
                v[j] = v[j]+arr[i][j];
            }
        }
         maxi = max(maxi,MAH(v));
     }
     return maxi;
} 

int main(){
    int m,n;
    cout<<"enter row and col size:"<<endl;
    cin>>m>>n;
    cout<<"enter binary 2D histogram :"<<endl;
    vector<vector<int>>v(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    cout<<"Maximum area of binary hiatogram is :"<<MABH(v);

    return 0;
}