# 🔢 658. Find K Closest Elements

- **Platform:** LeetCode  
- **Difficulty:** Medium  
- **Topic:** Heap / Priority Queue  
- **Pattern:** Top-K Elements  

---

## 🧠 Problem Summary

Given a sorted integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array.

### Conditions:
- The result must be sorted in ascending order.
- If two numbers have the same distance from `x`, choose the smaller number.

---

## 💡 Approach (Heap - Top K Pattern)

We use a **Max Heap of size k**.

### Why Max Heap?

- We want to keep the `k` closest elements.
- So we remove the element with the **largest distance** whenever size exceeds `k`.

### Steps:

1. Traverse the entire array.
2. Push `{abs(arr[i] - x), arr[i]}` into a max heap.
3. If heap size exceeds `k`, remove the top element (farthest one).
4. Extract remaining elements from heap.
5. Sort the result before returning.

---

Time Complexity

Heap insertion for n elements → O(n log k)

Sorting k elements → O(k log k)
