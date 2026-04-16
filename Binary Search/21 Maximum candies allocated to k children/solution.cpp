class Solution {
public:
    bool possible(long long k , int mid , vector<int> &candies){
        int n = candies.size();
        long long  student_possible=0;
        if(mid ==0)return 0;
         for(int i=0;i<n;i++){
            student_possible+= candies[i]/mid;
         }
         if(student_possible>=k)return true;
         return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long ans=1;
        long long start=0;
        long long  end = accumulate(candies.begin(),candies.end(),0LL); // ye dekh LL

        if(end <k)return 0;
        
        while(start<=end){
            long long  mid = start+(end-start)/2;
            if(possible(k,mid,candies)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        return ans;
    }
};
