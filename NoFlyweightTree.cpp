//
// Created by yassine on 23/02/2022.
//

#include "NoFlyweightTree.h"
#include <iostream>

NoFlyweightTree::NoFlyweightTree(int x, int y, const int color[3], const std::string &type, int height, int width) {
    NoFlyweightTree::x = x;
    NoFlyweightTree::y = y;
    NoFlyweightTree::type = type;
    NoFlyweightTree::color[0] = color[0];
    NoFlyweightTree::color[1] = color[1];
    NoFlyweightTree::color[2] = color[2];
    NoFlyweightTree::height = height;
    NoFlyweightTree::width = width;
}

NoFlyweightTree::~NoFlyweightTree() = default;
