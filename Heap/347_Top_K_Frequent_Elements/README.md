# 🔢 347. Top K Frequent Elements

- **Platform:** LeetCode  
- **Difficulty:** Medium  
- **Topic:** Heap / Bucket Sort  
- **Pattern:** Top-K Elements  

---

## 🧠 Problem Summary

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

You may return the answer in any order.

---

# ✅ Approach 1: Min Heap (Top-K Pattern)

### 💡 Idea

- Count frequency using `unordered_map`.
- Use a **min heap of size k**.
- Keep only the k highest frequency elements.
- Remove smallest frequency when size exceeds k.

---

## 💻 C++ Code (Min Heap)

#⏱ Time Complexity (Min Heap)

Building frequency map → O(n)

Heap operations → O(n log k)

Extracting k elements → O(k log k)

👉 Final Time Complexity:
O(n log k)

#Space Complexity (Min Heap)

Frequency map → O(n)

Heap (size k) → O(k)

Output → O(k)

👉 Final Space Complexity:
O(n)


##🚀 Approach 2: Bucket Sort (Optimized)
💡 Idea

Maximum possible frequency = n.
Create buckets where index = frequency.
Store numbers in bucket corresponding to their frequency.
Traverse buckets from high to low until k elements collected.
No heap required.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        for(int num : nums)
            mp[num]++;

        int n = nums.size();

        vector<vector<int>> bucket(n + 1);

        for(auto it : mp){
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

        for(int i = n; i >= 0 && ans.size() < k; i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};
