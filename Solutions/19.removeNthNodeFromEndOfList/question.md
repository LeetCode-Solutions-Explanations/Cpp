# Remove Nth Node From End of List

**Difficulty**: Medium

### Topics

- Linked List
- Two Pointers

### Hint

Given the head of a linked list, remove the \(n\)th node from the end of the list and return its head.

### Examples

#### Example 1

- **Input**: `head = [1,2,3,4,5]`, `n = 2`
- **Output**: `[1,2,3,5]`

#### Example 2

- **Input**: `head = [1]`, `n = 1`
- **Output**: `[]`

#### Example 3

- **Input**: `head = [1,2]`, `n = 1`
- **Output**: `[1]`

### Constraints

- The number of nodes in the list is `sz`.
- \(1 \leq sz \leq 30\)
- \(0 \leq \text{Node.val} \leq 100\)
- \(1 \leq n \leq sz\)

### Follow Up

Could you do this in one pass?
