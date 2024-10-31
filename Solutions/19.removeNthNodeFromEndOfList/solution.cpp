#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = dummy;
        ListNode *second = dummy;

        // Move first pointer n+1 steps ahead to create a gap of n
        for (int i = 0; i <= n; ++i)
        {
            first = first->next;
        }

        // Move both pointers until first reaches the end
        while (first != nullptr)
        {
            first = first->next;
            second = second->next;
        }

        // Skip the nth node from the end
        second->next = second->next->next;

        // Return the head of the modified list
        return dummy->next;
    }
};

// Helper function to print the list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Example usage
int main()
{
    // Creating the list: [1, 2, 3, 4, 5]
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    Solution solution;
    ListNode *modifiedHead = solution.removeNthFromEnd(head, n);

    // Print the modified list
    printList(modifiedHead);

    return 0;
}
