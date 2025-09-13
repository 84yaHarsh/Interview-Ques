/*NEXT LETTER GENARATION 
['a','c','f','h']  key = f */

#include<bits/stdc++.h>
using namespace std;
char nextLetter(vector<char>v1,int n,char key){
   int start =0,end = n-1;
   char ans = v1[0];  // default = first element (wrap-around)
   while(start<=end){
    int mid = start+(end-start)/2;
    if(v1[mid] == key){
        start = mid + 1;
    }
    else if(v1[mid] > key){
        ans = v1[mid];
        end = mid - 1;
    }
    else{
        start = mid + 1;
    }
   }
   return ans;
}
int main(){
    int n;
    cout<<"enter the size of charecter vector:"<<endl;
    cin>>n;
    cout<<"enter char vector:"<<endl;
    vector<char>v1(n);
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }
    char key;
    cout<<"enter key:"<<endl;
    cin>>key;
    char ch = nextLetter(v1,n,key);
    cout<<ch<<endl;
    return 0;
}