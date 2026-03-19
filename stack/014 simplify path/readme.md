# 🧭 Simplify Path (LeetCode)

## 🧾 Problem Statement

Given a string `path`, which is an **absolute path** in a Unix-style file system:

---

### 📁 Rules:

* `.` → current directory (ignore)
* `..` → move to parent directory
* Multiple `/` → treated as a single `/`
* The path always starts with `/`

---

### 🎯 Goal:

Return the **simplified canonical path**

---

## 🧪 Examples

### Example 1:

```id="ex1"
Input:
path = "/home/"

Output:
"/home"
```

---

### Example 2:

```id="ex2"
Input:
path = "/../"

Output:
"/"
```

---

### Example 3:

```id="ex3"
Input:
path = "/home//foo/"

Output:
"/home/foo"
```

---

### Example 4:

```id="ex4"
Input:
path = "/a/./b/../../c/"

Output:
"/c"
```

---

## 💡 Intuition

### 🔥 Core Idea:

This is a **stack simulation problem**

👉 Think like navigating folders:

* Go inside folder → push
* Go back (`..`) → pop
* Stay (`.`) → ignore

---

### 🧠 Key Observation:

> We only care about valid directory names and how navigation affects them

---

## ⚡ Step-by-Step Approach

### 1. Traverse the path character by character

* Build folder names using a temporary string

---

### 2. When `/` is encountered

Process the current folder name:

```cpp id="step2"
if ".." → pop from stack
if "." or "" → ignore
else → push folder name
```

---

### 3. Handle the last segment

After traversal, process the remaining string (important!)

---

### 4. Build the final path

* Join all elements in stack with `/`

---

## 🧠 Dry Run

```id="dry"
path = "/a/./b/../../c/"
```

Steps:

* `"a"` → push → [a]
* `"."` → ignore
* `"b"` → push → [a, b]
* `".."` → pop → [a]
* `".."` → pop → []
* `"c"` → push → [c]

👉 Final = `/c` ✅

---

## ❌ Common Mistakes

* Ignoring last segment ❌
* Pushing `"."` or `".."` directly ❌
* Not checking empty stack before popping ❌
* Handling logic after traversal instead of during ❌

---

## ✅ C++ Code

```cpp id="code"
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string str = "";

        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                if(str == ".."){
                    if(!st.empty()) st.pop();
                }
                else if(str != "" && str != "."){
                    st.push(str);
                }
                str = "";
            } else {
                str.push_back(path[i]);
            }
        }

        // 🔥 handle last segment
        if(str == ".."){
            if(!st.empty()) st.pop();
        }
        else if(str != "" && str != "."){
            st.push(str);
        }

        // build result
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};
```

---

## 🚀 Optimized Approach (Using Vector)

```cpp id="opt"
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string str = "";

        for(int i = 0; i <= path.size(); i++){
            if(i == path.size() || path[i] == '/'){
                if(str == ".."){
                    if(!st.empty()) st.pop_back();
                }
                else if(str != "" && str != "."){
                    st.push_back(str);
                }
                str = "";
            } else {
                str.push_back(path[i]);
            }
        }

        string ans = "";
        for(string &dir : st){
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};
```

---

## 🧠 Complexity Analysis

| Operation        | Complexity |
| ---------------- | ---------- |
| Traversal        | O(n)       |
| Stack Operations | O(n)       |
| Space            | O(n)       |

---

## 🎯 Key Takeaways

* This is a **stack-based navigation problem**
* Process decisions during traversal (not after)
* `".."` → go back
* `"."` → ignore
* valid names → push

---

## 🔗 Pattern Connection

Similar problems:

* Remove Stars From String
* Validate Stack Sequences
* Backspace String Compare

👉 All involve **undo / reverse operations using stack**

---

## 🏁 Final Thought

> “Treat folders like stack — go forward, go back, ignore noise.”

---

🔥 Master this → you’ll handle file systems, URL parsing, and stack problems easily.

---
