/*FIND FLOOR ELEEMNT OF A SORTED ARRAY 
[1,2,3,4,5,10,12]  ele = 6 
so floor element will be 5 if 6 is not present */
#include<bits/stdc++.h>
using namespace std;
int floorElement(vector<int>&v1,int n,int ele){
    int start = 0,end = n-1;
    int res =-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(v1[mid]==ele){
            return v1[mid];
        }
        else if(v1[mid] < ele){
            res = v1[mid];
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return res;
}
int main(){
    vector<int>v1 = {1,2,3,4,5,10,12};
    int n = v1.size();
    int ele = 6;
    cout<<floorElement(v1,n,ele);
    return 0;
}