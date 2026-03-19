
//my approach  --> bhai kabhi optimise bhi soach liya kar ye to pata hona chahiye ki ham push bhi kar sakte condition ke acc 
// + + 
// - +
// - - 
//ye kabhi nahi takrayega 

//tak rayega ye wale log only
//- +

//think do dry run 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int>ans;

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>0 && asteroids[i]<0 && st.top() < abs(asteroids[i]) ){
  
                st.pop();
               
            }

            if(!st.empty() && st.top() >= abs(asteroids[i]) && st.top()>0 && 0>asteroids[i]){
                if(st.top()==abs(asteroids[i]))st.pop();
                continue;
            }
            
            st.push(asteroids[i]);
            
        }
        while(!st.empty()){
          ans.push_back(st.top());
          st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//optimise littile bit
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> v;
        stack<int> s;
        int n= arr.size();

        for(int i=0;i<n;i++){
            if(s.size()==0 || arr[i]>0) s.push(arr[i]);
            
            else {
               while(s.size()>0 && s.top() >0 && s.top()< arr[i]*-1){
                 s.pop();
                }
                if(s.size()==0 || s.top() <0) s.push(arr[i]);
                else if(s.top()==abs(arr[i])){
                    s.pop();
                }
            }
            
        }
           while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(), v.end());
        return v;
            
    }
};
