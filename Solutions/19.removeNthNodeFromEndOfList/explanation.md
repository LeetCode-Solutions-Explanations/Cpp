The **Remove Nth Node From End of List** problem requires removing a node from a linked list, counting from the end rather than the beginning. The solution should modify the list in place and work in a single pass.

### Problem Breakdown

Given the head of a linked list and an integer \(n\), we want to remove the \(n\)th node from the end of the list. We should return the head of the modified list.

### Key Concept: Two-Pointer Technique

1. **Two Pointers with a Gap**:

   - We use two pointers (`first` and `second`) that are initially at a dummy node preceding the head. The dummy node is a convenient placeholder, especially for edge cases (like when the head needs to be removed).
   - First, we advance the `first` pointer \(n + 1\) steps ahead, creating a gap of \(n\) nodes between `first` and `second`.

2. **Moving Together**:

   - We move both pointers forward simultaneously until the `first` pointer reaches the end of the list.
   - At this point, `second` will be just before the \(n\)th node from the end of the list, allowing us to bypass that node by adjusting the `next` pointer.

3. **Edge Cases**:
   - When the list has only one node, removing that node will return an empty list.
   - When \(n\) equals the length of the list, the head node itself needs to be removed.

### Detailed Solution

Here’s the C++ code that implements this solution efficiently with one pass through the list.

```cpp
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Step 1: Move the first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Step 2: Move both pointers until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Step 3: Remove the nth node from the end
        second->next = second->next->next;

        // Return the new head (skipping dummy node)
        ListNode* newHead = dummy->next;
        delete dummy; // Free the memory of dummy node
        return newHead;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    // Creating the list: [1, 2, 3, 4, 5]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    Solution solution;
    ListNode* modifiedHead = solution.removeNthFromEnd(head, n);

    // Print the modified list
    printList(modifiedHead);

    return 0;
}
```

### Code Explanation

1. **Dummy Node**:

   - We create a dummy node before the `head`, which helps simplify handling cases where the head node is removed.

2. **Two Pointers (`first` and `second`)**:

   - The `first` pointer advances \(n + 1\) steps from `dummy` to create a gap of \(n\) nodes between `first` and `second`.
   - Both pointers then advance together until `first` reaches the end of the list. At this point, `second` points to the node just before the one that needs to be removed.

3. **Removal**:

   - By updating `second->next` to skip the target node, we remove the \(n\)th node from the end of the list.

4. **Return the Result**:
   - The modified list is returned, starting from `dummy->next`, since `dummy` is just a placeholder.

### Complexity Analysis

- **Time Complexity**: \(O(\text{sz})\), where \(\text{sz}\) is the size of the list, since we only traverse the list once.
- **Space Complexity**: \(O(1)\), since we use a constant amount of extra space.

### Edge Cases

- Removing the head node: If \(n\) equals the length of the list, this algorithm correctly handles removing the head by using the dummy node.
- Single-node list: When the list has only one node and \(n = 1\), the algorithm returns `nullptr`, representing an empty list.

### Conclusion

This solution efficiently removes the \(n\)th node from the end of a linked list in a single pass, using the two-pointer technique to avoid unnecessary traversal and handle edge cases.
