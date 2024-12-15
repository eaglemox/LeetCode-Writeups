/*
 * @lc app=leetcode id=1792 lang=c
 *
 * [1792] Maximum Average Pass Ratio
 */

// @lc code=start
#include <stdlib.h>

typedef struct Class {
    int pass;
    int total;
    double ratioChange;
} Class;

void heapify(Class* arr, int len, int idx) {
    int largest = idx, left = (idx << 1) + 1, right = left + 1;

    if (left < len && arr[left].ratioChange > arr[largest].ratioChange) {
        largest = left;
    }
    if (right < len && arr[right].ratioChange > arr[largest].ratioChange) {
        largest = right;
    }
    if (largest != idx) {
        Class temp = arr[idx];
        arr[idx] = arr[largest];
        arr[largest] = temp;
        heapify(arr, len, largest);
    }
}

void heapifyArray(Class* arr, int len) {
    for (int i = len / 2; i >= 0; i--) {
        heapify(arr, len, i);
    }
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    // Create a struct to track the pass ratio improvement, then heapify the struct list to maintain the maxHeap
    // Time: O(klogN), Space: O(N), N: classesSize, k: extraStudents
    Class *classInfo = malloc(classesSize * sizeof(Class));
    double result = 0;
    for (int i = 0; i < classesSize; i++) {
        double pass = classes[i][0], total = classes[i][1];
        classInfo[i].pass = pass;
        classInfo[i].total = total;
        classInfo[i].ratioChange = (total - pass) / (total * (total + 1));
        result += pass / total;
    }
    heapifyArray(classInfo, classesSize);

    while (extraStudents--) {
        // find class whose pass ratio improve the most if add one pass student
        result += classInfo[0].ratioChange;
        // Increment then cast to double for computation
        double pass = ++classInfo[0].pass, total = ++classInfo[0].total;
        classInfo[0].ratioChange = (total - pass) / (total * (total + 1));
        heapify(classInfo, classesSize, 0);
    }
    result /= classesSize;
    return result;
}
// @lc code=end

