/*COUNT A ELEEMENT IN AN SORTED ARRAY
T.C->O(logN) S.C->O(1)  */
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&v1,int n,int key,bool find){
    int start =0,end = n-1;
    int res = -1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(v1[mid]==key){
            res = mid;
        if(find){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        }
        else if(v1[mid]>key){
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return res;
}
int count(vector<int>&v1,int n,int key){
    int first = binarySearch(v1,n,key,true);
    if(first==-1) return 0; // element not found
    int last =  binarySearch(v1,n,key,false);
    int count = last-first+1;
    return count;
}
int main(){
    int key;
    vector<int>v1 = {2,4,10,10,10,18,20};
    cin>>key;
    int n = v1.size();
    cout<<count(v1,n,key);
    return 0;
}