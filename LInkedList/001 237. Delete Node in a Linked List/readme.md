# 🗑️ 237. Delete Node in a Linked List

## 📌 Problem Statement

Given a node in a **singly linked list**, delete that node.
You are **not given access to the head** of the list.

⚠️ Important:

* The given node is **not the last node**.
* All values in the linked list are **unique**.

---

## 🧠 Intuition

Since we don't have access to the previous node, we **cannot delete the node directly** in the usual way.

👉 Trick:

* Copy the value of the **next node** into the current node.
* Then delete the **next node** instead.

This effectively removes the given node from the list.

---

## ⚙️ Approach

1. Copy the value of the next node into the current node.
2. Store the next node in a temporary pointer.
3. Update the current node’s `next` pointer to skip the next node.
4. Delete the temporary node.

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;      // Copy next node's value
        ListNode* temp = node->next;      // Store next node
        node->next = node->next->next;    // Bypass next node
        delete temp;                      // Delete it
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(1)
* **Space Complexity:** O(1)

---

## 🔍 Example

### Input:

```
4 -> 5 -> 1 -> 9
     ↑ (node to delete)
```

### Output:

```
4 -> 1 -> 9
```

---

## 🚫 Edge Cases

* The given node will **never be the last node**, so `node->next` is always valid.
* No need to handle null pointers explicitly.

---

## 💡 Key Takeaway

> When you don’t have access to the previous node, simulate deletion by copying the next node’s data.

---

## 🏷️ Tags

* Linked List
* Data Structures
* Easy

---

## 🔗 Problem Link

* https://leetcode.com/problems/delete-node-in-a-linked-list/

---
