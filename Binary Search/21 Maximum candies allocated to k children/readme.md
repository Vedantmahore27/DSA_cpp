# 🍬 Maximum Candies Allocated to K Children

## 📌 Problem Statement

You are given an array `candies[]`, where each element represents a pile of candies, and an integer `k` (number of children).

👉 You can divide piles but **cannot merge them**.

Each child must get **equal number of candies**.

Return the **maximum candies per child**.

---

# 🧠 Approach 1: Brute Force

## 💡 Idea

Try all possible values of candies per child from `1` to `max(candies)` and check:

> Can we distribute at least `k` children?

---

## ⚙️ Steps

1. Loop `x = 1 → max(candies)`
2. For each `x`, compute:

   ```
   total_children = sum(candies[i] / x)
   ```
3. If `total_children >= k`, update answer

---

## ⏱️ Complexity

* **Time:** `O(n * max(candies))` ❌ Too slow
* **Space:** `O(1)`

---

# 🧠 Approach 2: Better (Binary Search on Answer)

## 💡 Idea

Instead of checking all values, use **binary search on answer space**.

👉 We search for the maximum `x` such that distribution is possible.

---

## ⚙️ Steps

1. Define range:

   ```
   start = 1
   end = max(candies)
   ```

2. For each `mid`:

   * Check if we can serve ≥ `k` children

3. If possible:

   * Try larger value → `start = mid + 1`

4. Else:

   * Reduce → `end = mid - 1`

---

## 🔍 Feasibility Check

```text
total_children = sum(candies[i] / mid)
```

If:

```text
total_children >= k
```

👉 valid

---

## ⏱️ Complexity

* **Time:** `O(n log max(candies))` ✅
* **Space:** `O(1)`

---

# 🚀 Approach 3: Optimal (Clean Binary Search)

## 💡 Improvements

* Avoid unnecessary range (`sum` is too large)
* Use `max_element` as upper bound
* Avoid division by zero

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    bool possible(long long k, long long mid, vector<int> &candies){
        long long count = 0;

        for(int c : candies){
            count += c / mid;
        }

        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long start = 1;
        long long end = *max_element(candies.begin(), candies.end());
        long long ans = 0;

        while(start <= end){
            long long mid = start + (end - start) / 2;

            if(possible(k, mid, candies)){
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
```

---

## ⏱️ Complexity

* **Time:** `O(n log max(candies))`
* **Space:** `O(1)`

---

# ⚠️ Common Mistakes

* Using `accumulate(..., 0)` → causes **overflow**
* Starting from `mid = 0` → division by zero
* Using `sum` as upper bound → unnecessary large range

---

# 🚀 Key Takeaways

* This is a **Binary Search on Answer** problem
* Always convert:

  ```
  maximize value → check feasibility
  ```
* Use tight bounds to optimize performance
* Avoid overflow using correct data types

---
