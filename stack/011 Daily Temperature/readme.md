# 🌡️ Daily Temperatures (Monotonic Stack)

## 📌 Problem

Given an array of integers `temperatures` represents the daily temperatures, return an array `answer` such that:

- `answer[i]` is the number of days you have to wait after the `i-th` day to get a warmer temperature.
- If there is no future day for which this is possible, keep `answer[i] == 0` instead.

---

## 🧾 Examples

### Example 1
Input:
temperatures = [73,74,75,71,69,72,76,73]

Output:
[1,1,4,2,1,1,0,0]

Explanation:
- Day 0 → wait 1 day (74 > 73)
- Day 2 → wait 4 days (76 > 75)
- Day 6 → no warmer day → 0

---

### Example 2
Input:
temperatures = [30,40,50,60]

Output:
[1,1,1,0]

---

### Example 3
Input:
temperatures = [30,60,90]

Output:
[1,1,0]

---

## 🧠 Intuition

👉 For each day, we need to find:
> "Next greater temperature on the right"

Brute force:
- For every index, check all future elements → O(n²) ❌

We need something faster.

---

## 💡 Key Idea

This is a classic:

👉 **Next Greater Element problem**

We want:
- For each index `i`
- Find the next index `j` such that:
  temperatures[j] > temperatures[i]

---

## 🧠 Why Stack?

We need to:
- Keep track of indices whose answer is not yet found
- Compare current temperature with previous ones

👉 Stack helps because:
- It stores indices in a way that we can resolve answers efficiently
- Last unresolved index is always on top

---

## 🔥 Monotonic Stack Concept

We maintain a **decreasing stack**:

- Stack stores indices
- Temperatures of stack elements are in decreasing order

---

## ⚙️ Approach

1. Create a result array initialized with 0
2. Use a stack to store indices
3. Traverse array from left to right

### For each index `i`:
- While stack is not empty AND  
  current temp > temp at stack top:
  
  → Pop index `prev`  
  → answer[prev] = i - prev

- Push current index into stack

---

## 🧑‍💻 Code

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev;
            }
            st.push(i);
        }

        return ans;
    }
};
