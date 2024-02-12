#include <iostream>
#include "../include/HanoiTowers.hpp"
#define NUMBER_OF_DISKS 8

int main()
{
    HanoiTowers towers(NUMBER_OF_DISKS);

    std::vector<HanoiTowers> solution = towers.solve();

    for (int i = solution.size(); i > 0; i--)
    {
        std::cout << "\nMove " << solution.size() - i << ":\n\n" << solution[i - 1] << "-----------------\n";
    }

    return 0;
}
