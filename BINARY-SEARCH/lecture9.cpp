/*SEARCH IN A NEARLY SORTED ARRAY
LIKE ELEMENT CAN BE FOUND AT iTH ,(i-1)TH or (I+1)th index*/
#include<bits/stdc++.h>
using namespace std;
int findElement(vector<int>&v1,int n,int key){
    int start =0;
    int end = v1.size()-1;
    while(start <= end){
      int mid = start+(end-start)/2;
      if(v1[mid] == key){
        return mid;
      }
      // check left neighour
      if(mid-1>=start && v1[mid-1] == key){
        return mid-1;
      }
      // check right neighour
      if(mid+1<=end && v1[mid+1] == key){
        return mid+1;
      }
      // search in right side
      if(v1[mid] < key){
        start = mid+2;
      }
      // search in left side
      else{
        end = mid - 2 ;
      }
    }
   return -1;
}
int main(){
    vector<int>v1 = {5,10,30,20,40};
    int key;
    cin>>key;
    int n = v1.size();
    int res = findElement(v1,n,key);
    if(res ==-1){
        cout<<"element not found"<<endl;
    }
    else {
        cout<<key<<" is found at idx :"<<res<<endl;
    }
    return 0;
}