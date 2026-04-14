# 🔍 876. Middle of the Linked List

## 📌 Problem Statement

Given the `head` of a **singly linked list**, return the **middle node** of the linked list.

👉 If there are **two middle nodes**, return the **second middle node**.

---

## 🧠 Intuition

To efficiently find the middle node, we use the **two-pointer (slow & fast) technique**:

* `slow` pointer moves **1 step at a time**
* `fast` pointer moves **2 steps at a time**

👉 When `fast` reaches the end, `slow` will be at the middle.

---

## ⚙️ Approach

1. Initialize two pointers: `slow` and `fast` at `head`.
2. Traverse the list:

   * Move `slow` by 1 step.
   * Move `fast` by 2 steps.
3. When `fast` becomes `NULL` or `fast->next` becomes `NULL`, stop.
4. Return `slow`.

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

---

## 🔍 Example

### Input:

```
1 -> 2 -> 3 -> 4 -> 5
```

### Output:

```
3 -> 4 -> 5
```

---

### Input:

```
1 -> 2 -> 3 -> 4 -> 5 -> 6
```

### Output:

```
4 -> 5 -> 6
```

---

## 🚫 Edge Cases

* Single node → return that node.
* Two nodes → return the second node.
* Empty list (if allowed) → return `NULL`.

---

## 💡 Key Takeaway

> The fast & slow pointer technique is a powerful pattern for linked list problems like cycle detection, finding middle, and more.

---

## 🏷️ Tags

* Linked List
* Two Pointers
* Fast & Slow Pointer

---

## 🔗 Problem Link

* https://leetcode.com/problems/middle-of-the-linked-list/

---
