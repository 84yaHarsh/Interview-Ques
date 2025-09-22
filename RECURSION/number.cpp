/*PRINT NUMBER FROM 1 TO N*/
#include<iostream>
using namespace std;
void number(int n){
if(n==1){
    cout<<n<<endl;
    return ;
}
number(n-1);
cout<<n<<endl;
}
int main(){
    number(5);
    return 0;
}


/*
Recursion Tree

number(5)
|
|-- number(4)
|    |
|    |-- number(3)
|    |    |
|    |    |-- number(2)
|    |    |    |
|    |    |    |-- number(1)  --> prints 1
|    |    |    --> prints 2
|    |    --> prints 3
|    --> prints 4
--> prints 5
*/