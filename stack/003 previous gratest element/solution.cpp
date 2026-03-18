
// AS WE KNOW ALL LIKE PREVIOUS GRATEST , SMALLET , NEXT GRATEST SMALLEST WE USE EARLIER WAY NOW THIS IS SOMETHING NEW IN SMALL SYNTAX YOU CAN TRY IT  EASY ROHIT NEGI APPROACH

// APPROACH I WANT PREVIOUS GRATEST, I MOVE FROM N-1 TO 0 CHECH IS MY CURRENT IS GRATER THAN TOP (top previous ele) -> yes -> then At Top index in result array write current val of arr,
//then check for its lower element of stack by popping out top element  while(! st.empty() && arr[i] > arr[st.top()]) 
//->no do nothing
// push ele everytime

// lastly some ele will remain in stack who dont have greater so we will assign them val as -1;

class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            
            while(! st.empty() && arr[i] > arr[st.top()]){
                res[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            res[st.top()]=-1;
            st.pop();
        }
        
        return res;
    }
};
