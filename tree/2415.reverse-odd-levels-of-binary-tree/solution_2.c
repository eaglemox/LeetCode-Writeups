/*
 * @lc app=leetcode id=2415 lang=c
 *
 * [2415] Reverse Odd Levels of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>

typedef struct Queue {
    int front;
    int rear;
    int size;
    int capacity;
    struct TreeNode **queueArray;
} Queue;

Queue createQueue(int maxSize) {
    Queue queue;
    queue.front = -1;
    queue.rear = -1;
    queue.size = 0;
    queue.capacity = maxSize;
    queue.queueArray = (struct TreeNode **)malloc(maxSize * sizeof(struct TreeNode *));
    return queue;
}

void enqueue(Queue* q, struct TreeNode* node) {
    if (q->rear == q->capacity - 1) {return;}
    q->queueArray[++q->rear] = node;
    q->size++;
    if (q->front == -1) {
        q->front = 0;
    }
}

struct TreeNode* dequeue(Queue* q) {
    if (q->front == -1) {return NULL;}
    struct TreeNode *ret_val = q->queueArray[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
        q->size = 0;
    } else {
        q->front++;
        q->size--;
    }
    return ret_val;
}

void printQueue(Queue* q) {
    printf("front: %d, rear: %d, size: %d\n", q->front, q->rear, q->size);
    for (int i = q->front; i != q->rear; i++) {
        printf("%d ", q->queueArray[i]->val);
    }
    printf("\n");
}

int countNode(struct TreeNode* root) {
    if (!root) {return 0;}
    return countNode(root->left) + countNode(root->right) + 1;
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    // BFS implemented with queue
    // Time: O(logN), Space: O(N)
    int numNodes = countNode(root);
    Queue q = createQueue(numNodes);
    enqueue(&q, root);
    int depth = 0;
    while (q.front != -1) { // not empty
        // swap value of each pair
        if (depth % 2) {
            for (int idx = 0; idx < q.size / 2; idx++) {
                int l = q.front + idx, r = q.rear - idx;
                int temp = q.queueArray[l]->val;
                q.queueArray[l]->val = q.queueArray[r]->val;
                q.queueArray[r]->val = temp;
            }
        }
        int levelSize = q.size;
        while (levelSize--) {
            struct TreeNode *frontNode = dequeue(&q);
            if (frontNode->left) {
                enqueue(&q, frontNode->left);
            }
            if (frontNode->right) {
                enqueue(&q, frontNode->right);
            }
        }
        depth++;
    }
    return root;
}
// @lc code=end

