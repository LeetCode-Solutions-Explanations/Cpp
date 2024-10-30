# Add Two Numbers Problem in C++

## Problem Description

In the **Add Two Numbers** problem, we are given two non-empty linked lists representing two non-negative integers. Each node in the list contains a single digit, and the digits are stored in **reverse order** (so the 1's digit is at the head of the list). Our task is to add the two numbers and return the result as a linked list.

### Example

Suppose we have two linked lists:

- `l1 = [2 -> 4 -> 3]` (representing 342)
- `l2 = [5 -> 6 -> 4]` (representing 465)

The expected result is `7 -> 0 -> 8`, representing the sum 807.

---

## Key Concepts

### 1. **Using Linked Lists to Represent Numbers**

Each list represents a number in reverse order:

- The **head** of the list has the **least significant digit** (1's place).
- This reverse order simplifies addition because we can start adding digits from the 1's place, just like how you do in manual addition.

### 2. **Managing Carry in Addition**

When adding two digits, we may end up with a sum greater than 9. If this happens:

- We keep the last digit as the current node's value.
- We carry over the remaining value to the next node.

For example:

- Adding `5 + 7` gives `12`. We set the current node to `2` and carry `1` to the next node.

### 3. **Using a Dummy Node**

To simplify list management, we use a **dummy node**. This dummy node helps in building the result linked list without worrying about special cases for the head node. At the end, we simply return the next node of this dummy as our result.

---

## Step-by-Step Solution

Here's the solution code explained in steps:

### Code

```cpp
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);  // Dummy node to simplify list operations
        ListNode* current = dummy;          // Pointer to build the result list
        int carry = 0;                      // Carry to manage sums greater than 9

        // Process each node in the lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;                 // Start with carry from the last addition

            if (l1 != nullptr) {             // Add l1's value if it exists
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {             // Add l2's value if it exists
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;                // Update carry
            current->next = new ListNode(sum % 10);  // Set the current digit
            current = current->next;         // Move to the next node
        }

        return dummy->next;                  // Return result, skipping the dummy node
    }
};
```

````

### Explanation

1. **Initialize Dummy Node**:

   - `ListNode* dummy = new ListNode(0);` creates a dummy node that helps us easily build the linked list.
   - `ListNode* current = dummy;` is used to move through the result list as we add nodes.

2. **Loop through Lists with Carry**:

   - `while (l1 != nullptr || l2 != nullptr || carry != 0)` ensures we keep adding until there are no more nodes in either list and no carry left.

3. **Calculate Sum**:

   - We start with `carry` from the previous addition.
   - If `l1` has a node, we add its value to `sum` and move `l1` to the next node.
   - Similarly, if `l2` has a node, we add its value to `sum` and move `l2` to the next node.

4. **Update Carry and Current Node**:

   - `carry = sum / 10;` updates carry (it’s 1 if `sum` is 10 or more, otherwise 0).
   - `current->next = new ListNode(sum % 10);` sets the node to the last digit of the sum.
   - We then move `current` to `current->next` to prepare for the next node.

5. **Return the Result**:
   - We return `dummy->next`, skipping the dummy node which was just a helper.

---

## Complexity Analysis

- **Time Complexity**: **O(max(m, n))**, where `m` and `n` are the lengths of `l1` and `l2`. We process each node in the lists only once.
- **Space Complexity**: **O(max(m, n))**, for storing the result in the new list.

---

## Summary

This approach efficiently adds two numbers represented by linked lists:

- We manage carryover for sums greater than 9.
- Using a dummy node helps simplify the list creation.
- The algorithm handles different lengths of input lists and produces the correct result in reverse order.

```

````
