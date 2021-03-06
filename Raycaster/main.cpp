#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <bitset>
#include <stdlib.h>
#include <thread>
#include "Raycaster.hpp"
#include "global.hpp"

int worldMap[mapHeight][mapWidth] = {
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,3,3,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,3,3,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,4,4,4,4,0,4,4,4,4,4,4,4,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {4,4,4,4,4,0,4,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {4,4,4,4,4,0,0,0,4,4,4,4,4,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}
};

int emptyMap[mapHeight][mapWidth] = {
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}
};

bool fullscreen = false;

//Starts up SDL and creates window
bool init();

//Loads music and sound effects
bool loadMusic();

//Frees media and shuts down SDL
void close();

void main_menu();

void game_loop();

void update_screen();

void clear_screen();

void animate_gun();

void drawDogs(Player *player);

//The window we'll be rendering to
SDL_Window* window = NULL;

//The window renderer
SDL_Renderer* renderer = NULL;

SDL_Texture* texture = NULL;

Player player = Player();

Raycaster raycaster = Raycaster(pixels, &player);

Vector2d hitscan;

bool trapMouse = true;

double t = 0;
double lastTime = 0;
double frameTime = 0;
int fps = 0;

int gunSprite = 0;
int shootTime = 0;
bool shooting = false;

double movementSpeed = 5;
double actualSpeed = movementSpeed;
bool forward = false;
bool backward = false;
bool right = false;
bool left = false;
bool sprint = false;

//Main loop flag
bool quit = false;

int chosenWall = 1;

int numberOfDogs = 0;

//Event handler
SDL_Event e;

SDL_Rect textureRenderSize;

struct Dog {
    double x;
    double y;
    int activeTexture = 0;
    long textureSwapTime = 0;
    long textureSwapDelta = 200;
    bool shot = false;
};

std::vector<Dog> dogs = {};

//The music that will be played
Mix_Music *gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gunSound = NULL;
Mix_Chunk *dogGrumble = NULL;
Mix_Chunk *dogGrowl = NULL;
Mix_Chunk *dogSnarl = NULL;

bool init() {
    
    textureRenderSize.x = 0;
    textureRenderSize.y = 0;
    textureRenderSize.w = SCREEN_WIDTH * 3;
    textureRenderSize.h = SCREEN_HEIGHT * 3;
    
    //Initialization flag
    bool success = true;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 ) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        //Create window
        window = SDL_CreateWindow( "RAYCASTER", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * 3, SCREEN_HEIGHT * 3 + 60, SDL_WINDOW_SHOWN );
        if (fullscreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
        if( window == NULL ) {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else {
            //Create renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if( renderer == NULL ) {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else {
                //Initialize renderer color
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            }
        }
         //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }
    }
    
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    memset(pixels, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    
    if (!success) printf( "Failed to initialize!\n" );
    return success;
}

void close() {
    delete[] pixels;
    // texture??
    
    //Destroy window
    //SDL_DestroyRenderer( renderer ); // TODO leak?
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;
    
    //Free the music
    Mix_FreeMusic( gMusic );
    gMusic = NULL;
    
    //Quit SDL subsystems
    Mix_Quit();
    SDL_Quit();
}

