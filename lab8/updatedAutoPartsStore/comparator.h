#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "Supply.h"

struct CompareAmount {
    bool operator()(const pair<string, Part>& left, const pair<string, Part>& right) {
        return left.second.amount > right.second.amount;
    }
};

#endif // COMPARATOR_H
