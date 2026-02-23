class Solution {
  public:
    
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        priority_queue<int> maxh;
        
        long long sum=0;
        
        for(int i=0;i<N;i++){
            maxh.push(A[i]);
            if(maxh.size()>K1)maxh.pop();
        }
        long long first=maxh.top();
        
       while(!maxh.empty()) {
            maxh.pop();
          }
        
        for(int i=0;i<N;i++){
            maxh.push(A[i]);
            if(maxh.size()>K2)maxh.pop();
        }
        long long second=maxh.top();
        
        for(int i=0;i<N;i++){
            if(A[i]>first && A[i]<second){
                sum+=A[i];
            }
        }
        
        return sum;
        
    }
};
