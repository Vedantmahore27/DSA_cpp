class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int n = s.size();
        int m = p.size();
       

        unordered_map<char,int> mp;

        for(int i=0;i<m;i++){
            mp[p[i]]++;
        }

        int cnt=mp.size();
        int j=0;

        for(int i=0 ;i<n;i++){
            mp[s[i]]--;
            if(mp[s[i]]==0)cnt--;
            if(i-j+1==m){
                if(cnt==0){
                    result.push_back(j);
                }
                mp[s[j]]++;
                if(mp[s[j]]==1)cnt++;
                j++;
            }
        }
         

        return result;

    }
};
