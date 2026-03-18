# Valid Parentheses

## Problem Statement

Given a string `s` containing just the characters:

```
( ) { } [ ]
```

Determine if the input string is **valid**.

A string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every closing bracket must have a corresponding opening bracket.

---

## Example

### Example 1

Input

```
s = "()"
```

Output

```
true
```

---

### Example 2

Input

```
s = "()[]{}"
```

Output

```
true
```

---

### Example 3

Input

```
s = "(]"
```

Output

```
false
```

---

### Example 4

Input

```
s = "([)]"
```

Output

```
false
```

Explanation
Brackets close in the wrong order.

---

# Intuition

We use a **stack** to track opening brackets.

* When we see an **opening bracket**, we push it into the stack.
* When we see a **closing bracket**, we check whether it matches the **top element of the stack**.
* If it matches, we pop the stack.
* If it doesn't match or the stack is empty, the string is invalid.

At the end, if the stack is empty, the parentheses are valid.

---

# Approach (Stack)

Steps:

1. Create an empty stack.
2. Traverse the string character by character.
3. If the character is an opening bracket → push it into the stack.
4. If the character is a closing bracket:

   * Check if stack is empty → return false.
   * Check if top of stack matches the corresponding opening bracket.
   * If yes → pop the stack.
   * Otherwise → return false.
5. After traversal, check if stack is empty.

---

# Algorithm

1. Initialize an empty stack `st`.
2. Iterate through the string.
3. Push opening brackets into the stack.
4. For closing brackets:

   * Check for correct matching.
5. If stack becomes empty at the end → return true.

---

# Time Complexity

```
O(n)
```

Where `n` is the length of the string.

Each character is processed once.

---

# Space Complexity

```
O(n)
```

In the worst case, all characters may be opening brackets stored in the stack.

---

# C++ Implementation

```cpp
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char c : s){

            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{

                if(st.empty())
                    return false;

                if((st.top() == '(' && c == ')') ||
                   (st.top() == '{' && c == '}') ||
                   (st.top() == '[' && c == ']')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();
    }
};
```

---

# Key Concepts

* Stack Data Structure
* Matching Parentheses
* LIFO (Last In First Out)
* String Traversal

---

# Edge Cases

* Empty string → valid
* Only opening brackets → invalid
* Only closing brackets → invalid
* Incorrect order → invalid

---

# Tags

```
Stack
String
Simulation
```

---

# Author

Vedant Mahore
DSA Practice – Interview Preparation
