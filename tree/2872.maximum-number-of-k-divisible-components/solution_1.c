/*
 * @lc app=leetcode id=2872 lang=c
 *
 * [2872] Maximum Number of K-Divisible Components
 */

// @lc code=start
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vector {
    int *data;
    int size;
    int capacity;
} Vector;

void vectorPush(Vector* v, int val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = val;
}

int dfs(Vector* v, int current, int parent, int* values, int* components, int k) {
    int sum = 0;
    for (int i = 0; i < v[current].size; i++) {
        int child = v[current].data[i];
        if (child == parent) {continue;}
        sum += dfs(v, child, current, values, components, k);
    }
    sum += values[current];
    sum %= k;
    if (sum == 0) {
        (*components)++;
    }
    return sum;
}

int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k) {
    // Form the tree (not necessary binary) with edges then perform 
    // DFS split leaf branches if divisible by k
    // Time: O(N), Space: O(N*E)
    // Initiate tree nodes
    Vector *nodes = malloc(n * sizeof(Vector));
    for (int i = 0; i < n; i++) {
        nodes[i].size = 0;
        nodes[i].capacity = 2;
        nodes[i].data = malloc(nodes[i].capacity * sizeof(int));
    }
    // Assign edges for each node ("un"directional)
    for (int i = 0; i < edgesSize; i++) {
        int outNode = edges[i][0], inNode = edges[i][1];
        vectorPush(&nodes[outNode], inNode);
        vectorPush(&nodes[inNode], outNode);
    }
    int result = 0;
    dfs(nodes, 0, -1, values, &result, k);
    return result;
}
// @lc code=end

