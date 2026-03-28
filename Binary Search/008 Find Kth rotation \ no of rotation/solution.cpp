class Solution {
  public:
    int findKRotation(vector<int> &arr) {
      int n = arr.size();
        int start = 0, end = n - 1;
          
        // If the array is not rotated, return the first element
        if (arr[start] <= arr[end]) return start;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(arr[mid]<arr[(mid+1)%n] && arr[mid]<arr[(mid-1+n)%n])return mid;
            else if(arr[mid]>=arr[0])start=mid+1;
            else if(arr[mid]<=arr[n-1]) end=mid-1;
            
        }
        return 0;

    }
};
