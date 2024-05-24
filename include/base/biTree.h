#pragma once
#include <iostream>
#include <vector>
template<typename T>
struct biTree {
    T data;
    biTree* lchild = nullptr, * rchild = nullptr;
    biTree() {};
    biTree(T t) {data = t;}
    biTree(T t, biTree *l, biTree *r) {lchild = l; rchild = r;}
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
void inOrder (biTree<T> *tree, std::vector<T>& seq) {
    if (tree->lchild != nullptr) {
        inOrder(tree->lchild, seq);
    }
    if (tree != nullptr) {
        seq.emplace_back(tree->data);
    }
    if (tree->rchild != nullptr) {
        inOrder(tree->rchild, seq);
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

// 上面的遍历是使用递归实现的，接下来使用非递归实现三种顺序的遍历

#include <stack>
template<typename T>
void preOrderS(biTree<T> *tree) {
    std::stack<biTree<T> *> nodes;
    biTree<T>* root = tree;
    while (1) {
        if (root != nullptr) {
            std::cout << root->data << std::endl;
            nodes.push(root);
            root = root->lchild;
            continue;
        }
        if (nodes.empty()) {
            break;
        }
        root = nodes.top()->rchild;
        nodes.pop();
    }
}

template<typename T>
void inOrderS(biTree<T>* tree) {
    std::stack<biTree<T>*> nodes;
    biTree<T>* root = tree;
    while (1) {
        if (root != nullptr) {
            nodes.push(root);
            root = root->lchild;
            continue;
        }
        if (nodes.empty()) {
            break;
        }
        std::cout << nodes.top()->data << std::endl;
        root = nodes.top()->rchild;
        nodes.pop();
    }
}

template<typename T>
void postOrderS(biTree<T>* tree) {
    std::stack<biTree<T>*> nodes;
    biTree<T>* root = tree;
    while (1) {
        if (root != nullptr) {
            nodes.push(root);
            root = root->lchild;
            continue;
        }
        if (nodes.empty()) {
            break;
        }
        biTree<T>* top = nodes.top();
        if (top->rchild == nullptr) {
            std::cout << top->data << std::endl;
            nodes.pop();
        }
        else {
            root = top->rchild;
        }
    }
}