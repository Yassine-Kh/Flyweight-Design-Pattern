//
// Created by yassine on 22/02/2022.
//

#ifndef FLYWEIGHT_TREE_H
#define FLYWEIGHT_TREE_H

#include "TreeFactory.h"

/*
 * Class Tree used to store the extrinsic state of the trees (the non-common elements)
 */
class Tree {
    int x;    // coordinate x of the tree
    int y;    // coordinate y of the tree
    std::string type;
public:

    // Constructor
    Tree(int x, int y, const std::string &tp) {
        this->x = x;
        this->y = y;
        type = tp;
    };

    ~Tree() = default;

    int get_x() const { return x; };

    int get_y() const { return y; };

    std::string get_type() const { return type; };

    // Assignment operator
    Tree &operator=(const Tree &t);
};


#endif //FLYWEIGHT_TREE_H
