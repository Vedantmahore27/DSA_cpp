class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left;
        vector<int> right;
        int maxi=INT_MIN;
     
        stack<pair<int,int>> st;
        //approach ---> width= NSEL- NSER-1 ---> height is given ---> max area nikal lo

        //NSER

        for(int i=n-1;i>=0;i--){
          if(st.empty())right.push_back(n);
          else if(!st.empty() && st.top().first>=heights[i]){

            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();
            }
            if(st.empty())right.push_back(n);
            else right.push_back(st.top().second);
           
          }
         else{
               right.push_back(st.top().second);
          }
         st.push({heights[i],i});
        }
        reverse(right.begin(),right.end());

        while(!st.empty()){
            st.pop();
        }


        //NSEL

        for(int i=0;i<n;i++){
          if(st.empty())left.push_back(-1);
          else if(!st.empty() && st.top().first>=heights[i]){

            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();
            }
            if(st.empty())left.push_back(-1);
            else left.push_back(st.top().second);
           
          }
         else{
             left.push_back(st.top().second);
          }
         st.push({heights[i],i});
        }

        for(int i=0; i<n;i++){
            maxi=max(heights[i]*(right[i]-left[i]-1),maxi);
        }

        return maxi;

    }
};
