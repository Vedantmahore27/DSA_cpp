class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0]>target) return 0;
        if(nums[n-1]<target) return n;
        int indx=0;
        int start=0;
        int end = n-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target){
                end=mid-1;
            }
            else start=mid+1;
        }
  
        return end+1;
    }
};
