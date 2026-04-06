# 🔥 K Sized Subarray Maximum

## 🧩 Problem Statement
Given an array `arr[]` of positive integers and an integer `k`, find the **maximum value for each contiguous subarray of size k**.

👉 Return an array of maximum values for each window.

---

## 📌 Example 1

```
Input: arr = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3

Subarrays:
[1, 2, 3] → 3
[2, 3, 1] → 3
[3, 1, 4] → 4
[1, 4, 5] → 5
[4, 5, 2] → 5
[5, 2, 3] → 5
[2, 3, 6] → 6

Output: [3, 3, 4, 5, 5, 5, 6]
```

---

## 📌 Example 2

```
Input: arr = [5, 1, 3, 4, 2], k = 1

Each element itself is a window:
[5], [1], [3], [4], [2]

Output: [5, 1, 3, 4, 2]
```

---

## 💡 Intuition

Brute force:
- For each window → find max → O(n * k) ❌

---

## 🚀 Optimized Approach — Sliding Window + Deque/List

- Use a **list (deque behavior)** to store useful elements
- Maintain elements in **decreasing order**

### 🧠 Key Idea
- Front always contains **maximum element of current window**
- Remove:
  - Smaller elements (not useful)
  - Out-of-window elements

---

## ⚙️ Approach

1. Traverse array
2. Remove all smaller elements from back
3. Push current element
4. When window size == k:
   - Front = maximum → store it
   - If outgoing element == front → remove it
5. Slide window

---

## 📌 Example 3 (Step Flow)

```
Input: arr = [2, 1, 3, 4], k = 2

Process:
[2, 1] → max = 2
[1, 3] → max = 3
[3, 4] → max = 4

Output: [2, 3, 4]
```

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> result;
        list<int> l;
        
        int j = 0;
        
        for(int i = 0; i < n; i++){
            
            while(l.size() > 0 && l.back() < arr[i])
                l.pop_back();
                
            l.push_back(arr[i]);
            
            if(i - j + 1 == k){
                
                result.push_back(l.front());
                
                if(l.front() == arr[j])
                    l.pop_front();
                    
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
- **Space Complexity:** O(k)

---

## 🎯 Key Takeaways

- Use **Sliding Window** for fixed size problems
- Use **Deque/List** for efficient max tracking
- Remove useless elements early

---

## 🏁 Summary

👉 Maintain decreasing order structure  
👉 Front always gives max  
👉 Slide window efficiently  

💯 Optimized from **O(n*k)** → **O(n)** 🚀
