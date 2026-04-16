class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end = nums.size()-1;
     
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];
      
        while(start<=end){
            int mid = start+(end-start)/2;
          
            if(mid>0 && mid<nums.size()-1 && nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])return nums[mid];
              
            else if((mid%2!=0 && nums[mid+1]==nums[mid]) || (mid%2==0 && nums[mid-1]==nums[mid]) ){
                end=mid-1;
            }
              
            else{
                start=mid+1;
            }
        }
        return -1;;
    }
};

//OR SECOND APPROACH

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // Ensure mid is even
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                start = mid + 2;
            } else {
                end = mid;
            }
        }

        return nums[start];
    }
};
