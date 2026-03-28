// User function Template for C++
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int start=0;
        int end=n-1;
        int ans=-1;
        if(arr[end]<target)return end+1;
        while(start<=end){
            int mid= start+(end-start)/2;
            if(arr[mid]>target){
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
