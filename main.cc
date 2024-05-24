#include <iostream>
#include "base/biSortTree.h"

int main() {
    std::vector<int> val = {53, 17, 9, 45, 23, 78, 65, 87};
    BinarySortTree *tree = new BinarySortTree(val);
    auto node65 = tree->search(45);
    tree->insertNode(66);
    auto delenode = tree->deleteNode(17);
    return 0;
}