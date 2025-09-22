#include "BSTTree.h"

void BSTTree::insert(int val)
{

    if(root==nullptr){
        cout<<"Root nije nullptr"<<endl;
        return;
    }
    BSTNode* tmp=this->root;
    while(tmp!=nullptr){
        cout<<"Usao u petlju"<<endl;
        if(tmp->data>val){
            cout<<"Usao u levo"<<endl;
            if(tmp->left==nullptr){
                cout<<"=nullptr levo"<<endl;
                tmp->left=new BSTNode(val);
                return;
            }
            tmp=tmp->left;
        }
        else{
            if(tmp->right==nullptr){
                cout<<"=nullptr desno"<<endl;
                tmp->right=new BSTNode(val);
                return;
            }
            tmp=tmp->right;
        }
    }
}


