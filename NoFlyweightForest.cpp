//
// Created by yassine on 23/02/2022.
//

#include "NoFlyweightForest.h"
#include "NoFlyweightTree.h"
#include <iostream>

NoFlyweightForest::~NoFlyweightForest() = default;

NoFlyweightForest::NoFlyweightForest() = default;


void NoFlyweightForest::plant(int x, int y, int *color, const std::string &type, int height, int width) {
    NoFlyweightTree tree = NoFlyweightTree(x, y, color, type, height, width);
    trees.push_back(tree);
}

void NoFlyweightForest::getTree(int x, int y) {
    int found = 0;
    for (const auto &tree: trees) {
        if (tree.get_x() == x && tree.get_y() == y) {
            found = 1;
            std::cout << "The coordinates of the non-flyweight-tree are " << x << y << std::endl;
            std::cout << "The type of the non-flyweight-tree is: " << tree.get_type() << std::endl;
            std::cout << "color " << tree.get_color()[0] << tree.get_color()[1] << tree.get_color()[2]
                      << " and height: " << tree.get_height() << " and width: " << tree.get_width()
                      << std::endl;
            break;
        }
    }
    if (found == 0) {
        std::cout << "This tree does not belong to this Forest" << std::endl;
    }
}

std::vector<NoFlyweightTree> NoFlyweightForest::get_allTrees() const {
    return trees;
}
