# 🔥 Count Occurrences of Anagrams

## 🧩 Problem Statement
Given two strings:
- `pat` → pattern
- `txt` → text

Find the **count of occurrences of anagrams of `pat` in `txt`**.

👉 An anagram is a rearrangement of characters.

---

## 💡 Intuition

Brute force:
- Generate all substrings of size `k`
- Check if each is anagram → O(n * k log k) ❌

---

## 🚀 Optimized Approach — Sliding Window + Frequency Map

- Store frequency of characters of `pat`
- Use a sliding window of size `k = pat.size()`
- Track matches using a counter `cnt`

### 🧠 Key Idea
- `cnt` = number of unique characters whose frequency is NOT zero
- When `cnt == 0` → valid anagram found ✅

---

## ⚙️ Approach

1. Store frequency of `pat` in map
2. Initialize:
   - `cnt = map.size()`
   - window size = `k`
3. Traverse `txt`:
   - Decrease frequency of current char
   - If freq becomes 0 → `cnt--`
4. When window size == k:
   - If `cnt == 0` → increment answer
   - Before sliding:
     - Restore outgoing char
     - If freq becomes 1 → `cnt++`
5. Slide window

---

## 📌 Example 1 (Step by Step)

```
Input: pat = "for", txt = "forxxorfxdofr"

k = 3

Windows:
[for] → ✅ anagram
[orx] → ❌
[rxx] → ❌
[xxo] → ❌
[xor] → ❌
[orf] → ✅
[rfx] → ❌
[fxd] → ❌
[xdo] → ❌
[dof] → ❌
[ofr] → ✅

Output: 3
```

---

## 📌 Example 2

```
Input: pat = "ab", txt = "abxaba"

Windows:
[ab] → ✅
[bx] → ❌
[xa] → ❌
[ab] → ✅
[ba] → ✅

Output: 3
```

---

## 📌 Example 3 (Edge Case)

```
Input: pat = "aaa", txt = "aaaaaa"

Windows:
[aaa] → ✅
[aaa] → ✅
[aaa] → ✅
[aaa] → ✅

Output: 4
```

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    int search(string &pat, string &txt) {
        unordered_map<char,int> mp;
        int k = pat.size();
        int ans = 0;
        int n = txt.size();
        
        for(auto ch : pat){
            mp[ch]++;
        }
        
        int cnt = mp.size();
        int j = 0;

        for(int i = 0; i < n; i++){
            mp[txt[i]]--;
            if(mp[txt[i]] == 0){
                cnt--;
            }

            if(i - j + 1 == k){
                if(cnt == 0){
                    ans++;
                }

                mp[txt[j]]++;
                if(mp[txt[j]] == 1){
                    cnt++;
                }

                j++;
            }
        }

        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1) (at most 26 characters)

---

## 🎯 Key Takeaways

- Use **Sliding Window** for fixed-size substring problems
- Use **Frequency Map** to track characters
- `cnt == 0` → all characters matched → anagram found

---

## 🏁 Summary

👉 Maintain frequency map of pattern  
👉 Slide window over text  
👉 Track matches using `cnt`  

💯 Efficient solution in **O(n)** instead of brute force 🚀
