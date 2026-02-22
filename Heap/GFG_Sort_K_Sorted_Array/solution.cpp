class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        
        priority_queue<int,vector<int>,greater<int>> minh;
        
        for(int i=0 ;i<=k;i++){
          minh.push(arr[i]);
        }
        
         int i;
       for( i= 0 ; i<n;i++){
           arr[i]=minh.top();
                
           if(i+k+1>=n)break;
           minh.push(arr[i+k+1]);
           if(minh.size()>k+1)minh.pop();
       }
       
       while(minh.size()!=0){
           arr[i]=minh.top();
           minh.pop();
           i++;
       }
    }
};
