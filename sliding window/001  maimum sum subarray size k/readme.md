# 🔥 Max Sum Subarray of Size K

## 🧩 Problem Statement
Given an array of integers `arr[]` and a number `k`, find the **maximum sum of a subarray of size k**.

👉 A subarray is a **contiguous** part of the array.

---

## 💡 Intuition

Brute force:
- Check every subarray of size `k`
- Calculate sum → O(n*k) ❌

### 🚀 Optimized — Sliding Window

- Maintain a window of size `k`
- Slide it forward:
  - Add next element
  - Remove previous element

👉 No recomputation → O(n)

---

## ⚙️ Approach

1. Take sum of first `k` elements → initial window
2. Store as `maxSum`
3. Slide window:
   - Add `arr[i]`
   - Remove `arr[i-k]`
   - Update `maxSum`
4. Return `maxSum`

---

## 📌 Example 1 (Step by Step)

```
Input: arr = [100, 200, 300, 400], k = 2

Initial window:
[100, 200] → sum = 300

Slide:
+300 -100 → 500
+400 -200 → 700

Max = 700
```

---

## 📌 Example 2 (Detailed Flow)

```
Input: arr = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4

Initial window:
[1, 4, 2, 10] → sum = 17

Slide:
+23 -1 → 39  ✅ max
+3  -4 → 38
+1  -2 → 37
+0  -10 → 27
+20 -23 → 24

Output: 39
```

---

## 📌 Example 3 (Edge Case)

```
Input: arr = [100, 200, 300, 400], k = 1

Each element itself is a window:
[100], [200], [300], [400]

Output: 400
```

---

## 📌 Example 4 (Small Case)

```
Input: arr = [2, 5, 1, 8, 2], k = 3

Initial:
[2, 5, 1] → 8

Slide:
+8 -2 → 14  ✅ max
+2 -5 → 11

Output: 14
```

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    int maximumSumSubarray(int k, vector<int> &arr) {
        int n = arr.size();
        
        int windowSum = 0;
        
        // first window
        for(int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        
        int maxSum = windowSum;
        
        // sliding window
        for(int i = k; i < n; i++) {
            windowSum += arr[i];      // add next
            windowSum -= arr[i - k];  // remove previous
            
            maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
    }
};
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## 🎯 Key Takeaways

- Fixed window size → use **Sliding Window**
- Avoid recomputing sums
- Efficient one-pass solution 🚀

---

## 🏁 Summary

👉 Maintain a running window of size `k`  
👉 Update sum dynamically while sliding  

💯 Converts brute force **O(n*k)** → optimized **O(n)**
