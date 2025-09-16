/*SEARCH AN IDX OF THE ELEMENT IN AN INFINITE BINARY SORTED ARRAY */
#include<bits/stdc++.h>
using namespace std;
  int binarySearch(vector<int>&v1,int start,int end,int key){
    int res = -1;
      while(start <= end){
        int mid = start + (end-start)/2;
        if(v1[mid] == key){
            res = mid;
            end = mid - 1;
        }
        else if(v1[mid] > key){
            end = mid -1;
        }
        else {
            start = mid +1;
        }
      }
    return res;
  }
void firstOccurence(vector<int>&v1,int n,int key){
   int start =0,end = 1;
   // Expand the window exponentially
   while(end < n && key > v1[end]){
       start = end;
       end = end * 2;
   }
   // Clamp end if it goes beyond array size
    if (end >= n) end = n - 1;

  int idx = binarySearch(v1,start,end,key);
  cout<<idx;
}
int main(){
    vector<int>v1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int key = 1;
    int n = v1.size();
   firstOccurence(v1,n,key);
    return 0;
}