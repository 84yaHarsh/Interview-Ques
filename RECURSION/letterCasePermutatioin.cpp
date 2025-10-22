/*a1b2 -> a1b2 , A1b2 , a1B2 , A1B2 */
#include<bits/stdc++.h>
using namespace std;
void permutation(string Ip,string Op,vector<string>&v1){
    if(Ip.length() == 0){
        v1.push_back(Op);
        return ;
    }
    if(isalpha(Ip[0])){
        string op1 = Op;
        string op2 = Op;
        op1.push_back(Ip[0]);
        op2.push_back(toupper(Ip[0]));
        Ip.erase(Ip.begin()+0);
        permutation(Ip,op1,v1);
        permutation(Ip,op2,v1);
    }
    else{
        string op3 = Op;
        op3.push_back(Ip[0]);
        Ip.erase(Ip.begin()+0);
        permutation(Ip,op3,v1);
    }

}
vector<string>lcp(string Ip){
    vector<string>v1;
    string Op = "";
    permutation(Ip,Op,v1);
    return v1;

}
int main(){
    string Ip = "a1b2";
    string Op = "";
    vector<string> v = lcp(Ip);
    for(string i : v){
        cout<<i<<endl;
    }
    return 0;
}