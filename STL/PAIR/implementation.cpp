/*pair < type1 , type2 >name_of_pair */

#include<bits/stdc++.h>
using namespace std;
int main(){
    pair< string , int > p;
    p = make_pair("harsh",21);
    /*p.first = "harsh";
      p.second = 21;
      */
    cout<< p.first <<" "<< p.second <<endl;
    return 0;
}