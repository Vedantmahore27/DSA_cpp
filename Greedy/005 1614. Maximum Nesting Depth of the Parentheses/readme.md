# 1614. Maximum Nesting Depth of the Parentheses

## 🧠 Problem Statement

Given a valid parentheses string `s`, return the maximum nesting depth of the parentheses.

The nesting depth is defined as the maximum number of nested parentheses.

---

## 💡 Intuition

Every time we encounter `'('`, the nesting depth increases.

Every time we encounter `')'`, the nesting depth decreases.

So we can:

- Maintain a counter `cnt` to track current depth.
- Maintain a variable `maxi` to store the maximum depth seen so far.

We update the maximum whenever depth increases.

---

## 🚀 Approach (State Tracking)

1. Initialize:
   - `cnt = 0` → current depth
   - `maxi = 0` → maximum depth

2. Traverse the string:
   - If `'('` → increment `cnt` and update `maxi`
   - If `')'` → decrement `cnt`

3. Return `maxi`

---

## ⏱️ Time Complexity

- Single traversal of string → `O(n)`

---

## 📦 Space Complexity

- Only two integer variables used → `O(1)`

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int cnt = 0;
        int maxi = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else if(s[i] == ')'){
                cnt--;
            }
        }
        return maxi;
    }
};
