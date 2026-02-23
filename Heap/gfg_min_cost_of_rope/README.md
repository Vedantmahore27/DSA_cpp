# 🔗 Connect N Ropes with Minimum Cost

---

## 🧩 Problem Statement

Given an array representing the lengths of N ropes, the task is to connect all ropes into a single rope with minimum total cost.

The cost of connecting two ropes is equal to the sum of their lengths.

You must connect the ropes in such a way that the total cost incurred is minimum.

---

## 📌 Example

Input:
    [4, 3, 2, 6]

Process:
    2 + 3 = 5   → cost = 5
    4 + 5 = 9   → cost = 14
    6 + 9 = 15  → cost = 29

Output:
    29

---

## 🔎 Key Insight

The cost of each merge contributes to future merges.

If larger ropes are combined earlier, their value keeps getting added repeatedly, increasing total cost.

Therefore:

    Always combine the two smallest ropes first.

This ensures minimal contribution in future merges.

---

# 💡 Optimal Approach – Greedy + Min Heap

This problem follows the Optimal Merge Pattern.

### Strategy:

• Insert all rope lengths into a Min Heap  
• While more than one rope exists:
    - Remove the two smallest ropes
    - Add their sum to total cost
    - Insert the combined rope back into heap
• Continue until one rope remains  

---

## 🧠 Why Greedy Works

At every step, choosing the two smallest ropes minimizes immediate cost.

Since each merge affects future cost, choosing smallest first ensures the overall sum remains minimal.

This is the same principle used in:

• Huffman Coding  
• Optimal Merge Pattern  
• File Merging Problems  

---

## ⏱ Complexity Analysis

Time Complexity:
    O(n log n)

Reason:
    Each insertion and removal from heap takes log n time.
    We perform n merge operations.

Space Complexity:
    O(n)

Reason:
    Heap stores all rope lengths.

---

# 📊 Edge Cases

✔ If only one rope exists → Cost = 0  
✔ If two ropes exist → Cost = sum of both  
✔ Handles duplicate values naturally  

---

# 🎯 Learning Outcomes

✔ Understanding Greedy Strategy  
✔ Applying Min Heap efficiently  
✔ Recognizing Optimal Merge Pattern  
✔ Improving time complexity using heap  

---

## 🏷 Category

Greedy  
Heap / Priority Queue  
Optimal Merge Pattern  

---

## 📘 Related Problems

• Minimum Cost to Connect Sticks (LeetCode 1167)  
• Huffman Coding  
• Merge K Sorted Lists  
• File Merge Problems  

---

This problem is a classic interview question and frequently asked in coding rounds and competitive programming.

Consistency in recognizing such patterns strengthens problem-solving intuition.
