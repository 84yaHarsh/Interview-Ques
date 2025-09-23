/*class Solution {
public:
int binarySearch(vector<int>&nums,int start,int end,int target){
   int start =0,end = nums.size()-1;
   while(start<=end){
    int mid = start+(end-start)/2;
    if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]>target){
        end = mid -1;
    }
    else {
        start = mid+1;
    }
   }
   return -1;
}
 int findPivot(vector<int>&v1){
    int n = nums.size();
      int start =0,end =n-1;
      while(start <= end){
        int mid = start +(end-start)/2;
        int prev = (mid+n-1)%n;
        int next = (mid+1)%n;
      if(nums[mid]<=num[prev] && nums[mid]<=nums[next]){
          return v1[mid];
      }
      else if(nums[mid]>nums[start]){
        start = mid+1;
      }
      else {
        end = mid-1;
      }
      return 0;
      }
 }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int x = findPivot(nums);
        if(x>=target && x< n-1){
            return bianrySearch(nums,x+1,n-1,target);
        }
        else{
            return binarySearch(nums,0,x,target);
        }
    }
};
*/