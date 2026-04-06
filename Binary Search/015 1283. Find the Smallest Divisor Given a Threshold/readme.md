# 🔍 Smallest Divisor Given a Threshold (LeetCode)

## 🧩 Problem Statement

Given an array `nums` and an integer `threshold`, we need to find the **smallest divisor** such that:

[
\sum \lceil \frac{nums[i]}{divisor} \rceil \leq threshold
]

---

## 💡 Intuition (Most Important)

* We need to **minimize the divisor**
* For every divisor, we calculate:

  ```
  sum = ceil(nums[0]/divisor) + ceil(nums[1]/divisor) + ...
  ```

---

### 🔥 Key Observation

* As **divisor increases → sum decreases**
* This is **monotonic behavior**

👉 So we can apply **Binary Search on Answer**

---

### 🎯 Search Space

* Minimum divisor = `1`
* Maximum divisor = `max(nums)`

👉 Why not more than max?

Because:

```
If divisor ≥ max(nums),
then every term becomes 1
⇒ sum = n (constant)
```

So after that, answer **does not change**

---

## ⚙️ Approach

1. Apply Binary Search on range `[1, max(nums)]`
2. For each `mid` (candidate divisor):

   * Calculate sum using:

     ```
     ceil(num / mid)
     ```
3. If sum ≤ threshold:

   * Store answer
   * Try smaller divisor (`end = mid - 1`)
4. Else:

   * Increase divisor (`start = mid + 1`)

---

## ⚡ Optimization Trick

Instead of:

```cpp
ceil((double)num / mid)
```

Use:

```cpp
(num + mid - 1) / mid
```

👉 Faster + no floating point

---

## 🚀 Code (Copy-Paste Ready)

```cpp
class Solution {
public:
    bool possible(vector<int>& nums, int mid, int threshold) {
        long long sum = 0;
        
        for (auto num : nums) {
            sum += (num + mid - 1) / mid; // integer ceil
            
            if (sum > threshold) return false; // early exit
        }
        
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (possible(nums, mid, threshold)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
```

---

## 📊 Example

```
nums = [1,2,5,9]
threshold = 6
```

Try divisor = 5:

```
ceil(1/5)=1
ceil(2/5)=1
ceil(5/5)=1
ceil(9/5)=2

sum = 5 ≤ 6 ✅
```

👉 Answer = 5

---

## 🧠 Key Takeaways

* Binary Search on Answer works when:

  * Condition is **monotonic**
* Always try to **tighten search space**
* Avoid floating point in interviews if possible
* Use **early exit** for optimization

---

## ⏱ Complexity

* Time: `O(n * log(max(nums)))`
* Space: `O(1)`

---

## 🏁 Summary

* Minimize divisor such that sum ≤ threshold
* Use Binary Search
* Optimize with integer ceil trick
* Keep search space tight

---

✨ Classic problem of **Binary Search on Answer + Optimization thinking**
