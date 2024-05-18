#include <iostream>
#include "base/biTree.h"
int main() {
    std::string pre_ = "ABCDEFGHI";
    std::vector<char> pre(9, '\0');
    memcpy(pre.data(), pre_.data(), 9);
    std::string in_ = "BCAEDGHFI";
    std::vector<char> in(9, '\0');
    memcpy(in.data(), in_.data(), 9);
    auto tree = initTreePreIn<char>(pre, in);
    return 0;
}