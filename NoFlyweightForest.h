//
// Created by yassine on 23/02/2022.
//

#ifndef FLYWEIGHT_NOFLYWEIGHTFOREST_H
#define FLYWEIGHT_NOFLYWEIGHTFOREST_H


#include "NoFlyweightTree.h"
#include <vector>

/*
 * Class NoFlyweightForest used to plant trees, retrieve the one already planted and store instance of NoFlyweightTree
 * without the flyweight design pattern.
 */
class NoFlyweightForest {
public:
    std::vector<NoFlyweightTree> trees;

    NoFlyweightForest();
    ~NoFlyweightForest();

    // Function used to plant a new tree with its intrinsic and extrinsic states
    void plant(int x, int y, int color[3], const std::string &type, int height, int width);

    // Printing the characteristics of the tree located at x and y
    void getTree(int x, int y);

    // Retrieving the vector trees
    std::vector<NoFlyweightTree> get_allTrees() const;
};

#endif //FLYWEIGHT_NOFLYWEIGHTFOREST_H
