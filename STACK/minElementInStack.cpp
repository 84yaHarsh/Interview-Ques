/*MINIMUM ELEMENT IN STACK USING EXTRA SPACE*/
#include<bits/stdc++.h>
using namespace std;
class minStack{
    stack<int>s;
    stack<int>ss;
   public:
   void push(int a){
      s.push(a);
      if(ss.empty() || ss.top() >=a){
         ss.push(a);
      }
   }
   int pop(){
      if(s.empty()){
         return -1;
      }
      int ans = s.top();
         s.pop();
      if(ss.top() == ans){
        ss.pop();
      }
      return ans;
   }
   int top(){
       if(s.empty()){
        return -1;
    }
        else{
        s.top();
      }
   }

   int getMin(){
       if(ss.empty()) return -1;
       return ss.top();
   }

   bool empty(){
    return empty();
   }

};
    

int main(){
    minStack ms;
    vector<int>v = {18,19,29,15,16};
    for(int i=0; i<v.size(); i++){
          ms.push(v[i]);
    cout<<"pushed element is :"<<v[i] << " min element is:"<<ms.getMin()<<endl;
    }
     while(!ms.empty()){
  
        cout<<"pop element is :"<< ms.top() << " min element is:"<<ms.getMin()<<endl;
              ms.pop();
     }

    return 0;
}