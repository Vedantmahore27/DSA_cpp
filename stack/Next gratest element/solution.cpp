class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> finial;

        for(int i =n-1;i>=0;i--){
         if(st.empty()){
            mp[nums2[i]]=-1;
         }
         else if(st.top()>nums2[i]){
            mp[nums2[i]]=st.top();
         }
         else{
            while(!st.empty() &&st.top()<=nums2[i] ){
                st.pop();
            }
            if(st.empty())  mp[nums2[i]]=-1;
            else  mp[nums2[i]]=st.top();
         }
         st.push(nums2[i]);
         
        }

        
        for(int i =0;i<nums1.size();i++){
              finial.push_back(mp[nums1[i]]);
            }

        //here firstly i use loop which gaining complexity of O(n square)
        return finial;

    }
};
