/*
 * @lc app=leetcode id=3341 lang=c
 *
 * [3341] Find Minimum Time to Reach Last Room I
 */

// @lc code=start
#include <stdlib.h>
#include <limits.h>

#define max(a, b) (a > b) ? a : b

typedef struct {
    int time;
    int x, y;
} QNode;

typedef struct {
    QNode *buffer;
    int head, tail, capacity;
} Queue;

Queue* queueCreate(int capacity) {
    Queue *q = malloc(sizeof(Queue));
    q->buffer = malloc(sizeof(QNode) * capacity);
    q->head = q->tail = 0;
    q->capacity = capacity;
    return q;
}

void queuePush(Queue* q, QNode node) {
    if ((q->tail + 1) % q->capacity == q->head) { // reach capacity
        int newCapacity = q->capacity <<= 1;
        q->buffer = realloc(q->buffer, sizeof(QNode) * newCapacity);
        if (q->tail < q->head) { // move circulated segment to new allocate memory 
            memmove(q->buffer + q->capacity, q->buffer, sizeof(QNode) * q->tail);
            q->tail += q->capacity;
        }
        q->capacity = newCapacity;
    } // Append to tail
    q->buffer[q->tail] = node;
    q->tail = (q->tail + 1) % q->capacity;
}

QNode queuePop(Queue* q) {
    QNode head = q->buffer[q->head];
    q->head = (q->head + 1) % q->capacity;
    return head;
}

int queueEmpty(Queue* q) {
    return q->head == q->tail;
}

void queueFree(Queue *q) {
    free(q->buffer);
    free(q);
}

int minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize) {
    int n = moveTimeSize, m = moveTimeColSize[0];
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int **dis = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        dis[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            dis[i][j] = 0x3f3f3f3f; // 10^9
        }
    }

    Queue *q = queueCreate(n * m);
    dis[0][0] = 0; // start room
    queuePush(q, (QNode){.time = 0, .x = 0, .y = 0}); // first node
    while (!queueEmpty(q)) { // dijkstra's algo. (BFS)
        QNode cur = queuePop(q);

        for (int d = 0; d < 4; d++) {
            int newX = cur.x + dir[d][1], newY = cur.y + dir[d][0];
            if (newY >= 0 && newY < n && newX >= 0 && newX < m) {
                // printf("(%d,%d): %d\n", newY, newX, cur.time);
                int minTime = max(cur.time + 1, moveTime[newY][newX] + 1);
                if (minTime < dis[newY][newX]) {
                    dis[newY][newX] = minTime;
                    queuePush(q, (QNode){.time = minTime, .x = newX, .y = newY});
                }
            }
        }
    }
    queueFree(q);
    return dis[n-1][m-1];
}
// @lc code=end

