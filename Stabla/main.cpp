#include "BSTTree.h";
#include <iostream>;
using namespace std;
int main()
{
    BSTTree * stablo=new BSTTree();
    BSTNode * cvor=new BSTNode(10);
    stablo->root=cvor;
    BSTNode * cvor2=new BSTNode(13);
    BSTNode * cvor3=new BSTNode(7);
    BSTNode * cvor4=new BSTNode(1);
    BSTNode * cvor5=new BSTNode(30);
    BSTNode * cvor6=new BSTNode(6);
    stablo->insert(13);

    stablo->insert(7);
    stablo->insert(1);
    stablo->insert(30);
    stablo->insert(6);  
    
    stablo->suma(stablo->root);
    

}
