/* IF WE WANT TO MAKE MORE THAN TWO ELEMENT IN A PAIR */
#include<bits/stdc++.h>
using namespace std;
int main(){
    pair<string,pair<int,int>>p;
    p = make_pair("harsh",make_pair(21,54));  // (name,(age,weight))
    cout<< p.first <<" "<<p.second.first<<" "<<p.second.second<<endl;
    return 0;
}