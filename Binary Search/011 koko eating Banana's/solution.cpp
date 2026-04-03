class Solution {
public:
    bool check(int k ,int h,vector<int> nums){
        int n = nums.size();
        long hr =0;
        for(int i=0;i<n;i++){
          if(nums[i]<=k)hr++;
          else{
            int req = ceil(double(double(nums[i])/(double)k));
            hr=hr+req;
          }
        }
        if(hr<=h)return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int end = *max_element(piles.begin(),piles.end());
        int start=1;
        int ans =0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(check(mid,h,piles)){
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
