/*Nearest greatest to the right
T.C->O(N) S.C->O(N)*/
#include<bits/stdc++.h>
using namespace std;
vector<int> nearesetGreatestRight(vector<int>&v1){
    vector<int>v;
    stack<int>s;
    int n = v1.size();
    for(int i=n-1; i>=0; i--){
        // if stack is empty
        
        if(s.empty()){
             v.push_back(-1);
        }
        
        // s.top() > v1[i] (if top element is greater then vector element) 
      
        else if(!s.empty() && s.top() > v1[i]){
            v.push_back(s.top());
        }

        //  s.top() <= v1[i] then pop until s.top() >v1[i] or s.size()==0

        else if(!s.empty() && s.top()<=v1[i]){
            while(!s.empty() && s.top() <= v1[i]  ){
                s.pop();
            }
        if(s.empty()){
            v.push_back(-1);
        }
        else{
            v.push_back(s.top());
         }
    } 
      s.push(v1[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}

int main(){
    vector<int>v1 = {1,3,2,4};
    vector<int> res = nearesetGreatestRight(v1);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}