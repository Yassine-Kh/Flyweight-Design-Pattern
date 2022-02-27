//
// Created by yassine on 12/02/2022.
//

#ifndef FLYWEIGHT_FOREST_H
#define FLYWEIGHT_FOREST_H

#include "Tree.h"
#include "TreeFactory.h"

/*
 * Class Forest used to plant trees, retrieve the one already planted and store instance of Tree.
 */
class Forest {
public:
    std::vector<Tree> trees;  // Vector used to store all instances of Tree in a forest

    Forest();

    ~Forest();

    // used to insert a new instance of Tree in trees
    void insert(int x, int y, const std::string &type);

    // Function used to plant a new tree with its intrinsic and extrinsic states
    void plant(int x, int y, int color[3], const std::string &type, int h, int w) {
        TreeFactory::get()->getTreeType(color, type, h, w);
        this->insert(x, y, type);
    };

    // Retrieving the vector trees
    std::vector<Tree> get_allTrees() const;

    // Printing the characteristics of the tree located at x and y
    void getTree(int x, int y);
};


#endif //FLYWEIGHT_FOREST_H
