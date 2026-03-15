# 1790. Check if One String Swap Can Make Strings Equal

## 🧠 Problem Statement

You are given two strings `s1` and `s2` of equal length.

Return `true` if it is possible to make the strings equal by performing at most one swap on exactly one of the strings.

A swap consists of choosing two indices and swapping the characters at those indices.

---

## 💡 Intuition

A single swap affects **exactly two positions**.

So the only valid scenarios are:

1️⃣ The strings are already equal → return `true`.

2️⃣ There are exactly **two mismatched positions**  
   and swapping those two characters makes the strings equal.

If mismatches are:
- 0 → valid
- 2 → check cross-match condition
- Anything else → impossible

---

## 🔍 Key Observation

If mismatch occurs at indices `i` and `j`, then:

s1[i] must equal s2[j]  
AND  
s1[j] must equal s2[i]

This ensures that swapping `s1[i]` and `s1[j]` makes the strings identical.

---

## 🚀 Approach

1. If `s1 == s2`, return `true`.
2. Traverse both strings and collect indices where characters differ.
3. If number of mismatches ≠ 2 → return `false`.
4. If mismatches == 2:
   - Check cross equality condition.
5. Return result.

---

## ⏱️ Time Complexity

- Single traversal → `O(n)`

---

## 📦 Space Complexity

- At most storing two mismatch indices → `O(1)`

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        vector<int> diff;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
                if (diff.size() > 2) return false;
            }
        }

        if (diff.size() != 2) return false;

        return s1[diff[0]] == s2[diff[1]] &&
               s1[diff[1]] == s2[diff[0]];
    }
};
