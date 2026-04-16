class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0;
        int n = nums.size();
        int end = n-1;
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-2]<nums[n-1])return n-1;

        while(start<=end){
              int mid = start+(end-start)/2;

              if(nums[mid]>nums[mid+1] && nums[mid]> nums[mid-1])return mid;
              else if(nums[mid]<nums[mid+1]){
                      start=mid+1;
              }
              else{
                end=mid-1;
              }
        }
        return -1;
    }
};

//OR 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Increasing slope → peak on right
                start = mid + 1;
            } else {
                // Decreasing slope → peak on left (including mid)
                end = mid;
            }
        }

        return start;
    }
};
