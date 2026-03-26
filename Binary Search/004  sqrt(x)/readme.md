# 🧮 Sqrt(x)

## 📘 Problem Description
Given a non-negative integer `x`, return the **square root of x** rounded down to the nearest integer.

The returned integer should be the **floor value** of the square root.  
You **must not use** any built-in exponent function or operator.

---

## 🧾 Examples

### Example 1:
Input: x = 4  
Output: 2  
Explanation: √4 = 2

### Example 2:
Input: x = 8  
Output: 2  
Explanation: √8 = 2.828..., so return 2 (floor value)

---

## 📌 Constraints
- `0 <= x <= 2^31 - 1`

---

## 🧠 Approach (Binary Search)

Since the square root lies in a **search space**, we can apply **Binary Search**.

### 🔹 Key Idea:
Find the **largest number `mid` such that `mid * mid <= x`**

### 🔹 Algorithm:
1. If `x <= 1`, return `x`
2. Set `low = 1`, `high = x / 2`
3. While `low <= high`:
   - `mid = low + (high - low) / 2`
   - If `mid * mid == x` → return `mid`
   - If `mid * mid < x`:
     - store `mid` as answer
     - move right → `low = mid + 1`
   - Else:
     - move left → `high = mid - 1`
4. Return stored answer

---

## 💻 Implementation (C++)

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        int low = 1, high = x / 2;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid == x)
                return mid;
            else if (mid * mid < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
