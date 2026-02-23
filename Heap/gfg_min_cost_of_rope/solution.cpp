class Solution {
  public:
    int minCost(vector<int>& arr) {
        
        priority_queue<int, vector<int>, greater<int>> minh;
        
        // Step 1: Push all ropes into min heap
        for(int i = 0; i < arr.size(); i++) {
            minh.push(arr[i]);
        }
        
        int totalCost = 0;
        
        // Step 2: Keep combining until one rope remains
        while(minh.size() > 1) {
            
            int first = minh.top();
            minh.pop();
            
            int second = minh.top();
            minh.pop();
            
            int sum = first + second;
            
            totalCost += sum;
            
            minh.push(sum);
        }
        
        return totalCost;
    }

};
