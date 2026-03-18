# Stock Spanner (LeetCode 901)

## 📌 Problem Overview

The **Stock Spanner** problem asks us to design a class that collects daily stock prices and returns the **span** of the stock’s price for the current day.

The **span** of the stock’s price today is defined as:

> The maximum number of consecutive days (starting from today and going backward) for which the stock price was **less than or equal to today's price**.

### Example

| Day | Price | Span |
| --- | ----- | ---- |
| 1   | 100   | 1    |
| 2   | 80    | 1    |
| 3   | 60    | 1    |
| 4   | 70    | 2    |
| 5   | 60    | 1    |
| 6   | 75    | 4    |
| 7   | 85    | 6    |

---

# 🧠 Key Idea

To solve this efficiently, we use a **Monotonic Stack**.

The stack stores:

```
(price, index)
```

Where:

* `price` = stock price
* `index` = day number

The stack maintains **previous greater prices**.

When a new price arrives:

1. Remove all prices from the stack that are **≤ current price**.
2. If the stack becomes empty → span = current day index.
3. Otherwise → span = current index − previous greater price index.
4. Push `(price, index)` into the stack.

---

# ⚙️ Algorithm

1. Maintain a stack storing `(price, index)`.
2. Increment the day counter `i`.
3. Pop elements from the stack while the top price is less than or equal to the current price.
4. Calculate span:

   * If stack is empty → `span = i`
   * Else → `span = i - st.top().second`
5. Push `{price, i}` into the stack.
6. Return span.

---

# ⏱ Time Complexity

| Operation         | Complexity         |
| ----------------- | ------------------ |
| `next()`          | **O(1) amortized** |
| Total for N calls | **O(N)**           |

Each element is pushed and popped **at most once**.

---

# 📦 Space Complexity

```
O(N)
```

For storing elements in the stack.

---

# 🔑 Important Concept

This problem uses the **Monotonic Stack Pattern**, which is common in many stack-based problems like:



---

# 🚀 Takeaway

The key insight is to maintain a **monotonic decreasing stack** so that smaller elements are removed when a larger price arrives.
This ensures efficient computation of spans without re-checking all previous elements.
