# Permutation with Spaces (GFG)

## 🧩 Problem

Given a string `s`, generate all possible strings by inserting **a space or no space** between its characters.

### Example

Input:

```
s = "ABC"
```

Output:

```
A B C
A BC
AB C
ABC
```

---

# 🧠 Key Idea

Between every pair of characters we have **two choices**:

```
1. Insert a space
2. Do not insert a space
```

If the string length is `n`, there are `n-1` possible positions for spaces.

Total combinations:

```
2^(n-1)
```

---

# ⚙️ Approach 1 — Backtracking (Pass by Reference)

### Idea

We build the answer string step by step and **modify the same string using backtracking**.

Steps:

1. Add a space and the current character.
2. Recurse.
3. Undo changes (backtrack).
4. Add the character without space.
5. Recurse again.

This approach **avoids copying strings**, making it more efficient.

---

### Code

```cpp
class Solution {
public:
    void solve(int i, string &s, string &ans, vector<string> &res){

        if(i == s.size()){
            res.push_back(ans);
            return;
        }

        // add space
        ans.push_back(' ');
        ans.push_back(s[i]);

        solve(i+1, s, ans, res);

        // backtrack
        ans.pop_back();
        ans.pop_back();

        // no space
        ans.push_back(s[i]);

        solve(i+1, s, ans, res);

        // backtrack
        ans.pop_back();
    }

    vector<string> permutation(string s) {

        vector<string> res;
        string ans;

        ans.push_back(s[0]);

        solve(1, s, ans, res);

        return res;
    }
};
```

---

### Complexity

Time Complexity

```
O(2^(n-1))
```

Space Complexity

```
O(n)
```

(recursion stack)

---

# ⚙️ Approach 2 — Recursion (Pass by Value)

### Idea

Instead of modifying the same string, we pass **a copy of the string** to every recursive call.

Since each recursion has its own copy, we **do not need to manually backtrack** at the end.

This makes the logic simpler but slightly slower due to **string copying**.

---

### Code

```cpp
class Solution {
public:
    void solve(int n, int i ,string &s,string ans,vector<string> &finial){

        if(i==n){
            finial.push_back(ans);
            return;
        }

        // add space
        ans.push_back(' ');
        ans.push_back(s[i]);

        solve(n,i+1,s,ans,finial);

        // remove space branch
        ans.pop_back();
        ans.pop_back();

        // no space
        ans.push_back(s[i]);

        solve(n,i+1,s,ans,finial);
    }

    vector<string> permutation(string s) {

       string ans="";
       ans.push_back(s[0]);

       vector<string> finial;

       int n=s.size();

       solve(n,1,s,ans,finial);

       return finial;
    }
};
```

---

### Complexity

Time Complexity

```
O(n * 2^(n-1))
```

Extra `n` factor due to **string copying**.

Space Complexity

```
O(n)
```

---

# 🌳 Recursion Tree Example

For:

```
s = "ABC"
```

Tree:

```
          A
        /   \
      A B     AB
     /   \   /  \
 A B C  A BC AB C ABC
```

Generated outputs:

```
A B C
A BC
AB C
ABC
```

---

# 🔑 Backtracking Pattern

Most backtracking problems follow this template:

```
choose
recurse
undo choice
```

Example:

```
ans.push_back(x)
solve(...)
ans.pop_back()
```

This pattern appears in many problems:

* Subsets
* Permutations
* Combination Sum
* Generate Parentheses
* Letter Case Permutation

---

# ⭐ Key Observations

1. We start with the first character already in the answer.
2. At every next character, we decide:

   * **space + character**
   * **character only**
3. Backtracking ensures the string returns to its previous state.

---

# 🚀 Interview Insight

This problem is a classic **recursion/backtracking template** used to understand:

* Choice making
* Recursion tree exploration
* State restoration (backtracking)

Mastering this pattern makes many problems easier to solve.
