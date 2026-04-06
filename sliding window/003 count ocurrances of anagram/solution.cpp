// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        unordered_map<char,int>mp;
        int k = pat.size();
        int ans=0;
        int n =txt.size();
        
        for(auto ch : pat){
            mp[ch]++;
        }
        
        int cnt = mp.size();
        int j=0;
        for(int i=0;i<n;i++){
            mp[txt[i]]--;
            if(mp[txt[i]]==0){
                cnt--;
                
            }
            if(i-j+1==k){
                if(cnt==0){
                    ans++;
                }
                mp[txt[j]]++;
                if(mp[txt[j]]==1)cnt++;
                j++;
            }
        }
        return ans;
        
    }
};
