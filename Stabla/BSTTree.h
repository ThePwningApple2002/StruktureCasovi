#pragma once
#include <iostream>
#include "BSTNode.h"
using namespace std;
class BSTTree {
    public:
        BSTNode* root;
        BSTTree() : root(nullptr) {}
        BSTTree(BSTNode* r) : root(r) {}
        void insert(int val);
        void inorder(BSTNode* node) {
            if (node != nullptr) {
                inorder(node->left);
                cout << node->data << " ";
                inorder(node->right);
            }
        }
        void preorder(BSTNode* node) {
            if (node != nullptr) {
                cout << node->data << " ";
                preorder(node->left);
                preorder(node->right);
            }
        }
        void postorder(BSTNode* node) {
            if (node != nullptr) {
                postorder(node->left);
                postorder(node->right);
                cout << node->data << " ";
            }
        }

        int count(BSTNode* root){
            if(root==nullptr){
                return 0;
            }
            return 1+count(root->left)+count(root->right);

        }

       
        int sumaleft(BSTNode* root)
        {
            if(root==nullptr){
                return 0;
            }
            return root->data + sumaleft(root->left)+ sumaleft(root->right);
        }

        int sumaright(BSTNode* root)
        {
            if(root==nullptr){
                return 0;
            }
            return root->data + sumaright(root->left)+ sumaright(root->right);
        }

        int suma(BSTNode* root)//za svako podstablo suma
        {
            if(root==nullptr)
            {
                return 0;
            }
            int sl=suma(root->left);
            int sr=suma(root->right);
            int total=root->data+sl+sr;
            
            cout<<"suma podstabla cvora:" <<root->data<< " "<<total<<endl;
            return total;
        }
        

        
};