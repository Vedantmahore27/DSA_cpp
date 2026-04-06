class Solution {
public:
    bool possible(vector<int> bloomDay,int mid ,int m, int k){
        int n =bloomDay.size();
        int my_boquet=0;
        int consecutive_days=0;

        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                consecutive_days++;
                 if(consecutive_days>=k){
                     my_boquet++;
                     consecutive_days=0;
                    if(my_boquet==m)return true;
                 }
         }
            else{
                 consecutive_days=0;
            }
           
        }
        if(my_boquet>=m)return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n<(long long)m*k)return -1;
        int start = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(possible(bloomDay,mid,m,k)){
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
