class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
       int n =arr.size();
       int j=0;
       int sum=0;
       int maxi=-99;
       for(int i=0;i<n;i++){
           sum+=arr[i];
           if(i-j+1==k){
               maxi =max(sum,maxi);
               sum-=arr[j];
               j++;
           }
       }
       return maxi;
    }
};
