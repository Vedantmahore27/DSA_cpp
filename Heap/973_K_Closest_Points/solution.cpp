class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int m = points[0].size();
        priority_queue<pair<int,pair<int,int>>> maxh;
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            int val= points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxh.push({val,{points[i][0],points[i][1]}});
            if(maxh.size()>k)maxh.pop();        
        }
        while(!maxh.empty()){
            ans.push_back({maxh.top().second.first,maxh.top().second.second});
            maxh.pop();
        }
        return ans;
    }
};
