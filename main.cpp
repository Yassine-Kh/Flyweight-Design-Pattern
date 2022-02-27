#include <iostream>
#include "Forest.h"
#include "NoFlyweightForest.h"

int main() {
    // Creation of the first Forest
    auto *forest = new Forest();

    // Planting trees of type sapin
    for (int i = 0; i < 200; i++) {
        int color[3] = {0, 0, 0};
        forest->plant(i, i, color, "sapin", 10, 10);
        if (i % 50 == 0) {
            forest->getTree(i, i);
        }
    }

    // Planting trees of type erable
    for (int i = 200; i < 300; i++) {
        int color[3] = {200, 200, 200};
        forest->plant(i, i, color, "erable", 20, 20);
        if (i % 50 == 0) {
            forest->getTree(i, i);
        }
    }

    // Planting trees of type saperable
    for (int i = 300; i < 400; i++) {
        int color[3] = {i, i, i};
        forest->plant(i, i, color, "saperable", 30, 30);
        if (i % 50 == 0) {
            forest->getTree(i, i);
        }
    }
    auto trees = forest->get_allTrees();
    auto sharedTrees = &TreeFactory::get()->getSharedTrees();

    // Creation of the second Forest
    auto *forest2 = new Forest();

    // Planting trees of type sapin2
    for (int i = 0; i < 100; i++) {
        int color[3] = {i, i, i};
        forest2->plant(i, i, color, "sapin2", 100, 100);
        if (i % 50 == 0) {
            forest2->getTree(i, i);
        }
    }

    // Planting trees of type erable2
    for (int i = 100; i < 150; i++) {
        int color[3] = {i, i, i};
        forest2->plant(i, i, color, "erable2", 200, 200);
        if (i % 50 == 0) {
            forest2->getTree(i, i);
        }
    }

    // Planting trees of type saperable2
    for (int i = 150; i < 200; i++) {
        int color[3] = {i, i, i};
        forest2->plant(i, i, color, "saperable2", 300, 300);
        if (i % 50 == 0) {
            forest2->getTree(i, i);
        }
    }
    auto trees2 = forest->get_allTrees();
    auto sharedTrees2 = &TreeFactory::get()->getSharedTrees();

    //sharedTrees->erase(sharedTrees->begin());

    // size of all our data if we use the flyweight design pattern for 200 trees
    int size_data_with_flyweight = trees.size()*sizeof(trees[0]) + sharedTrees->size()*sizeof(sharedTrees[0]);


//////////////////////////// Comparison with a non-flyweight design pattern ////////////////////////////

    std::cout << " Now we will plant trees in a forest without the flyweight design pattern " << std::endl;
    auto *nonFlyweightForest = new NoFlyweightForest();

    // Planting trees of type sapin
    for (int i = 0; i < 200; i++) {
        int color[3] = {i, i, i};
        nonFlyweightForest->plant(i, i, color, "sapin", 10, 10);
        if (i % 50 == 0) {
            nonFlyweightForest->getTree(i, i);
        }
    }

    // Planting trees of type erable
    for (int i = 200; i < 300; i++) {
        int color[3] = {i, i, i};
        nonFlyweightForest->plant(i, i, color, "erable", 20, 20);
        if (i % 50 == 0) {
            nonFlyweightForest->getTree(i, i);
        }
    }

    // Planting trees of type saperable
    for (int i = 300; i < 400; i++) {
        int color[3] = {i, i, i};
        nonFlyweightForest->plant(i, i, color, "saperable", 30, 30);
        if (i % 50 == 0) {
            nonFlyweightForest->getTree(i, i);
        }
    }
    auto noFlyweightTrees = nonFlyweightForest->get_allTrees();
    int size_data_without_flyweight = noFlyweightTrees.size()*sizeof(noFlyweightTrees[0]);

    std::cout << "\n We can see that the size of data in bytes with flyweight: " << size_data_with_flyweight << \
    " is clearly a lot smaller than without flyweight: " << size_data_without_flyweight << std::endl;
    return 0;
}
