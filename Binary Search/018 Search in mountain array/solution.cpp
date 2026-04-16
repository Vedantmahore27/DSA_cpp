/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
   int binarySearchAsc(MountainArray &arr, int start, int end, int target){
          while (start <= end) {
            int mid = start + (end - start) / 2;
            int val = arr.get(mid);

            if (val == target) return mid;
            else if (val < target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }

    int binarySearchDesc(MountainArray &arr, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int val = arr.get(mid);

            if (val == target) return mid;
            else if (val > target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        vector<int>mount;
        int n=mountainArr.length();
      

        int start=0;
        int end=n-1;
        //api call jyda nahi lagni chahiye 852 wala soln nahi chalega peak in mountain array naya approach
        int peak=-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            //if(mountainArr.get(mid)> mountainArr.get(mid-1) && mountainArr.get(mid)> mountainArr.get(mid+1)) ye call badhayega
            if(mountainArr.get(mid)< mountainArr.get(mid+1) ){
               start=mid+1;
            }
            else{
                peak=mid;
                end=mid-1;
            }
        }
     //   peak=start;
        int res1=binarySearchAsc(mountainArr,0,peak,target);
        int res2=binarySearchDesc(mountainArr,peak+1,n-1,target);
        if(res1!=-1)return res1;
        else return res2;
      
    }
};
