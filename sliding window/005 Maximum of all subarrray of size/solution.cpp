class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int>result;
        list<int> l;
        
        int j =0;
        for(int i =0;i<n;i++){
            while(l.size()>0 && l.back()<arr[i])l.pop_back();
            l.push_back(arr[i]);
            if(i-j+1==k){
                result.push_back(l.front());
                if(l.front()==arr[j])l.pop_front();
                j++;
            }
        }
        return result;
    }
};
