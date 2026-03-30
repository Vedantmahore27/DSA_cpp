

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int start=0;
        int end=n-1;

        while(start<=end){
            int mid = start +(end-start)/2;
                  if(nums[mid]==target)return true;
            if(nums[mid]==nums[end]&& nums[mid]==nums[start]){
                start++;
                end--;
                continue;
            }
      
            else if(nums[start]<=nums[mid]){
                  if(nums[start] <= target && target < nums[mid]){
                         end=mid-1;
                  }
                  else{
                     start=mid+1;
                  }
            }
            else if(nums[mid]<=nums[end]){
               if(nums[mid] < target && target <= nums[end]){
                        start=mid+1;
                  }
                  else{
                      end=mid-1;
                  }
            }
        }

        return false;
    }
};
