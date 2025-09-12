/*NUMBER OF TIMES AN SORTED ARRAY IS ROTATED 
T.C->O(logN) S.C ->O(1)*/
#include<bits/stdc++.h>
using namespace std;
int findRotationCount(vector<int>&v1,int n){
    int start =0,end = n-1;
 
    while(start<=end){
        // already sorted ->smallest at 0th index
        if(v1[start] <= v1[end]) return start;
        int mid = start +(end-start)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        
    if(v1[mid]<=v1[prev] && v1[mid]<=v1[next]){
         return mid;
    }
    else if(v1[start]<=v1[mid]){
        start = mid+1;
    }
    else {
        end = mid-1;
      }
    }
    return -1;
}
int main(){
   vector<int>v1 = {11,12,15,18,2,5,6,8};
   int n = v1.size();
    cout<<findRotationCount(v1,n);
    return 0;
}
