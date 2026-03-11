# Evaluate Reverse Polish Notation

**LeetCode Problem:** 150
**Difficulty:** Medium
**Pattern:** Stack / Expression Evaluation

---

# Problem Statement

Evaluate the value of an arithmetic expression in **Reverse Polish Notation (RPN)**.

Valid operators are:

```
+  -  *  /
```

Each operand may be an integer or another expression.

Return the **result of the evaluation**.

Note:

* Division between two integers should truncate toward zero.
* The input is always a valid RPN expression.

---

# What is Reverse Polish Notation?

Reverse Polish Notation (RPN) is a mathematical notation where **operators come after operands**.

Example:

```
Infix Expression:
(2 + 1) * 3

RPN Expression:
2 1 + 3 *
```

Evaluation steps:

```
2 1 + → 3
3 3 * → 9
```

Result:

```
9
```

---

# Example 1

Input

```text
tokens = ["2","1","+","3","*"]
```

Output

```
9
```

Explanation

```
(2 + 1) * 3 = 9
```

---

# Example 2

Input

```text
tokens = ["4","13","5","/","+"]
```

Output

```
6
```

Explanation

```
4 + (13 / 5)
= 4 + 2
= 6
```

---

# Example 3

Input

```text
tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
```

Output

```
22
```

---

# Intuition

In Reverse Polish Notation:

* Operands appear **before operators**
* Each operator works on the **last two operands**

A **stack** perfectly models this behavior.

Steps:

1. If the token is a **number**, push it into the stack.
2. If the token is an **operator**:

   * Pop the **top two elements**
   * Perform the operation
   * Push the result back into the stack.
3. At the end, the stack will contain **one value**, which is the final result.

---

# Approach (Stack)

1. Create a stack of integers.
2. Traverse through the tokens.
3. If token is a number → push it.
4. If token is an operator:

   * Pop two values
   * Perform the operation
   * Push the result.
5. Return the top of the stack.

---

# Algorithm

1. Initialize an empty stack.
2. Iterate through each token.
3. Check if token is an operator.
4. Pop operands and evaluate expression.
5. Push result back to stack.
6. After traversal, return stack top.

---

# Time Complexity

```
O(n)
```

Each token is processed once.

---

# Space Complexity

```
O(n)
```

Stack stores operands during evaluation.
