/*MIn STACK IMPLEMENTATION USING O(1) SPACE */
#include<bits/stdc++.h>
using namespace std;
class minStack{
    stack<int>s;
    int minEle ;
    public:
    void push(int x){
       if(s.empty()){
          s.push(x);
          minEle = x;
       }
       else{
           if(!s.empty() && x >minEle){
           s.push(x);
       }
       else {
            // if(!s.empty() && s.top() < x) 
            s.push(2*x-minEle);
            minEle = x;
         }
     } 
    }
    void pop(){
        if(s.empty())  return ;
        else if(!s.empty() && s.top() > minEle){
            s.pop();
        }
        else{
                // (!s.empty() && s.top() <= minEle)
                minEle = 2*minEle - s.top();
                s.pop();
        } 
    }
    int top(){
          if(s.empty()){
            return -1;
          }
          else if(!s.empty() && s.top() >=minEle){
                return s.top();
          } 
          else{
            //(!s.empty() && s.top() < minEle)
            return minEle;
          }
    }
    int getMin(){
        if(s.empty()){
            return -1;
        }
        else {
            return minEle;
        }
    }
};
int main(){
    minStack ms;
    vector<int>v = {18,19,29,15,16};
    for(int i=0; i<v.size(); i++){
        ms.push(v[i]);
       cout<< "pushed element is : "<< v[i]<< "and min element is : " << ms.getMin()<<endl;
    }
    
    cout<<"top element is :" <<ms.top() <<endl; 
    ms.pop();
    cout<<"after pop operation min element is:" << ms.getMin()<<endl;

    return 0;
}