int main( int argc, char* args[] ) {
    
    //Start up SDL and create window
    if(init()) {
        main_menu();
        for (int i = 0; i < numberOfDogs; i++) {
            Dog d;
            d.x = rand() % 30 + 1;
            d.y = rand() % 90 + 1;
            dogs.push_back(d);
        }
        
        gunSound = Mix_LoadWAV("Assets/Music/gun.wav");
        loadMusic();
        Mix_PlayMusic(gMusic, -1);
        game_loop();
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}

void game_loop() {
    SDL_SetRelativeMouseMode(SDL_bool(trapMouse));
    
    fps = 0;
    
    //While application is running
    bool pause = false;
    while( !quit ) {
        if (!pause) {
            SDL_LockTexture(texture, NULL,(void**) &pixels, &pitch);
            
            raycaster.raycast(&player, activeMap, 1, false, false);
            drawDogs(&player);
            animate_gun();
            pixels[SCREEN_WIDTH * SCREEN_HEIGHT / 2 + SCREEN_WIDTH / 2] = 255 << 8; // reticle
            update_screen();
            
            if (sprint) actualSpeed = movementSpeed * 5;
            else actualSpeed = movementSpeed;
            if (forward) {
                Vector2d newPos = player.pos + player.dir.norm() * actualSpeed * frameTime;
                if ((*activeMap)[(int) newPos.getY()][(int) newPos.getX()] <= 0) player.pos += player.dir.norm() * actualSpeed * frameTime;
                else {
                    Vector2d delta = Vector2d(0, 0);
                    // todo fungerar bara vid vinklar större än 45
                    if ((int) newPos.getX() != (int) player.pos.getX() && abs(player.dir.getY()) > abs(player.dir.getX())) {
                        delta = Vector2d(0, player.dir.norm().getY())  * actualSpeed * frameTime;
                    }
                    else if ((int) newPos.getY() != (int) player.pos.getY()) {
                        delta = Vector2d(player.dir.norm().getX(), 0)  * actualSpeed * frameTime;
                    }
                    newPos = player.pos + delta * 5;
                    if ((*activeMap)[(int) newPos.getY()][(int) newPos.getX()] <= 0) player.pos += delta;
                }
            }
            if (left) {
                Vector2d newPos = player.pos + player.dir.rotate(-3.14159 / 2).norm() * actualSpeed * frameTime * 3;
                if ((*activeMap)[(int) newPos.getY()][(int) newPos.getX()] <= 0) player.pos += player.dir.rotate(-3.14159 / 2).norm() * actualSpeed * frameTime;
            }
            if (backward) {
                Vector2d newPos = player.pos - player.dir.norm() * actualSpeed * frameTime * 3;
                if ((*activeMap)[(int) newPos.getY()][(int) newPos.getX()] <= 0) player.pos -= player.dir.norm() * actualSpeed * frameTime;
            }
            if (right) {
                Vector2d newPos = player.pos + player.dir.rotate(3.14159 / 2).norm() * actualSpeed * frameTime * 3;
                if ((*activeMap)[(int) newPos.getY()][(int) newPos.getX()] <= 0) player.pos += player.dir.rotate(3.14159 / 2).norm() * actualSpeed * frameTime;
            }
        }
        
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            
            else if( e.type == SDL_KEYDOWN ) {
                switch(e.key.keysym.sym) {
                    case SDLK_w: {
                        forward = true;
                        break;
                    }
                    case SDLK_a: {
                        left = true;
                        break;
                    }
                    case SDLK_s: {
                        backward = true;
                        break;
                    }
                    case SDLK_d: {
                        right = true;
                        break;
                    }
                    case SDLK_LSHIFT: {
                        sprint = true;
                        break;
                    }
                    case SDLK_ESCAPE: {
                        if (fullscreen) quit = true; // todo replace true
                        else {
                            pause = !pause;
                            trapMouse = !trapMouse;
                            SDL_SetRelativeMouseMode(SDL_bool(trapMouse));
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
            
            else if( e.type == SDL_KEYUP ) {
                switch(e.key.keysym.sym) {
                    case SDLK_w: {
                        forward = false;
                        break;
                    }
                    case SDLK_a: {
                        left = false;
                        break;
                    }
                    case SDLK_s: {
                        backward = false;
                        break;
                    }
                    case SDLK_d: {
                        right = false;
                        break;
                    }
                    case SDLK_LSHIFT: {
                        sprint = false;
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
            
            else if( e.type == SDL_MOUSEMOTION) {
                int x, y;
                SDL_GetMouseState( &x, &y );
                player.dir.rotateThis(e.motion.xrel / 2000.0);
                player.cam.rotateThis(e.motion.xrel / 2000.0);
                yOffset -= e.motion.yrel / 2;
                if (yOffset > maxYOffset) yOffset = maxYOffset;
                else if (yOffset < -maxYOffset) yOffset = -maxYOffset;
            }
            
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                switch (e.button.button) {
                    case SDL_BUTTON_LEFT:
                        if (!shooting) {
                            hitscan = Vector2d(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
                            gunSprite = 1;
                            shooting = true;
                            shootTime = SDL_GetTicks();
                        }
                        break;
                    case SDL_BUTTON_RIGHT:
                        if (createMode) createWall = chosenWall;
                        else {
                            player.dir = player.dir * 2;
                            viewDistance /= 2;
                            yOffset *= 2;
                        }
                        break;
                    default:
                        break;
                }
                
            }
            
            else if (e.type == SDL_MOUSEBUTTONUP) {
                switch (e.button.button) {
                    case SDL_BUTTON_LEFT:
                        break;
                    case SDL_BUTTON_RIGHT:
                        if (!createMode) {
                            player.dir = player.dir * 0.5;
                            viewDistance *= 2;
                            yOffset /= 2;
                        }
                        break;
                    default:
                        break;
                }
                
            }
            
            else if (e.type == SDL_MOUSEWHEEL) {
                if (++chosenWall > 4) chosenWall = 1;
            }
        }
        
        lastTime = t;
        t = SDL_GetTicks();
        frameTime = (t - lastTime) / 1000.0;
        fps = (int) (1.0 / frameTime);
        std::cout << "FPS: " << fps << std::endl;
    }
}

void animate_gun() {
    Uint32 c;
    if (SDL_GetTicks() > shootTime + 90 && shooting) {
        if (gunSprite++ == 1) Mix_PlayChannel(-1, gunSound, 0);
        shootTime = SDL_GetTicks();
    }
    if (gunSprite > 4) {
        gunSprite = 0;
        shooting = false;
    }
    for (int i = 0; i < 64 * 64; i++) {
        switch (gunSprite) {
            case 0:
                c = pistol_ready[i];
                break;
            case 1:
                hitscan = Vector2d();
                c = pistol_atk1[i];
                break;
            case 2:
                c = pistol_atk2[i];
                break;
            case 3:
                c = pistol_atk3[i];
                break;
            case 4:
                c = pistol_atk4[i];
                break;
            default:
                c = pistol_ready[i];
                break;
        }
        Uint8 c1 = (Uint8) (c >> 8);
        Uint8 c2 = (Uint8) (c >> 4) & 0x0f;
        Uint8 c3 = ((Uint8) (c) << 4);
        c3 = c3 >> 4;
        
        if (gunSprite == 2) {
            c1 = c1 << 4;
            c2 = c2 << 4;
            c3 = c3 << 4;
        } else {
            c1 = c1 << 3;
            c2 = c2 << 3;
            c3 = c3 << 3;
        }
        
        if (c != 0x0908) {
            for (int k = 0; k < 4; k++) {
                pixels[(SCREEN_HEIGHT - 256 + (i / 64) * 4) * SCREEN_WIDTH + (i * 4 + k) % 256 + SCREEN_WIDTH / 2 - 128] = (((Uint32) c3) + (((Uint32) c2) << 8) + (((Uint32) c1) << 16) + (((Uint32) 255) << 24));
                pixels[(SCREEN_HEIGHT - 256 + (i / 64) * 4 + 1) * SCREEN_WIDTH + (i * 4 + k) % 256 + SCREEN_WIDTH / 2 - 128] = (((Uint32) c3) + (((Uint32) c2) << 8) + (((Uint32) c1) << 16) + (((Uint32) 255) << 24));
                pixels[(SCREEN_HEIGHT - 256 + (i / 64) * 4 + 2) * SCREEN_WIDTH + (i * 4 + k) % 256 + SCREEN_WIDTH / 2 - 128] = (((Uint32) c3) + (((Uint32) c2) << 8) + (((Uint32) c1) << 16) + (((Uint32) 255) << 24));
                pixels[(SCREEN_HEIGHT - 256 + (i / 64) * 4 + 3) * SCREEN_WIDTH + (i * 4 + k) % 256 + SCREEN_WIDTH / 2 - 128] = (((Uint32) c3) + (((Uint32) c2) << 8) + (((Uint32) c1) << 16) + (((Uint32) 255) << 24));
            }
        }
    }
}

void drawDogs(Player *player) {
    // bubble sort, closest in the end of the vector, TODO optimize
    if (dogs.size() > 1) {
        bool sorted = false;
        while(!sorted) {
            sorted = true;
            for (int i = 0; i < dogs.size() - 1; i++) {
                if ((dogs[i].x - player -> pos.getX()) * (dogs[i].x - player -> pos.getX()) + (dogs[i].y - player -> pos.getY()) * (dogs[i].y - player -> pos.getY()) <
                    (dogs[i + 1].x - player -> pos.getX()) * (dogs[i + 1].x - player -> pos.getX()) + (dogs[i + 1].y - player -> pos.getY()) * (dogs[i + 1].y - player -> pos.getY())) {
                    std::swap(dogs[i], dogs[i + 1]);
                    sorted = false;
                }
            }
        }
    }
    Vector2d pos = player -> pos;
    Vector2d dir = player -> dir;
    Vector2d cam = player -> cam;
    int lowQuality; // if == 2 then lowQuality, else 1
    for (auto dog = dogs.begin(); dog != dogs.end(); ) {
        //if (rand() % 10000 == 0) Mix_PlayChannel(-1, dogGrowl, 0); random dog sounds
        bool destroyed = false;
        Vector2d dogPos = Vector2d(dog -> x, dog -> y);
        Vector2d newDogPos = dogPos + (pos - dogPos).norm() * 3 * frameTime;
        if ((pos - newDogPos).mag() > 1 && !(dog -> shot)) {
            if ((int) newDogPos.getY() > 0 && (int) newDogPos.getY() < mapHeight && (int) newDogPos.getX() > 0 && (int) newDogPos.getX() < mapWidth && (*activeMap)[(int) newDogPos.getY()][(int) newDogPos.getX()] <= 0) {
                dog -> x = newDogPos.getX();
                dog -> y = newDogPos.getY();
                if (dog -> activeTexture == 0) dog -> activeTexture = 1;
            }
        } else if (!(dog -> shot) && dog -> activeTexture < 9) dog -> activeTexture = 9;
        // relative distance
        Vector2d spriteDistance = Vector2d(dog -> x - pos.getX(), dog -> y - pos.getY());
        
        if (spriteDistance.mag() < 1.5) lowQuality = 2;
        else lowQuality = 1;
        
        double inverseDeterminant = 1.0 / (cam.getX() * dir.getY() - cam.getY() * dir.getX());
        Vector2d transformed = Vector2d(dir.getY() * spriteDistance.getX() - dir.getX() * spriteDistance.getY(), -cam.getY() * spriteDistance.getX() + cam.getX() * spriteDistance.getY());
        transformed *= inverseDeterminant;
        int spriteScreenX = int((SCREEN_WIDTH / 2) * (1 + transformed.getX() / transformed.getY()));
        int spriteHeight = abs(int(SCREEN_HEIGHT / transformed.getY()));
        int drawStartY = SCREEN_HEIGHT / 2 - spriteHeight / 2;
        if (drawStartY < 0) drawStartY = 0;
        int drawEndY = SCREEN_HEIGHT / 2 + spriteHeight / 2;
        if (drawEndY > SCREEN_HEIGHT) drawEndY = SCREEN_HEIGHT;
        int spriteWidth = abs(int(SCREEN_WIDTH / transformed.getY()));
        int drawStartX = spriteScreenX - spriteWidth / 2;
        if (drawStartX < 0) drawStartX = 0;
        int drawEndX = spriteScreenX + spriteWidth / 2;
        if (drawEndX > SCREEN_WIDTH) drawEndX = SCREEN_WIDTH;
        for (int x = drawStartX; x < drawEndX; x+=lowQuality) {
            int texX = int(256 * (x - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;
            if (transformed.getY() > 0 && x > 0 && x < SCREEN_WIDTH && transformed.getY() < zBuffer[x]) {
                for (int y = drawStartY; y < drawEndY; y+=lowQuality) {
                    int d = y * 256 - SCREEN_HEIGHT * 128 + spriteHeight * 128;
                    int texY = ((d * 64) / spriteHeight) / 256;
                    Uint32 c;
                    switch (dog -> activeTexture) {
                        case 0:
                            c = dog_still[texY * 64 + texX];
                            break;
                        case 1:
                            c = dog_running1[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta) {
                                if (++(dog -> activeTexture) > 3) dog -> activeTexture = 1;
                                dog -> textureSwapTime = SDL_GetTicks();
                            }
                            break;
                        case 2:
                            c = dog_running2[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta * 3 / 2) {
                                if (++(dog -> activeTexture) > 3) dog -> activeTexture = 1;
                                dog -> textureSwapTime = SDL_GetTicks();
                            }
                            break;
                        case 3:
                            c = dog_running3[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta) {
                                if (++(dog -> activeTexture) > 3) dog -> activeTexture = 1;
                                dog -> textureSwapTime = SDL_GetTicks();
                            }
                            break;
                        case 4:
                            dog -> shot = true;
                            c = dog_shot1[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta / 2) {
                                dog -> activeTexture++;
                                dog -> textureSwapTime = SDL_GetTicks();
                                Mix_PlayChannel(-1, dogSnarl, 0);
                            }
                            break;
                        case 5:
                            c = dog_shot2[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta / 2) {
                                dog -> activeTexture++;
                                dog -> textureSwapTime = SDL_GetTicks();
                            }
                            break;
                        case 6:
                            c = dog_shot3[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta / 2) {
                                dog -> activeTexture++;
                                dog -> textureSwapTime = SDL_GetTicks();
                            }
                            break;
                        case 7:
                            c = dog_dead[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta * 5) {
                                dog -> activeTexture++;
                            }
                            break;
                        case 8:
                            c = dog_dead[texY * 64 + texX];
                            destroyed = true;
                            break;
                        case 9:
                            c = dog_bite1[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta) {
                                dog -> activeTexture++;
                                dog -> textureSwapTime = SDL_GetTicks();
                                Mix_PlayChannel(-1, dogGrumble, 0);
                            }
                            break;
                        case 10:
                            c = dog_bite2[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta) {
                                dog -> activeTexture++;
                                dog -> textureSwapTime = SDL_GetTicks();
                            }
                            break;
                        case 11:
                            c = dog_bite3[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta) {
                                dog -> activeTexture++;
                                dog -> textureSwapTime = SDL_GetTicks();
                            }
                            break;
                        case 12:
                            c = dog_still[texY * 64 + texX];
                            if (SDL_GetTicks() > dog -> textureSwapTime + dog -> textureSwapDelta * 2) {
                                dog -> activeTexture = 0;
                                dog -> textureSwapTime = SDL_GetTicks();
                            }
                            break;
                        default:
                            c = dog_still[texY * 64 + texX];
                            dog -> activeTexture = 0;
                            break;
                    }
                    if (c != 0x0908) {
                        Uint8 c1 = (Uint8) (c >> 8);
                        Uint8 c2 = (Uint8) (c >> 4) & 0x0f;
                        Uint8 c3 = ((Uint8) (c) << 4);
                        c3 = c3 >> 4;
                        c1 = c1 << 4;
                        c2 = c2 << 4;
                        c3 = c3 << 4;
                        c1 -= c1 * transformed.getY() / (viewDistance + 1);
                        c2 -= c2 * transformed.getY() / (viewDistance + 1);
                        c3 -= c3 * transformed.getY() / (viewDistance + 1);
                        if (abs(y + yOffset - hitscan.getY()) < lowQuality && abs(x - hitscan.getX()) < lowQuality) {
                            dog -> activeTexture = 4;
                        }
                        Uint32 value = (((Uint32) c3) + (((Uint32) c2) << 8) + (((Uint32) c1) << 16) + (((Uint32) 255) << 24));
                        int index = (y + yOffset) * SCREEN_WIDTH + x;
                        if (lowQuality == 2) {
                            if (index >= 0 && index < SCREEN_WIDTH * SCREEN_HEIGHT - 1) {
                                pixels[index] = value;
                                pixels[++index] = value;
                                index += SCREEN_WIDTH;
                                if (index > 0 && index < SCREEN_WIDTH * SCREEN_HEIGHT) {
                                    pixels[index] = value;
                                    pixels[--index] = value;
                                }
                            }
                        } else {
                            if (index >= 0 && index < SCREEN_WIDTH * SCREEN_HEIGHT) {
                                pixels[index] = value;
                            }
                        }
                    }
                }
            }
        }
        if (destroyed) dog = dogs.erase(dog);
        else ++dog;
    }
}

void update_screen() {
    SDL_UnlockTexture(texture);
    clear_screen();
    //SDL_UpdateTexture(texture, NULL, pixels, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderCopy(renderer, texture, NULL, &textureRenderSize);
    SDL_RenderPresent(renderer);
}

void clear_screen() {
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0xFF );
    SDL_RenderClear( renderer );
}

void main_menu() {
    bool menu_done = false;
    while (!menu_done) {
        clear_screen();
        
        SDL_Rect play;
        play.x = SCREEN_WIDTH / 2;
        play.y = SCREEN_HEIGHT / 3;
        play.w = 100;
        play.h = 40;
        SDL_SetRenderDrawColor(renderer, 42, 42, 42, 255);
        SDL_RenderFillRect(renderer, &play);
        
        SDL_Rect create;
        create.x = SCREEN_WIDTH / 2;
        create.y = SCREEN_HEIGHT / 3 + 100;
        create.w = 100;
        create.h = 40;
        SDL_RenderFillRect(renderer, &create);
        
        SDL_RenderPresent(renderer);
        
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
                menu_done = true;
            }
            
            else if( e.type == SDL_KEYDOWN ) {
                switch(e.key.keysym.sym) {
                    case SDLK_w: {
                        break;
                    }
                    case SDLK_a: {
                        left = true;
                        break;
                    }
                    case SDLK_s: {
                        break;
                    }
                    case SDLK_d: {
                        break;
                    }
                    case SDLK_ESCAPE: {
                        if (fullscreen) quit = true;
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
            
            else if( e.type == SDL_KEYUP ) {
                switch(e.key.keysym.sym) {
                    case SDLK_w: {
                        break;
                    }
                    case SDLK_a: {
                        break;
                    }
                    case SDLK_s: {
                        break;
                    }
                    case SDLK_d: {
                        break;
                    }
                    case SDL_SCANCODE_RETURN: {
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
            
            else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) { // todo only left-click
                int x, y;
                SDL_GetMouseState( &x, &y );
                if (x > play.x && x < play.x + play.w && y > play.y && y < play.y + play.h) {
                    activeMap = &worldMap;
                    numberOfDogs = 16;
                    menu_done = true;
                } else if (x > create.x && x < create.x + create.w && y > create.y && y < create.y + create.h) {
                    createMode = true;
                    activeMap = &emptyMap;
                    numberOfDogs = 0;
                    menu_done = true;
                }
            }
        }
    }
}

bool loadMusic() {
    gMusic = Mix_LoadMUS("Assets/Music/evil_temple.wav");
    if( gMusic == NULL ) {
        printf("Failed to load the music file! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }
    gunSound = Mix_LoadWAV("Assets/Music/gun.wav");
    if( gunSound == NULL ) {
        printf( "Failed to load gun sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    dogGrumble = Mix_LoadWAV("Assets/Music/dog-grumble.flac");
    if( dogGrumble == NULL ) {
        printf( "Failed to load gun sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    dogGrowl = Mix_LoadWAV("Assets/Music/dog-growl.flac");
    if( dogGrumble == NULL ) {
        printf( "Failed to load gun sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }dogSnarl = Mix_LoadWAV("Assets/Music/dog-snarl.flac");
    if( dogGrumble == NULL ) {
        printf( "Failed to load gun sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    return true;
}
