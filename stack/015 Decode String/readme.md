# 🔓 Decode String (LeetCode)

## 🧾 Problem Statement

Given an encoded string `s`, return its decoded string.

---

### 🔐 Encoding Rule:

The encoding follows this pattern:

```text
k[encoded_string]
```

Where:

* `k` is a positive integer
* `encoded_string` inside the square brackets is repeated exactly `k` times

---

### 🎯 Goal:

Return the fully **decoded string**

---

## 🧪 Examples

### Example 1:

```id="ex1"
Input:
s = "3[a]2[bc]"

Output:
"aaabcbc"
```

---

### Example 2:

```id="ex2"
Input:
s = "3[a2[c]]"

Output:
"accaccacc"
```

---

### Example 3:

```id="ex3"
Input:
s = "2[abc]3[cd]ef"

Output:
"abcabccdcdcdef"
```

---

## 💡 Intuition

### 🔥 Core Idea:

This is a **nested structure decoding problem**

👉 Whenever we see:

```text
k[ ... ]
```

We:

* Decode inside `[ ]`
* Repeat it `k` times

---

### 🧠 Key Observation:

> Nested brackets → naturally handled using recursion or stack

---

## ⚡ Step-by-Step Approach (Recursion)

### 1. Use a helper function

```cpp id="step1"
string solve(int &i, string &s)
```

👉 `i` is passed by reference to control traversal

---

### 2. Traverse the string

```cpp id="step2"
while(i < s.size())
```

---

### 3. Handle cases

#### ✅ If digit:

Build number (handle multi-digit)

```cpp id="step3"
num = num * 10 + (s[i] - '0');
```

---

#### ✅ If `[`:

* Move inside
* Recursively decode inner string

```cpp id="step4"
i++;
string inner = solve(i, s);
```

---

#### ✅ If `]`:

* End current recursion
* Return decoded string

---

#### ✅ If character:

* Add to result

---

### 4. Repeat decoded string

```cpp id="step5"
while(num--) res += inner;
```

---

## 🧠 Dry Run

```id="dry"
s = "3[a2[c]]"
```

Steps:

* `3` → repeat 3 times
* enter `[`

  * `"a"`
  * `2` → repeat 2 times
  * enter `[`

    * `"c"`
  * result → `"cc"`
  * combine → `"acc"`
* final → `"accaccacc"`

---

## ❌ Common Mistakes

* Using loop instead of controlled pointer ❌
* Not handling `]` properly ❌
* Not resetting number ❌
* Ignoring multi-digit numbers ❌

---

## ✅ C++ Code (Recursion)

```cpp id="code"
class Solution {
public:
    
    string solve(int &i, string &s) {
        string res = "";
        int num = 0;

        while(i < s.size()) {

            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            else if(s[i] == '[') {
                i++;
                string inner = solve(i, s);

                while(num--) {
                    res += inner;
                }

                num = 0;
            }

            else if(s[i] == ']') {
                return res;
            }

            else {
                res.push_back(s[i]);
            }

            i++;
        }

        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return solve(i, s);
    }
};
```

---

## 🚀 Stack Approach (Alternative)

```cpp id="stack"
class Solution {
public:
    string decodeString(string s) {
        stack<int> digit;
        stack<string> str;

        string curr = "";
        int num = 0;

        for(char ch : s){

            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }

            else if(ch == '['){
                digit.push(num);
                str.push(curr);
                num = 0;
                curr = "";
            }

            else if(ch == ']'){
                int times = digit.top(); digit.pop();
                string prev = str.top(); str.pop();

                string temp = "";
                for(int i = 0; i < times; i++){
                    temp += curr;
                }

                curr = prev + temp;
            }

            else{
                curr.push_back(ch);
            }
        }

        return curr;
    }
};
```

---

## 🧠 Complexity Analysis

| Operation        | Complexity |
| ---------------- | ---------- |
| Traversal        | O(n)       |
| String Expansion | O(n * k)   |
| Space            | O(n)       |

---

## 🎯 Key Takeaways

* This is a **parsing + recursion problem**
* Use `int &i` for controlled traversal
* `[` → go deeper
* `]` → return
* Repeat using number

---

## 🔗 Pattern Connection

Similar problems:

* Basic Calculator
* Simplify Path
* Remove Stars From String

👉 All involve **parsing + stack/recursion**

---

## 🏁 Final Thought

> “Nested problems are best solved by recursion or stack — choose wisely.”

---

🔥 Master this → you unlock advanced parsing problems.

---
