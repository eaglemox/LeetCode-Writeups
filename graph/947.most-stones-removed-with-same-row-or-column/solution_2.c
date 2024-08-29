/*
 * @lc app=leetcode id=947 lang=c
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
typedef struct {
    int *parent;
    int *rank;
} UnionFind;
UnionFind* createUnionFind(int size) {
    UnionFind *uf = (UnionFind *)calloc(1, sizeof(UnionFind));
    uf->parent = (int *)malloc(size * sizeof(int));
    uf->rank = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        uf->parent[i] = i; // self
        uf->rank[i] = 0;
    }
    return uf;
}
int find(UnionFind *uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]);
    }
    return uf->parent[x];
}
void unionByRank(UnionFind *uf, int x, int y) {
    // find their roots
    int rootX = find(uf, x);
    int rootY = find(uf, y);
    if (rootX == rootY) {return;}
    if (uf->rank[rootX] < uf->rank[rootY]) {
        uf->parent[rootY] = rootX;
    }
    else if (uf->rank[rootX] > uf->rank[rootY]) {
        uf->parent[rootX] = rootY;
    }
    else { // same rank
        uf->parent[rootY] = rootX;
        uf->rank[rootX]++; // y to x, rank of x increase
    }
}
void freeUnionFind(UnionFind *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}
int removeStones(int **stones, int stonesSize, int *stonesColSize) {
    /*  if the stones are connect by N connected components,
        stones can be removed until N stones are left.
        removable = stones - N
    */
    int indexSize = 20002;
    int component = 0;
    int *visited = (int *)calloc(indexSize, sizeof(int));
    UnionFind *uf = createUnionFind(indexSize);
    // to unionset
    for (int i = 0; i < stonesSize; i++) {
        int row = stones[i][0];
        int col = stones[i][1] + 10001;
        unionByRank(uf, row, col);
    }
    for (int i = 0; i < stonesSize; i++) {
            int root = find(uf, stones[i][0]);
            if (!visited[root]){
                visited[root] = 1;
                component++;
            }
        }
    free(visited);
    freeUnionFind(uf);
    
    return stonesSize - component;
}
// @lc code=end
