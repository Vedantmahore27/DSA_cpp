class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
       queue<int> q;
       vector<int> result;
       int n =arr.size();
       int j=0;
      for(int i=0;i<n;i++){
           if(arr[i]<0)q.push(arr[i]);
           if(i-j+1==k){
               if(!q.empty()){
                   result.push_back(q.front());
               }
               else  result.push_back(0);
               
               if(!q.empty() && arr[j]==q.front()){
                       q.pop();
                }
                   j++;
               } 
           }
           
           
       
       return result;
    }
};
