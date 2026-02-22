class Solution {
public:
    //typedef pair<int,int> pii;
    using pii = pair<int,int>;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pii ,vector<pii>,greater<pii>> minh;

        unordered_map<int,int> mp;

        vector<int> ans;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;     // num , freq   //spaceO(n)=> worst
        }

        for(auto it : mp){
            minh.push({it.second , it.first});  //freq , num   //space => O(m) m=>unique element

            if(minh.size()>k)minh.pop();
        }

        while(!minh.empty()){
          ans.push_back(minh.top().second);  //num
          minh.pop();
        }

        return ans;

    }
};

//time and space 

//space

// unordered_map → O(n)
// Heap of size k → O(k)
// Output vector → O(k)

//time complexity
// push() → O(log k)
// pop() (if size > k) → O(log k)

//O(n) + O(n log k) + O(k log k)


//you can use bucket technique in which you have to declare bucket(n+1)
// bucket[frequency]= value 

//last se travels karo
//top jitna bola utna uthalo
