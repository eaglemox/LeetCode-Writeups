/*
 * @lc app=leetcode id=874 lang=c
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define HASH_MULTIPLIER 60000
long long hashCoordinate(int x, int y) {return x * HASH_MULTIPLIER + y;}
bool checkObstacle(int x, int y, long long *obstacleSet, int obstaclesSize) {
    long long hCoor = hashCoordinate(x, y);
    for (int i = 0; i < obstaclesSize; i++) {
        if (obstacleSet[i] == hCoor) {return true;}
    }
    return false;
}
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    int coordinate[2] = {0};
    int maxDistance = 0;
    int direction = 0; // 0: N, 1: E, 2: S, 3: W

    long long *obstacleSet = malloc(obstaclesSize * sizeof(long long));
    for (int i = 0; i < obstaclesSize; i++) {
        obstacleSet[i] = hashCoordinate(obstacles[i][0], obstacles[i][1]);
    }
    for (int i = 0; i < commandsSize; i++) {
        switch (commands[i]) {
            case -1:
                direction = (direction + 1) % 4;
                break;
            case -2:
                direction = (direction + 3) % 4;
                break;
            default: // 1~9
                int nextX, nextY;
                for (int j = 0; j < commands[i]; j++) {
                    if (direction % 2 == 0) { // N-S
                        nextX = coordinate[0];
                        nextY = coordinate[1] + ((direction < 2) ? 1 : -1);
                    } else { // E-W
                        nextX = coordinate[0] + ((direction < 2) ? 1 : -1);
                        nextY = coordinate[1];
                    }
                    if (checkObstacle(nextX, nextY, obstacleSet, obstaclesSize)) {
                        printf("blocked by an obstacle!\n");
                        break;
                    } else {
                        coordinate[0] = nextX;
                        coordinate[1] = nextY;
                    }
                }
                printf("current coordinate: (%d, %d)\n", coordinate[0], coordinate[1]);
                break;
        }
        int currentDistance = coordinate[0] * coordinate[0] + coordinate[1] * coordinate[1];
        maxDistance = (maxDistance <= currentDistance) ? currentDistance : maxDistance;
    }
    free(obstacleSet);
    return maxDistance; 
}
// @lc code=end

