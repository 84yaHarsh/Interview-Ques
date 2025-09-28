/*STOCK SPAN PROBLEM */
#include<bits/stdc++.h>
using namespace std;
vector<int>stockSpan(vector<int>&arr){
    vector<int>v;
    stack<pair<int,int>>s;
    for(int i=0; i<arr.size(); i++){
        if(s.empty()){
            v.push_back(-1);
        }
        else if(!s.empty() && s.top().first > arr[i] ){
            v.push_back(s.top().second);
        }
        else if(!s.empty() && s.top().first <= arr[i]){
            while(!s.empty() && s.top().first <= arr[i]){
                   s.pop();
            }
        if(s.empty()){
            v.push_back(-1);
        }
        else{
            v.push_back(s.top().second);
        }
       
    }
     s.push({arr[i],i});
    }
     for(int i=0; i<v.size(); i++){
            v[i] = i - v[i];
        }
        return v;
}
  int  main(){
    vector<int> v = {100,80,60,70,60,75,85};
    vector<int> ans = stockSpan(v);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
  }
