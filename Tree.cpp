//
// Created by yassine on 22/02/2022.
//

#include "Tree.h"

Tree &Tree::operator=(const Tree &t) {
    // protection against auto-assignment
    if (this == &t)
        return *this;
    x = t.get_x();
    y = t.get_y();
    type = t.get_type();
    return *this;
}
