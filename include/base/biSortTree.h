#pragma once
#include "biTree.h"
#include <iostream>
#include <vector>
#define Tree biTree<int>
class BinarySortTree {
public:
    BinarySortTree(std::vector<int> arr) {
        tree = new Tree(arr[0]);
        Tree *root = nullptr;
        for (int i = 1; i < arr.size(); i++) {
            root = tree;
            while (1) {
                if (root->data > arr[i]) {
                    if (root->lchild == nullptr) {
                        root->lchild = new Tree(arr[i]);
                        break;
                    } else {
                        root = root->lchild;
                    }
                } else if (root->data < arr[i]) {
                    if (root->rchild == nullptr) {
                        root->rchild = new Tree(arr[i]);
                        break;
                    } else {
                        root = root->rchild;
                    }
                } else {
                    _ASSERT("redundant key" && 0);
                }
            }
        }
        inOrder(tree, seq);
    }
    Tree *search(int val) {
        Tree *node = tree;
        while (1) {
            if (node == nullptr) {
                return node;
            }
            if (node->data == val) {
                return node;
            } else if (node->data < val) {
                node = node->rchild;
            } else {
                node = node->lchild;
            }
        }
    }
    void insertNode(int val) {
        Tree *node = tree;
        while (1) {
            if (node == nullptr) {
                node = new Tree(val);
                inOrder(tree, seq);
                return;
            }
            if (node->data > val) {
                node = node->lchild;
            } else if (node->data < val) {
                node = node->rchild;
            } else {
                _ASSERT("redundant key" && 0);
            }
        }
    }
    Tree* deleteNode(int val) {
        Tree *node = tree;
        Tree *parent = nullptr;
        while (1) {
            if (node == nullptr) {
                return node;
            }
            if (node->data == val) {
                if (node->lchild == nullptr && node->rchild == nullptr) {
                    if (parent->lchild == node) {
                        parent->lchild = nullptr;
                    } else if (parent->rchild == node) {
                        parent->rchild = nullptr;
                    }
                    node->lchild = nullptr;
                    node->rchild = nullptr;
                    return node;
                } else if (node->lchild == nullptr) {
                    if (parent->lchild == node) {
                        parent->lchild = node->rchild;
                    } else if (parent->rchild == node) {
                        parent->rchild = node->rchild;
                    }
                    node->lchild = nullptr;
                    node->rchild = nullptr;
                    return node;
                } else if (node->rchild == nullptr) {
                    if (parent->lchild == node) {
                        parent->lchild = node->lchild;
                    } else if (parent->rchild == node) {
                        parent->rchild = node->lchild;
                    }
                    node->lchild = nullptr;
                    node->rchild = nullptr;
                    return node;
                } else {
                    auto pos = std::find(seq.begin(), seq.end(), val);
                    int next = *(pos + 1);
                    auto temp = deleteNode(next);
                    node->data = next;
                    temp->lchild = nullptr;
                    temp->rchild = nullptr;
                    return temp;
                }
            } else if (node->data > val) {
                parent = node;
                node = node->lchild;
            } else {
                parent = node;
                node = node->rchild;
            }
        }
    }
private:
    Tree* tree = nullptr;
    std::vector<int> seq{};
};