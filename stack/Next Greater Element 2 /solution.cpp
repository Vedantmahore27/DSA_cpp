class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      
        int n = nums.size();
         stack<int> st;
         vector<int> res;
         for(int i=n-1;i>=0;i--)st.push(nums[i]);         // see here , we put reverse ordere of array into stack do dry run

         for(int i =n-1;i>=0;i--){
            if(st.empty())res.push_back(-1);

            else if(st.top()>nums[i]){
                res.push_back(st.top());
            }
            else{
                while(!st.empty() && st.top()<=nums[i]){
                    st.pop();
                }
                if(st.empty())res.push_back(-1);
                else res.push_back(st.top());
            }
            st.push(nums[i]);
         }
          reverse(res.begin(),res.end());

          return res;
    }
};
