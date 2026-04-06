# 🔥 438. Find All Anagrams in a String

## 🧩 Problem Statement
Given two strings `s` and `p`, return **all starting indices of `p`'s anagrams in `s`**.

👉 An anagram is a rearrangement of characters.  
👉 Return indices in **any order**.

---

## 💡 Intuition

Brute force:
- Generate all substrings of size `k`
- Sort & compare → O(n * k log k) ❌

---

## 🚀 Optimized Approach — Sliding Window + Frequency Map

- Maintain a frequency map of `p`
- Use a sliding window of size `k = p.size()`
- Track matches using a counter `cnt`

---

## 🧠 Key Idea

- `cnt` = number of unique characters whose frequency is NOT zero
- When `cnt == 0` → valid anagram found ✅
- Store **starting index (j)** instead of count

---

## ⚙️ Approach

1. Store frequency of `p` in map
2. Initialize:
   - `cnt = map.size()`
   - window size = `k`
3. Traverse string `s`:
   - Decrease frequency of current char
   - If freq becomes 0 → `cnt--`
4. When window size == k:
   - If `cnt == 0` → store index `j`
   - Before sliding:
     - Restore outgoing char
     - If freq becomes 1 → `cnt++`
5. Slide window

---

## 📌 Example 1 (Step by Step)

```
Input: s = "cbaebabacd", p = "abc"

k = 3

Windows:
[cba] → ✅ index 0
[bae] → ❌
[aeb] → ❌
[eba] → ❌
[bab] → ❌
[aba] → ❌
[bac] → ✅ index 6
...

Output: [0, 6]
```

---

## 📌 Example 2

```
Input: s = "abab", p = "ab"

Windows:
[ab] → ✅ index 0
[ba] → ✅ index 1
[ab] → ✅ index 2

Output: [0, 1, 2]
```

---

## 📌 Example 3 (No Anagram)

```
Input: s = "abcdefg", p = "hij"

Output: []
```

---

## 🧠 Code (C++)

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        vector<int> result;

        for (auto ch : p) {
            mp[ch]++;
        }

        int cnt = mp.size();
        int k = p.size();
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]--;

            if (mp[s[i]] == 0) {
                cnt--;
            }

            if (i - j + 1 == k) {
                if (cnt == 0) {
                    result.push_back(j);
                }

                mp[s[j]]++;
                if (mp[s[j]] == 1) {
                    cnt++;
                }

                j++;
            }
        }

        return result;
    }
};
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1) (only lowercase letters)

---

## 🎯 Key Takeaways

- Fixed window → **Sliding Window**
- Use **frequency map + counter trick**
- `cnt == 0` → anagram found
- Store index instead of count

---

## 🏁 Summary

👉 Convert anagram checking into frequency matching  
👉 Slide window of size `k`  
👉 Track matches efficiently using `cnt`  

💯 Optimized from **O(n * k log k)** → **O(n)** 🚀
