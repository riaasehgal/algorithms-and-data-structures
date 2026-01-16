# Binary Search Tree Implementation

Classic BST data structure with insertion, search, and traversal operations.

## Features
- Insert nodes maintaining BST property
- Search for specific values
- In-order traversal (outputs sorted sequence)
- File output for tree contents

## Operations
- **Insert**: O(log n) average, O(n) worst case
- **Search**: O(log n) average, O(n) worst case
- **Traversal**: O(n)

## Compilation & Execution
```bash
gcc binary-search-tree.c -o bst
./bst
```

## Output
Creates `output.txt` with sorted node values from in-order traversal.