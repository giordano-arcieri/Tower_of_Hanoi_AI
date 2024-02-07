#include <iostream>
#include "../include/HanoiTowers.hpp" // Assuming HanoiTower class is defined in HanoiTower.h

const int NUMBER_OF_DISKS = 15;

int main()
{
    HanoiTowers tower(NUMBER_OF_DISKS); // Instantiate a new HanoiTower object
    
    std::cout << "This is the inital tower:\n" << tower << std::endl; // Print the HanoiTower object

    std::cin.get();

    tower.solve(); // Solve the HanoiTower problem


    return 0;
}
