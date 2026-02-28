# 2037. Minimum Number of Moves to Seat Everyone

## 🧠 Problem Statement

There are `n` seats and `n` students.  
Each seat and student has a position represented by an integer.

You can move a student from position `x` to `y` in `|x - y|` moves.

Return the minimum number of moves required to seat each student.

---

## 💡 Intuition

To minimize total movement:

- Students closer to smaller seats should occupy smaller seats.
- Crossing assignments increases total distance.

Example:
If we mismatch smallest student with largest seat, total cost increases.

So the optimal strategy is:

👉 Sort both `seats` and `students`  
👉 Match them index-wise  

This avoids crossing and ensures minimum total movement.

---

## 🚀 Greedy Approach

### Greedy Factor:
> Always match the ith smallest student with the ith smallest seat.

Why does this work?

Because absolute difference sum is minimized when both arrays are sorted and paired in order.

This ensures:
- No crossing
- Local optimal decisions lead to global minimum

---

## 🔍 Algorithm

1. Sort `seats`
2. Sort `students`
3. Initialize `moves = 0`
4. For each index `i`:
   - Add `abs(seats[i] - students[i])` to `moves`
5. Return `moves`

---

## ⏱️ Time Complexity

- Sorting: `O(n log n)`
- Traversal: `O(n)`
- Overall: `O(n log n)`

---

## 📦 Space Complexity

- `O(1)` extra space (if sorting in place)
