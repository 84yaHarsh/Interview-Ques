/*abc -> aB,Ab,AB,ab */
#include<bits/stdc++.h>
using namespace std;
void permutation(string Ip,string Op){
   if(Ip.length()==0) {
    cout<< Op <<endl ;
    return ;
   }
   string Op1 = Op;
   string Op2 = Op;
   Op1.push_back(Ip[0]);
   Op2.push_back(toupper(Ip[0]));
   Ip.erase(Ip.begin()+0);
   permutation(Ip,Op1);
   permutation(Ip,Op2);
   return ;
}
int main(){
    string Ip = "ab";
    string Op = "";
    permutation(Ip,Op);
    return 0;
}