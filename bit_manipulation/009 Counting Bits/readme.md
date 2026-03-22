# 🧠 Counting Bits (LeetCode 338)

## 📌 Problem Statement

Given an integer `n`, return an array `ans` of length `n + 1` such that:

* `ans[i]` = number of **1's in the binary representation** of `i`
* for all `0 ≤ i ≤ n`

---

## ✨ Example

### Example 1:

```
Input: n = 2
Output: [0,1,1]

Explanation:
0 → 0 → 0 ones  
1 → 1 → 1 one  
2 → 10 → 1 one  
```

---

### Example 2:

```
Input: n = 5
Output: [0,1,1,2,1,2]

Explanation:
0 → 0 → 0  
1 → 1 → 1  
2 → 10 → 1  
3 → 11 → 2  
4 → 100 → 1  
5 → 101 → 2  
```

---

# 🚀 Approaches

---

## 🧩 1. Brute Force

### 💡 Idea

For every number, count set bits manually using bit operations.

---

### 💻 Code

```cpp
class Solution {
public:
    int countOnes(int x) {
        int cnt = 0;
        while (x > 0) {
            cnt += (x & 1);
            x >>= 1;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            ans.push_back(countOnes(i));
        }
        return ans;
    }
};
```

---

### ⏱ Complexity

* Time: `O(n log n)`
* Space: `O(1)` (excluding output)

---

## ⚡ 2. Better Approach (DP + Bit Shift)

### 💡 Idea

Use previously computed results:

```
ans[i] = ans[i / 2] + (i & 1)
```

* `i / 2` → removes last bit
* `(i & 1)` → gives last bit

---

### 💻 Code

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i / 2] + (i & 1);
        }

        return ans;
    }
};
```

---

### ⏱ Complexity

* Time: `O(n)`
* Space: `O(n)`

---

## 🔥 3. Optimal Approach (DP + Bit Trick)

### 💡 Idea

Use:

```
ans[i] = ans[i & (i - 1)] + 1
```

### 🧠 Key Insight:

* `i & (i - 1)` removes the **last set bit**
* So we reuse a smaller computed result

---

### 💻 Code

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;
    }
};
```

---

### ⏱ Complexity

* Time: `O(n)`
* Space: `O(n)`

---

# 🧠 Key Concepts

### 🔹 Bit Manipulation

* `(i & 1)` → last bit
* `i >> 1` → remove last bit
* `i & (i - 1)` → remove last set bit

---

### 🔹 Dynamic Programming

* Build solution using previously computed values
* Avoid recomputation

---

# 📊 Comparison

| Approach | Time       | Space | Idea                |
| -------- | ---------- | ----- | ------------------- |
| Brute    | O(n log n) | O(1)  | Count bits manually |
| Better   | O(n)       | O(n)  | Shift + last bit    |
| Optimal  | O(n)       | O(n)  | Remove last set bit |

---

# 🎯 Interview Tip

👉 Best explanation:

> “We use dynamic programming with bit manipulation.
> Using `i & (i-1)` removes the lowest set bit, allowing us to reuse previously computed results and achieve O(n) time complexity.”

---

# 🔥 Bonus

### Check if number is power of 2:

```cpp
if (n > 0 && (n & (n - 1)) == 0)
```

---

# ✅ Conclusion

* Start with brute → optimize using DP
* Best solution uses **bit trick + DP**
* Very common **interview question pattern**

---

Happy Coding 💻🔥
