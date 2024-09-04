/*
 * @lc app=leetcode id=218 lang=c
 *
 * [218] The Skyline Problem
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int type; // 0: enter, 1: leave
    int x;
    int height;
} Event;
int compareEvent(const void *p, const void *q) {
    // return <= 0: p, q no swap
    // return >  0: q, p
    Event *a = (Event *)p;
    Event *b = (Event *)q;
    if (a->x != b->x) {
        return a->x - b->x;
    } else if (a->type != b->type) {
        return a->type - b->type; // enter first
    }
    return a->height - b->height;
}
int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes) {
    int eventsSize = 2 * buildingsSize;
    *returnSize = 0;
    Event *events = malloc(2 * buildingsSize * sizeof(Event));
    for (int i = 0; i < buildingsSize; i++) {
        events[2*i].type = 0;
        events[2*i].x = buildings[i][0];
        events[2*i].height = buildings[i][2];
        events[2*i+1].type = 1;
        events[2*i+1].x = buildings[i][1];
        events[2*i+1].height = buildings[i][2];
    }
    qsort(events, eventsSize, sizeof(Event), compareEvent);

    // for (int i = 0; i < eventsSize; i++) { // print sorted result
    //     printf("[%d, %d, %d]\n", events[i].x, events[i].height, events[i].type);
    // }
    // allocate return array
    int **skyline = malloc(eventsSize * sizeof(int *));
    for (int i = 0; i < eventsSize; i++) {
        skyline[i] = (int *)malloc(2 * sizeof(int));
    }
    // record entered heights 
    int heightsSize = 0;
    int *heights = malloc(eventsSize * sizeof(int));
    int prevHeight = 0; // previous max height of entered buildings before event
    for (int i = 0; i < eventsSize; i++) {
        if (events[i].type == 0) { // enter
            heights[heightsSize++] = events[i].height;
            int j = i + 1;
            if (j != eventsSize) { // same x enter
                while (events[i].height <= events[j].height && events[j].x == events[i].x && events[j].type == 0) {
                    heights[heightsSize++] = events[j].height;
                    i = j++;
                }
            }
        } else { // leave
            for (int j = 0; j < heightsSize; j++) {
                if (heights[j] == events[i].height) { // remove the leaving building's heights
                    heights[j] = heights[--heightsSize];
                    break;
                }
            }
        }
        int currentHeight = 0; // max height of entered buildings
        for (int j = 0; j < heightsSize; j++) { // find current max height
            if (heightsSize == 0) {
                currentHeight = 0;
                break;
            }
            if (heights[j] >= currentHeight) {
                currentHeight = heights[j];
            } 
        }
        if (currentHeight != prevHeight) {
            skyline[*returnSize][0] = events[i].x;
            skyline[*returnSize][1] = currentHeight;
            (*returnSize)++;
            prevHeight = currentHeight;
        }
    }
    // adjust return size
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    free(events);
    free(heights);
    return skyline;
}
// @lc code=end

