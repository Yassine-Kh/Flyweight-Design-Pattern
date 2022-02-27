//
// Created by yassine on 23/02/2022.
//

#ifndef FLYWEIGHT_NOFLYWEIGHTTREE_H
#define FLYWEIGHT_NOFLYWEIGHTTREE_H


#include <iostream>

/*
 * Class NoFlyweightTree used to store the extrinsic state of the trees (the non-common elements) without the
 * flyweight design pattern.
 */
class NoFlyweightTree {
private:
    int x;
    int y;
    int color[3]{};
    std::string type;
    int height;
    int width;

public:
    // Constructor to create new instance of tree
    NoFlyweightTree(int x, int y, const int color[3], const std::string &type, int height, int width);

    ~NoFlyweightTree();

    int get_x() const { return x; };

    int get_y() const { return y; };

    std::string get_type() const { return type; };

    const int *get_color() const { return color; };

    int get_height() const { return height; };

    int get_width() const { return width; };

};


#endif //FLYWEIGHT_NOFLYWEIGHTTREE_H
