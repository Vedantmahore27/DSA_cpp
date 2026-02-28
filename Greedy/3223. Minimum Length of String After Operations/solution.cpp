class Solution {
public:
    int minimumLength(string s) {
        int n =s.size();
        int sum=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        for(int i=0;i<n;i++){
            if(mp[s[i]]>=3)mp[s[i]]=mp[s[i]]-2;
        }
        for(auto it : mp){
            sum+=it.second;
        }
        return sum;
    }
};
