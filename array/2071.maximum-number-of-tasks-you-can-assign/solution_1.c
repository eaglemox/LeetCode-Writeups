/*
 * @lc app=leetcode id=2071 lang=c
 *
 * [2071] Maximum Number of Tasks You Can Assign
 */

// @lc code=start
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* a, const void* b) {
    return  *(int*)a - *(int*)b;
}

bool isValid(int* tasks, int tasksSize, int* workers, int workersSize, int k, int pills, int strength) {
    static int q[50000];
    int front = 0, back = 0, j = 0;
    // Check if k tasks can be completed
    for (int i = workersSize - k; i < workersSize; i++) {
        int maxStrength = workers[i] + strength;
        while (j < tasksSize && tasks[j] <= maxStrength) {
            q[back++] = tasks[j++];
        }
        if (front == back) // no tasks can be assigned
            return false;

        if (q[front] <= workers[i]) { // assign easiest task to current worker
            front++;
        } else {
            if (pills-- == 0) { // no more pills
                return false;
            }
            back--;
        }
    }
    return true;
}

int maxTaskAssign(int* tasks, int tasksSize, int* workers, int workersSize, int pills, int strength) {
    // ref: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/solutions/6703654/64ms-14mb-pure-c-alternative-queue-based-sliding-window/?envType=daily-question&envId=2025-05-01
    // Sort tasks and workers array and check k easiest tasks can be assigned 
    // to k strongest 
    qsort(tasks, tasksSize, sizeof(int), cmp);
    qsort(workers, workersSize, sizeof(int), cmp);

    // Binary search
    int left = 0, right = tasksSize < workersSize ? tasksSize : workersSize;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (isValid(tasks, tasksSize, workers, workersSize, mid, pills, strength)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
// @lc code=end

