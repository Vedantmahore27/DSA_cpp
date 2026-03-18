class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
           while(!st.empty() && heights[i] < heights[st.top()]){
               int indx= st.top();
               st.pop();
               if(!st.empty()){
                 ans = max(ans, heights[indx]*(i-st.top()-1));
               }
               else{
                  ans = max(ans, heights[indx]*i);
               }
           }
           st.push(i);
        }

        while(!st.empty()){
            int indx= st.top();
            st.pop();

            if(!st.empty()){
               ans= max(ans, heights[indx]*(n-st.top()-1));
            }
            else{
                ans= max(ans, heights[indx]*(n));
            }
        }

        return ans;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi= INT_MIN;
        vector<int> v(m,0);

        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){

            if(matrix[i][j]=='0')v[j]=0;
            else v[j]=1+v[j];
           }
          maxi=max(maxi ,largestRectangleArea(v));
        }

        return maxi;
    }
};
