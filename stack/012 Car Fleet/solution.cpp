class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n = position.size();
       vector<double> time(n);
       stack<double> st;
       vector<pair<int,int>> v;
       for(int i =0;i<n;i++){
        v.push_back({position[i],i});
       }
       sort(v.begin(),v.end());
       for(int i=0;i<n;i++){
        position[i]=speed[v[i].second];
       }
       for(int i=0;i<n;i++){
        speed[i]=position[i];
        position[i]=v[i].first;
       }

       for(int i=0;i<n;i++){
         time[i]= (double)(target-position[i])/speed[i];
       }

       for(int i=n-1;i>=0;i--){
          if(!st.empty() && st.top()>=time[i])continue;
          st.push(time[i]);
       }

     return st.size();

     
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>>cars;

        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end());
        stack<double>st;
        for(int i=n-1;i>=0;i--){
            double time = (double)(target-cars[i].first)/cars[i].second;

            if(!st.empty() && st.top()>=time)
            continue;

            st.push(time);
        }
        return st.size();
    }
};
