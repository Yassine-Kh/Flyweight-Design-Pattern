//
// Created by yassine on 11/02/2022.
//

#include "TreeFactory.h"

TreeFactory *TreeFactory::sharedFlyweight = nullptr;  // Instantiating the Pointer to the singleton

void TreeFactory::insert(int color[3], const std::string &type, int h, int w) {
    TreeType flyweight_element = TreeFactory::TreeType(color, type, h, w);
    if (find(sharedTrees.begin(), sharedTrees.end(), flyweight_element) == sharedTrees.end()) {
        (TreeFactory::get()->sharedTrees).push_back(flyweight_element);
    }
}


TreeFactory::TreeType TreeFactory::getTreeType(int color[3], const std::string &type, int h, int w) {
    TreeType flyweight_element = TreeFactory::TreeType(color, type, h, w);
    if (find(sharedTrees.begin(), sharedTrees.end(), flyweight_element) != sharedTrees.end()) {
        return flyweight_element;
    } else {
        std::cout << "your sharedTrees is not present in our database. I will create it for you" << std::endl;
        TreeFactory::insert(color, type, h, w);
        return flyweight_element;
    }
}


TreeFactory::TreeType TreeFactory::getTreeType(const std::string &type) {
    for (auto &x: sharedTrees) {
        if (x.get_type() == type) {
            return x;
        }
    }
    std::cout << " There is no match for this type" << std::endl;
    return sharedTrees[0];
}


TreeFactory::TreeType &TreeFactory::TreeType::operator=(const TreeType &t) {
    // protection against auto-assignment
    if (this == &t)
        return *this;
    std::memcpy(this->color, t.get_color(), 3 * sizeof(int));
    type = t.get_type();
    width = t.get_width();
    height = t.get_height();
    return *this;
}

bool TreeFactory::TreeType::operator==(const TreeFactory::TreeType &p1) const {
    if (this->get_type() == p1.get_type()) {
        return true;
    } else {
        return false;
    }
};
