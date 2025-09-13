/*FIND CEIL ELEEMNT OF A SORTED ARRAY 
[1,2,3,4,5,10,12]  ele = 6 
so ceil element will be 10 if 6 is not present */

#include<bits/stdc++.h>
using namespace std;
int ceilElement(vector<int>&v1,int n,int ele){
    int start = 0,end = n-1;
    int res =-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(v1[mid]==ele){
            return v1[mid];
        }
        else if(v1[mid] > ele){
            res = v1[mid];
            end = mid - 1;
        }
        else{
            start = mid + 1 ;
        }
    }
    return res;
}
int main(){
    vector<int>v1 = {1,2,3,4,5,10,12};
    int n = v1.size();
    int ele = 6;
    cout<<ceilElement(v1,n,ele);
    return 0;
}