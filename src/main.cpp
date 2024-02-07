#include <iostream>
#include "../include/HanoiTowers.hpp" 
#include "../include/Tree.hpp" 

#define NUMBER_OF_DISKS 5

int main()
{
    HanoiTowers tower(NUMBER_OF_DISKS); // Instantiate a new HanoiTower object
    
    Tree<int> tree;
    auto np = tree.createRoot(0);
    auto np1 = tree.addChild(np, 1);
    tree.addChild(np, 2);
    auto am = tree.addChild(np, 3);
    tree.addChild(am, 7);

    auto np2 = tree.addChild(np1, 4);
    auto n = tree.addChild(np1, 5);
    tree.addChild(n, 4.6);
    tree.addChild(np1, 6);

    tree.printTree();


    return 0;
}
