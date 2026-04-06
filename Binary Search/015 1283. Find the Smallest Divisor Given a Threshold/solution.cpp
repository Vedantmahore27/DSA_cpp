class Solution {
public:
    bool possible(vector<int> nums , int mid ,int threshold){
        int n = nums.size();
        long long sum=0;
        for(auto num : nums){
          sum = sum + ceil((double)num/(double)mid);
        }
        if(sum<=(long long)threshold)return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1;
        int end= *max_element(nums.begin(),nums.end());
        int ans=-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(possible(nums,mid,threshold)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
