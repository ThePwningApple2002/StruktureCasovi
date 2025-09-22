#pragma once
#include <iostream>
using namespace std;
class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
    BSTNode (int val, BSTNode* l, BSTNode* r) : data(val), left(l), right(r) {}
};