/*
 * @lc app=leetcode id=731 lang=c
 *
 * [731] My Calendar II
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)

typedef struct {
    int **booked;
    int **doubleBooked;
    int bookedSize;
    int doubleBookedSize;
} MyCalendarTwo;


MyCalendarTwo* myCalendarTwoCreate() {
    return calloc(1, sizeof(MyCalendarTwo));
}

bool isOverlapped(int* start1, int* end1, int start2, int end2) {
    // start1, end1 are the overlapped interval
    *start1 = max(*start1, start2);
    *end1 = min(*end1, end2);
    return *start1 < *end1;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    for (int i = 0; i < obj->doubleBookedSize; i++) {
        if (isOverlapped(&start, &end, obj->doubleBooked[i][0], obj->doubleBooked[i][1])) {
            return false;
        }
    }
    // Insert book
    if (obj->bookedSize == 0) {
        obj->bookedSize++;
        obj->booked = malloc(sizeof(int *));
    } else {
        obj->bookedSize++;
        int **temp = realloc(obj->booked, obj->bookedSize * sizeof(int *));
        if (temp) {obj->booked = temp;}
    }
    int *date = malloc(2 * sizeof(int));
    date[0] = start, date[1] = end;
    obj->booked[obj->bookedSize-1] = date;
    // Update double booked
    for (int i = 0; i < obj->bookedSize - 1; i++) {
        int doubleStart = obj->booked[obj->bookedSize-1][0], doubleEnd = obj->booked[obj->bookedSize-1][1];
        if (isOverlapped(&doubleStart, &doubleEnd, obj->booked[i][0], obj->booked[i][1])) {
            if (obj->doubleBookedSize == 0) {
                obj->doubleBookedSize++;
                obj->doubleBooked = malloc(sizeof(int *));
            } else {
                obj->doubleBookedSize++;
                int **temp = realloc(obj->doubleBooked, obj->doubleBookedSize * sizeof(int *));
                if (temp) {obj->doubleBooked = temp;}
            }
            int *doubleDate = malloc(2 * sizeof(int));
            doubleDate[0] = doubleStart, doubleDate[1] = doubleEnd;
            obj->doubleBooked[obj->doubleBookedSize-1]= doubleDate;
        }
    }
    // for (int i = 0; i < obj->bookedSize; i++) {
    //     printf("[%d, %d] ", obj->booked[i][0], obj->booked[i][1]);
    // } printf("\ndouble:\n");
    // for (int i = 0; i < obj->doubleBookedSize; i++) {
    //     printf("[%d, %d] ", obj->doubleBooked[i][0], obj->doubleBooked[i][1]);
    // } printf("\n");
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    for (int i = 0; i < obj->bookedSize; i++) {
        free(obj->booked[i]);
    }
    for (int i = 0; i < obj->doubleBookedSize; i++) {
        free(obj->doubleBooked[i]);
    }
    free(obj);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 
 * myCalendarTwoFree(obj);
*/
// @lc code=end

