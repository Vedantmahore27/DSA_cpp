class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)return x;
        int start=0;
        int end = x/2;
        int res=-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if((long long)mid*mid==x)return mid;
            else if((long long)mid*mid < x){
                res=mid;
                start=mid+1;
            }
           // else end=mid-1;
        }
        return res;
    }
};
