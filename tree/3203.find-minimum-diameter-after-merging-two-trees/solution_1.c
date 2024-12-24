/*
 * @lc app=leetcode id=3203 lang=c
 *
 * [3203] Find Minimum Diameter After Merging Two Trees
 */

// @lc code=start
#include <stdlib.h>
#include <stdbool.h>
#define max(a, b) ((a > b) ? a : b)
#define MAX_VAL 100000

typedef struct Matrix {
    int rowSize;
    int *colSize;
    int *colCapacity;
    int **data;
} Matrix;

Matrix matrixCreate(int rows) {
    Matrix mat;
    mat.rowSize = rows;
    mat.colSize = malloc(rows * sizeof(int));
    mat.colCapacity = malloc(rows * sizeof(int));
    mat.data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat.colSize[i] = 0;
        mat.colCapacity[i] = 2;
        mat.data[i] = malloc(mat.colCapacity[i] * sizeof(int));
    }
    return mat;
}

void matrixRowPush(Matrix* mat, int row, int val) {
    if (mat->colSize[row] == mat->colCapacity[row]) {
        mat->colCapacity[row] *= 2;
        mat->data[row] = realloc(mat->data[row], mat->colCapacity[row] * sizeof(int));
    }
    mat->data[row][mat->colSize[row]++] = val;
}

void matrixPrint(Matrix* mat) {
    printf("Tree\n");
    for (int i = 0; i < mat->rowSize; i++) {
        printf("%d: ", i);
        for (int j = 0; j < mat->colSize[i]; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

int findFarthestNode(Matrix* adj, int originNode, int* diameter) {
    int front = 0, rear = 0, q[MAX_VAL+1];
    bool visited[MAX_VAL+1] = {false};
    q[rear++] = originNode;
    visited[originNode] = true;
    int farthestNode = originNode;
    *diameter = 0;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            int frontNode = q[front++];
            farthestNode = frontNode;
            // push neighbor nodes to the queue
            for (int j = 0; j < adj->colSize[frontNode]; j++) {
                int neighborNode = adj->data[frontNode][j];
                if (!visited[neighborNode]) {
                    visited[neighborNode] = true;
                    q[rear++] = neighborNode;
                } 
            }
        }
        if (front < rear) {(*diameter)++;}
    }
    return farthestNode;
}

int findDiameter(Matrix* adj) {
    int diameter;
    // Find end node for arbitrary node
    int end1 = findFarthestNode(adj, 0, &diameter);
    // Find the other end node for the tree
    int end2 = findFarthestNode(adj, end1, &diameter);
    return diameter;
}

int minimumDiameterAfterMerge(int** edges1, int edges1Size, int* edges1ColSize, int** edges2, int edges2Size, int* edges2ColSize) {
    // Store adjacent list in 2DArray then BFS to find the end nodes for the diameters
    // Time: O(M+N), Space: O(M+N), M: #nodes of tree1, N: #nodes of tree2
    Matrix adjacentList1 = matrixCreate(edges1Size + 1),
           adjacentList2 = matrixCreate(edges2Size + 1);
    
    for (int i = 0; i < max(edges1Size, edges2Size); i++) {
        if (i < edges1Size) {
            matrixRowPush(&adjacentList1, edges1[i][0], edges1[i][1]);
            matrixRowPush(&adjacentList1, edges1[i][1], edges1[i][0]);
        }
        if (i < edges2Size) {
            matrixRowPush(&adjacentList2, edges2[i][0], edges2[i][1]);
            matrixRowPush(&adjacentList2, edges2[i][1], edges2[i][0]);
        }
    }
    matrixPrint(&adjacentList1);
    matrixPrint(&adjacentList2);

    int diameter1 = findDiameter(&adjacentList1);
    int diameter2 = findDiameter(&adjacentList2);
    int mergedDiameter = (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1;

    return max(diameter1, max(diameter2, mergedDiameter));
}
// @lc code=end

