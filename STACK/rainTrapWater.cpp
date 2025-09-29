/*RAIN TRAP WATER
     TIME COMPLEXITY

LEFT_MAX ->O(N)
RIGHT_MAX ->O(N)
WATER[N] ->O(N)

SO OVERALL O(N)

      SPACE COMPLEXITY
left_max[n] → O(N)

right_max[n] → O(N)

water[n] → O(N)

So total extra space = 3·O(N) = O(N)*/
#include<bits/stdc++.h>
using namespace std;
int rainTrapWater(vector<int>&arr){
    int n = arr.size();
    if(n==0) return n;
    vector<int>left_max(n);
    vector<int>right_max(n);
    left_max[0] = arr[0];
    for(int i=1; i<n; i++){
       left_max[i] = max(left_max[i-1],arr[i]);
    }
    right_max[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        right_max[i] = max(right_max[i+1],arr[i]);
    }
    vector<int>water(n);
    int waterContain =0;
    for(int i=0; i<n; i++){
        water[i] = min(left_max[i],right_max[i])-arr[i];
        waterContain+=water[i];
    }
   return waterContain;
}
int main(){
    vector<int>v1 = {3,0,0,2,0,4};
   cout<<"water contain is:"<< rainTrapWater(v1);
    return 0;
}