/*FIND PEAK ELEMENT IN AN ARRAY*/
#include<bits/stdc++.h>
using namespace std;
int peakElement(vector<int>&v1,int n){
    int start =0, end = n-1;
    if(n==1) return 0;
    while(start < end){
        int mid = start +(end-start)/2;
    if(v1[mid]>v1[mid+1]){
        end = mid;
    }
    else {
        start = mid + 1;
    }
    }
    return start ; // end since start ==end
}
int main(){
    vector<int>v1 = {10,20,15,2,23,90,67};
    int n = v1.size();
    cout<< peakElement(v1,n);
    return 0;
}