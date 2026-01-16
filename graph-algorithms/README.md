# Floyd-Warshall All-Pairs Shortest Path

Implementation of Floyd-Warshall algorithm to find shortest paths between all pairs of vertices in a weighted graph.

## Features
- Reads graph from input file (`testGraph.txt`)
- Computes all-pairs shortest paths
- Displays intermediate matrices at each step
- Identifies central node (node with minimum eccentricity)

## Algorithm
Uses dynamic programming to iteratively improve path estimates:
- Time: O(V³)
- Space: O(V²)

## Input Format
```
4           # Number of nodes
0 1 5       # edge: node0 to node1, weight 5
1 2 3       # edge: node1 to node2, weight 3
...
```

## Compilation & Execution
```bash
gcc floyd-warshall.c -o graph
./graph
```

## Note
Make sure it compiles cleanly
```
bashgcc -Wall -Wextra floyd-warshall.c -o graph
```

## Example Output
Shows progression of shortest path matrix and identifies central node.