/*
 * @lc app=leetcode id=874 lang=c
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    int coordinate[2] = {0};
    int maxDistance = 0;
    int direction = 0; // 0: N, 1: E, 2: S, 3: W
    for (int i = 0; i < commandsSize; i++) {
        // printf("command: %d, direction: %d, coordinate: (%d, %d)\n", commands[i], direction, coordinate[0], coordinate[1]);
        // printf("maximum L2-distance: %d\n", maxDistance);
        switch (commands[i]) {
            case -1:
                direction = (direction + 1) % 4;
                break;
            case -2:
                direction = (direction + 3) % 4;
                break;
            default: // 1~9
                int cmdVector = (direction < 2) ? commands[i] : -commands[i];
                int maxDisplacement = cmdVector; // maximum displacement <= commands
                int temp;
                for (int j = 0; j < obstaclesSize; j++) {
                    // printf("obstacle: (%d, %d)\n", obstacles[j][0], obstacles[j][1]);
                    if (direction % 2 == 0) { // N-S
                        temp = cmdVector;
                        if (obstacles[j][0] == coordinate[0] && obstacles[j][1] != coordinate[1]) { 
                            int obsVector = obstacles[j][1] - coordinate[1];
                            if (obsVector * cmdVector >= 0 && abs(cmdVector) >= abs(obsVector)) { // same direction 
                                temp = (cmdVector >= 0) ? obstacles[j][1] - 1 : obstacles[j][1] + 1;
                                temp -= coordinate[1];
                            }
                        }
                    } else { // E-W
                        temp = cmdVector;
                        if (obstacles[j][1] == coordinate[1] && obstacles[j][0] != coordinate[0]) {
                            int obsVector = obstacles[j][0] - coordinate[0];
                            if (obsVector * cmdVector >= 0 && abs(cmdVector) >= abs(obsVector)) { // same direction 
                                temp = (cmdVector >= 0) ? obstacles[j][0] - 1 : obstacles[j][0] + 1;
                                temp -= coordinate[0];
                            } 
                        }
                    }
                    // printf("displacement: %d\n", maxDisplacement);
                    maxDisplacement = (abs(temp) <= abs(maxDisplacement)) ? temp : maxDisplacement;
                }
                if (direction % 2 == 0) {
                    coordinate[1] += maxDisplacement;
                } else {
                    coordinate[0] += maxDisplacement;
                }
                break;
        }
        // printf("result coord.: (%d, %d)\n", coordinate[0], coordinate[1]);
        int currentDistance = coordinate[0] * coordinate[0] + coordinate[1] * coordinate[1];
        maxDistance = (maxDistance <= currentDistance) ? currentDistance : maxDistance;
    }
    return maxDistance; 
}
// @lc code=end

