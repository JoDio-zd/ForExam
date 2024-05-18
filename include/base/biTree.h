#include <iostream>
#include <vector>
template<typename T>
struct biTree {
    T data;
    biTree* lchild = nullptr, * rchild = nullptr;
};

/**
    通过先序序列和中序序列初始化一个二叉树
    后序序列和中序序列的解决方案一致
*/
template<typename T>
biTree<T> * initTreePreIn(std::vector<T> pre, std::vector<T> in) {
    if (pre.size() == 0 || in.size() == 0) {
        return nullptr;
    }
    biTree<T> *root = new biTree<T>();
    root->data = pre[0];
    auto rootnode = std::find(in.begin(), in.end(), pre[0]);
    std::vector<T> lInTree(in.begin(), rootnode);
    std::vector<T> rInTree(rootnode + 1, in.end());
    std::vector<T> lPreTree(pre.begin() + 1, pre.begin() + 1 + lInTree.size());
    std::vector<T> rPreTree(pre.begin() + 1 + lInTree.size(), pre.end());
    root->lchild = initTreePreIn(lPreTree, lInTree);
    root->rchild = initTreePreIn(rPreTree, rInTree);
    return root;
}

template<typename T>
void preOrder (biTree<T> *tree) {
    if (tree != nullptr) {
        std::cout << tree->data << std::endl;
    }
    if (tree->lchild != nullptr) {
        preOrder(tree->lchild);
    }
    if (tree->rchild != nullptr) {
        preOrder(tree->rchild);
    }
}

template<typename T>
void inOrder (biTree<T> *tree) {
    if (tree->lchild != nullptr) {
        inOrder(tree->lchild);
    }
    if (tree != nullptr) {
        std::cout << tree->data << std::endl;
    }
    if (tree->rchild != nullptr) {
        inOrder(tree->rchild);
    }
}

template<typename T>
void postOrder (biTree<T> *tree) {
    if (tree->lchild != nullptr) {
        postOrder(tree->lchild);
    }
    if (tree->rchild != nullptr) {
        postOrder(tree->rchild);
    }
    if (tree != nullptr) {
        std::cout << tree->data << std::endl;
    }
}