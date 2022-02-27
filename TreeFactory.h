//
// Created by yassine on 11/02/2022.
//

#ifndef FLYWEIGHT_TREEFACTORY_H
#define FLYWEIGHT_TREEFACTORY_H

#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

/* The Singleton class TreeFactory is designed
 * to manage the nested class TreeType. It is
 * a singleton class so that all forests created
 * share the same instances of TreeType */
class TreeFactory {
    static TreeFactory *sharedFlyweight;  // Pointer to the singleton

    // private constructor so that no one can create another instance of the class
    TreeFactory() = default;;

    ~TreeFactory() = default;
public:
/*
 * Nested class TreeType used to store the common elements of the trees
 */
    class TreeType {
        int color[3]{};
        std::string type;
        int height;
        int width;
    public:

        // Constructor initializing all attributes
        TreeType(int col[3], const std::string &tp, int h, int w) {
            std::memcpy(color, col, 3 * sizeof(int));
            type = tp;
            height = h;
            width = w;
        };

        std::string get_type() const { return type; };

        const int *get_color() const { return color; };

        int get_height() const { return height; };

        int get_width() const { return width; };

        // Operator == used to compare two instances of TreeType
        bool operator==(const TreeType &p1) const;

        // Assignment operator
        TreeType &operator=(const TreeType &t);
    };

    /*
     * Static method that controls access to the singleton
     */
    static TreeFactory *get() {
        if (!sharedFlyweight)
            sharedFlyweight = new TreeFactory();
        return sharedFlyweight;
    }

    std::vector<TreeType> mutable sharedTrees;  // vector containing all instances of TreeType

    // Function used to insert a new TreeType into sharedTrees
    void insert(int col[3], const std::string &tp, int h, int w);

    // Function used to get a TreeType with all attributes
    TreeType getTreeType(int col[3], const std::string &tp, int h, int w);

    // Function used to get a TreeType with attribute type only (Surcharge...)
    TreeType getTreeType(const std::string &tp);

    // Function used to access the vector shared Trees
    std::vector<TreeType> &getSharedTrees() const {
        return sharedTrees;
    }
};


#endif //FLYWEIGHT_TREEFACTORY_H