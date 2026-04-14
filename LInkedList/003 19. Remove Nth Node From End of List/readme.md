# 🗑️ 19. Remove Nth Node From End of List

## 📌 Problem Statement

Given the `head` of a **singly linked list**, remove the **nth node from the end** of the list and return its head.

---

## 🧠 Intuition

To remove the nth node from the end in **one pass**, we use the **two-pointer (fast & slow) technique**.

👉 Idea:

* Maintain a gap of **n nodes** between `fast` and `slow`.
* When `fast` reaches the end, `slow` will be just **before the node to delete**.

---

## ⚙️ Approach (Using Dummy Node)

1. Create a **dummy node** pointing to `head` (handles edge cases like deleting head).
2. Initialize two pointers: `slow` and `fast` at dummy.
3. Move `fast` **n steps ahead**.
4. Move both `slow` and `fast` together until `fast->next == NULL`.
5. Delete `slow->next`.
6. Return `dummy->next`.

---

## 💻 Code (C++)

```cpp id="z8m3xr"
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n steps ahead
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // Move both pointers
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        // Delete node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummy->next;
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

```id="r8a8yq"
1 -> 2 -> 3 -> 4 -> 5, n = 2
```

### Output:

```id="vkb9l3"
1 -> 2 -> 3 -> 5
```

---

## 🚫 Edge Cases

* Removing the **head node** (when `n == length of list`)
* Single node list
* Two node list

---

## 💡 Key Takeaway

> Using a dummy node simplifies handling edge cases and ensures clean, consistent logic.

---

## 🏷️ Tags

* Linked List
* Two Pointers
* Fast & Slow Pointer

---

## 🔗 Problem Link

* https://leetcode.com/problems/remove-nth-node-from-end-of-list/

---
