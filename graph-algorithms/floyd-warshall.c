#include <stdio.h>
#include <stdlib.h>

#define INF 999999  

// create and initialize an adjacency matrix
int** createAdjMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (i == j) ? 0 : INF;
        }
    }
    return matrix;
}

// print
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Floyd-Warshall Algorithm
void floydWarshall(int** graph, int n) {
    int** dist = createAdjMatrix(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < n; k++) {
        printf("Intermediate matrix after including node %d:\n", k);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
        printMatrix(dist, n);
    }

    printf("Final All-Pairs Shortest Paths matrix:\n");
    printMatrix(dist, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = dist[i][j];

    for (int i = 0; i < n; i++)
        free(dist[i]);
    free(dist);
}

// find central node
int centralNode(int** dist, int n) {
    int minEccentricity = INF;
    int central = -1;

    for (int i = 0; i < n; i++) {
        int maxDist = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                return -1;
            if (dist[i][j] > maxDist)
                maxDist = dist[i][j];
        }
        if (maxDist < minEccentricity) {
            minEccentricity = maxDist;
            central = i;
        }
    }

    return central;
}

int main() {
    FILE* file = fopen("testGraph.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    int** adjMatrix = createAdjMatrix(n);

    int src, tgt, weight;
    while (fscanf(file, "%d %d %d", &src, &tgt, &weight) == 3) {
        adjMatrix[src][tgt] = weight;
        adjMatrix[tgt][src] = weight; 
    }

    fclose(file);

    printf("Original Adjacency Matrix:\n");
    printMatrix(adjMatrix, n);

    floydWarshall(adjMatrix, n);

    int central = centralNode(adjMatrix, n);
    if (central == -1)
        printf("The graph is not connected. No central node.\n");
    else
        printf("The central node is: %d\n", central);

    for (int i = 0; i < n; i++)
        free(adjMatrix[i]);
    free(adjMatrix);

    return 0;
}

// to run do this in terminal 
// gcc graph.c -o graph
// ./graph
