#include <iostream>
#include <vector>

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode(0);
        ListNode *top = l3;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            top->next = new ListNode(sum % 10);
            top = top->next;
        }

        return l3->next;
    }
};

// Helper function to create a linked list from a vector of integers
ListNode *createLinkedList(const std::vector<int> &values)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int value : values)
    {
        ListNode *newNode = new ListNode(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        tail = newNode;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val;
        if (head->next != nullptr)
            std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;

    // Example 1
    ListNode *l1 = createLinkedList({2, 4, 3});
    ListNode *l2 = createLinkedList({5, 6, 4});
    ListNode *result = solution.addTwoNumbers(l1, l2);
    std::cout << "Output for Example 1: ";
    printLinkedList(result);

    // Example 2
    l1 = createLinkedList({0});
    l2 = createLinkedList({0});
    result = solution.addTwoNumbers(l1, l2);
    std::cout << "Output for Example 2: ";
    printLinkedList(result);

    // Example 3
    l1 = createLinkedList({9, 9, 9, 9, 9, 9, 9});
    l2 = createLinkedList({9, 9, 9, 9});
    result = solution.addTwoNumbers(l1, l2);
    std::cout << "Output for Example 3: ";
    printLinkedList(result);

    return 0;
}
