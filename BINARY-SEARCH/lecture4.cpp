/*SEARCH AN ELEMENT IN AN SORTED ARRAY IF IT IS NOT DECIDE EITHER IT IS IN SORETD IN ASSENDING OR DECENDING */

#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&v1,int n,int key){
    int start =0,end = n-1;
    bool isAscending = v1[start]<=v1[end];  // check order
    while(start<=end){
        int mid = start +(end-start)/2;
        if(v1[mid]==key){
            return mid;
        }
    if(isAscending){
         if(v1[mid]>key)
            end = mid-1;

         else  
            start = mid+1;
      }
    else{
        if(v1[mid]>key)
            start = mid+1;
        
        else 
            end = mid -1;
    }
    }
    return -1;
}
int main(){
    int n,key;
    cin>>n>>key;
    vector<int>v1(n);
    for(int i=0; i<n ; i++){
        cin>>v1[i];
    }
    cout<<binarySearch(v1,n,key);
    return 0;
}
