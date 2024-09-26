/*
 * @lc app=leetcode id=729 lang=c
 *
 * [729] My Calendar I
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* Brute force: check all possible overlaps */

typedef struct {
    int **booked;
    int bookedSize;
} MyCalendar;


MyCalendar* myCalendarCreate() {
    MyCalendar *calendar = calloc(1, sizeof(MyCalendar));
    // calendar->bookedDates = malloc(0 * sizeof(int *));
    // printf("ptr: %d\n", calendar->bookedDates);
    // printf("size: %d\n", calendar->bookedDatesSize);
    return calendar;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    for (int i = 0; i < obj->bookedSize; i++) {
        if (start < obj->booked[i][1] && end > obj->booked[i][0]) {
            return false;
        }
    }
    // print dates
    // for (int i = 0; i < obj->bookedSize; i++) {
    //     printf("[%d, %d] ", obj->booked[i][0], obj->booked[i][1]);
    // }
    // printf("\n");
    int *date = malloc(2 * sizeof(int));
    date[0] = start; date[1] = end;
    if (obj->bookedSize == 0) {
        (obj->bookedSize)++;
        obj->booked = malloc(sizeof(int *));
    } else {
        (obj->bookedSize)++;
        int **temp = realloc(obj->booked, obj->bookedSize * sizeof(int *));
        if (temp) {obj->booked = temp;}
    }
    obj->booked[(obj->bookedSize)-1] = date;
    return true;
}

void myCalendarFree(MyCalendar* obj) {
    for (int i = 0; i < obj->bookedSize; i++) {
        free(obj->booked[i]);
    }
    free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/
// @lc code=end

