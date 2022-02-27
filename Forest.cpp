//
// Created by yassine on 12/02/2022.
//

#include "Forest.h"


void Forest::insert(int x, int y, const std::string &type) {

    Tree extrinsicElement = Tree(x, y, type);
    int found = 0;
    for (const auto &tree: trees) {
        if (tree.get_x() == x && tree.get_y() == y) {
            found = 1;
            std::cout << "You already have a tree at this location" << std::endl;
            break;
        }
    }
    if (found == 0) {
        trees.push_back(extrinsicElement);
    }
}

void Forest::getTree(int x, int y) {
    int found = 0;
    for (const auto &tree: trees) {
        if (tree.get_x() == x && tree.get_y() == y) {
            found = 1;
            auto treeType = TreeFactory::get()->getTreeType(tree.get_type());
            std::cout << "The coordinates of the tree are " << x << y << std::endl;
            std::cout << "The type of the tree is: " << tree.get_type() << std::endl;
            std::cout << "color " << treeType.get_color()[0] << treeType.get_color()[1] << treeType.get_color()[2]
                      << " and height: " << treeType.get_height() << " and width: " << treeType.get_width()
                      << std::endl;
            break;
        }
    }
    if (found == 0) {
        std::cout << "This tree does not belong to this Forest" << std::endl;
    }

}

std::vector<Tree> Forest::get_allTrees() const {
    return trees;
}

Forest::~Forest() = default;

Forest::Forest() = default;
