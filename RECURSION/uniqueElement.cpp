/*print only unique subset of a string */
#include<bits/stdc++.h>
using namespace std;
set<string>s;
void subSet(string Ip,string Op){
    if(Ip.size()==0){
        s.insert(Op);
        return ;
    }
    string op1 = Op;
    string op2 = Op;
    op2.push_back(Ip[0]);
    Ip.erase(Ip.begin()+0);
    subSet(Ip,op1);
    subSet(Ip,op2);

}
int main(){
    string Ip = "aab";
    string Op = "";
    sort(Ip.begin() ,Ip.end());
    subSet(Ip,Op);
    for(auto it=s.begin() ; it!=s.end(); it++){
        if(*it == "") cout<<"empty"<<endl;
        else cout<<*it<<endl;
    }
    return 0;
}