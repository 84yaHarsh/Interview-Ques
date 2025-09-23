/*SORT AN ARRAY USING RECURSION  */
#include<bits/stdc++.h>
using namespace std;
void insert(vector<int>&v1,int temp){
    int n = v1.size();
    if(n==0 || v1[n-1]<=temp){
        v1.push_back(temp);
        return;
    }
    int last = v1[n-1];
    v1.pop_back();
    insert(v1,temp);
    v1.push_back(last);
}
void sortArray(vector<int>&v1){  
    int n = v1.size();
    if(n==1){
       return ;
    }
    int temp = v1[n-1]; 
    v1.pop_back();  
    sortArray(v1);  
    insert(v1,temp);
     
}
int main(){
    vector<int> v1 = {1,0,5,4,2};
    int n = v1.size();
    sortArray(v1);
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
    return 0;
}