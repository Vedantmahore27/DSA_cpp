class Solution {
  public:
   bool possible(int k, int mid, vector<int> &arr){
        int students = 1;
        int pages = 0;

        for(int i = 0; i < arr.size(); i++){
            if(pages + arr[i] <= mid){
                pages += arr[i];
            } else {
                students++;
                pages = arr[i];
            }
        }

        return students <= k;
    }
    
    int findPages(vector<int> &arr, int k) {
        if(k > arr.size()) return -1;
        int start= *max_element(arr.begin(),arr.end());
        int end= accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(possible(k,mid,arr)){
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
