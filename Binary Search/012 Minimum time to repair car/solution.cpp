class Solution {
public:
    bool check(vector<int> &ranks,int cars,long long mid){
        int n =ranks.size();
        long long  cnt=0;
        for(int i=0;i<n;i++){
            cnt=cnt+(sqrt((double)mid/ranks[i]));
        }
        if(cnt>=cars)return true;
        else return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n =ranks.size();
        long long ans=0;
        long long start= 1;
      long long end = 1LL * (*max_element(ranks.begin(), ranks.end())) * cars * cars;
        while(start<=end){
            long long  mid=start+(end-start)/2;
            if(check(ranks,cars,mid)){
                ans=mid;
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        return ans;
    }
};
