/*BOOK ALLOCATION PROBLEM */
#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<int>&v1,int n,int k,int maxPage){
     int student = 1;
     int sum = 0;
     for(int i=0; i<n; i++){
        sum += v1[i];
        if(sum > maxPage){
            student ++;
            sum = v1[i];
        }
        if(student > k){
            return false;
        }
     }
     return true;
}
int bookAllocation(vector<int>&v1 , int n , int k){
    int max = v1[0],sum =0;
    for(int i=0; i<n; i++){
        if(max < v1[i]){
            max = v1[i];
        }
        sum +=v1[i];
    }
   int start = max, end = sum;
   int res = -1;
   while(start <= end){
    int mid = start + (end - start)/2;
    if(isValid(v1,n,k,mid)){
        res = mid;
        end = mid -1;
    }
    else {
        start = mid + 1 ;
    }
   }
   return res ;
}
int main(){
    vector<int>v1 = {10,20,30,40};
    int n = v1.size();
    int k = 2;
    cout<<bookAllocation(v1,n,k);
    return 0;
}