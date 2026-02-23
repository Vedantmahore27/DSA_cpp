# 📍 Sum of Elements Between k1’th and k2’th Smallest Elements

---

## 🧩 Problem Statement

Given an array of integers and two numbers k1 and k2,  
find the sum of all elements strictly between the k1’th smallest and k2’th smallest elements.

The order of elements is based on sorted order (not original index).

---

## 📌 Example

Input:
    arr = [20, 8, 22, 4, 12, 10, 14]
    k1 = 3
    k2 = 6

Sorted Array:
    [4, 8, 10, 12, 14, 20, 22]

3rd smallest element = 10  
6th smallest element = 20  

Elements strictly between them:
    12 + 14 = 26

Output:
    26

---

# 🔎 Key Insight

We do NOT need to fully sort the array.

We only need:

• k1’th smallest element  
• k2’th smallest element  
• Sum of values strictly between them  

This is an Order Statistics problem.

---

# 💡 Approach 1 – Sorting (Simple)

## Strategy

• Sort the array  
• Traverse from index (k1) to (k2 - 2)  
• Add all elements in that range  

## Complexity

Time Complexity:
    O(n log n)

Space Complexity:
    O(1) or O(n)

✔ Simple to implement  
❌ Not optimal for very large arrays  

---

# 💡 Approach 2 – Max Heap (Efficient)

## 🧠 Intuition

To find k’th smallest element efficiently:

• Maintain a max heap of size k  
• If heap size exceeds k → remove largest  

This ensures heap always contains k smallest elements.

---

## 🔁 Strategy

1️⃣ Find k1’th smallest element using max heap  
2️⃣ Find k2’th smallest element using max heap  
3️⃣ Traverse original array  
4️⃣ Add elements strictly between those two values  

---

## ⏱ Complexity

Time Complexity:
    O(n log k2)

Space Complexity:
    O(k2)

✔ More efficient than full sorting  
✔ Useful when k is small compared to n  

---

# 💡 Approach 3 – Quick Select (Advanced)

## 🧠 Idea

• Use partition logic (like QuickSort)  
• Find k1’th smallest  
• Find k2’th smallest  
• Traverse array to compute sum  

## Complexity

Average Time:
    O(n)

Worst Time:
    O(n²)

Space:
    O(1)

✔ Best average performance  
❌ More complex implementation  

---

# 📊 Edge Cases

✔ If k1 and k2 are consecutive → answer = 0  
✔ If array has duplicates → handle strictly between values  
✔ Ensure k1 < k2  

---

# 🎯 Learning Outcomes

✔ Understanding Order Statistics  
✔ Using Heap for kth smallest  
✔ Comparing sorting vs heap vs quickselect  
✔ Optimizing time complexity  

---

## 🏷 Category

Heap  
Order Statistics  
Selection Algorithm  
Sorting  

---

This problem strengthens understanding of partial sorting and heap size control, which is very common in technical interviews.
