#include <iostream>
#include "../include/HanoiTowers.hpp" // Assuming HanoiTower class is defined in HanoiTower.h

const int NUMBER_OF_DISKS = 3;

int main()
{
    HanoiTowers tower(NUMBER_OF_DISKS); // Instantiate a new HanoiTower object

    tower.solve(); // Solve the HanoiTower problem

    std::cout << tower << std::endl; // Print the HanoiTower object

    return 0;
}
