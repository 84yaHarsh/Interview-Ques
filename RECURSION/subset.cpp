/*SUBSET OS A STRING */
#include<bits/stdc++.h>
using namespace std;
void subSet(string ip,string op){
    if(ip.length()==0){
        cout<<op <<endl;
        return ;
    }
string op1 = op;
string op2 = op;
op2.push_back(ip[0]);
ip.erase(ip.begin()+0); // remove the charecter present at 0th index
subSet(ip,op1);
subSet(ip,op2);
return ;
}
int main(){
    string ip = "abc";
    string op = "";
    subSet(ip,op);
    return 0;
}