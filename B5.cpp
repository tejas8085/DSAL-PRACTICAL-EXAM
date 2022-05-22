/*
A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method. 

               QUESTIONS

1. Binnay Tree ---> a binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child.

2. Traversal in Binary Tree
   1)  Inorder --> 
        It means that first left subtree is visited after that root node is traversed, and finally, the right subtree is traversed
        eg.  left- root- right

   2)  preorder -->  
        In preorder traversal, first, root node is visited, then left sub-tree and after that right   sub-tree is visited. 
        eg. root-left-right

   3)  postorder  --> 
        The postorder traversal is one of the traversing techniques used for visiting the node in the tree. It follows the principle LRN (Left-right-node).

*/

#include <iostream>
using namespace std;
struct node
{
    char lbl[30];
    int chapters;
    node *cnode[30];
} * root;
class book
{
public:
    void createtree();
    void displaytree(node *r);
    book()
    {
        root = NULL;
    }
};
void book::createtree()
{
    int chpcount, i, j, k;
    root = new node;
    cout << "ENTER NAME OF THE BOOK-: ";
    cin >> root->lbl;
    cout << "ENTER NO. OF CHAPTERS-: ";
    cin >> chpcount;
    root->chapters = chpcount;
    for (i = 0; i < chpcount; i++)
    {
        root->cnode[i] = new node;
        cout << "ENTER CHAPTER NAME-: ";
        cin >> root->cnode[i]->lbl;
        cout << "ENTER NO. OF SECTIONS IN CHAPTER " << root->cnode[i]->lbl << "-: ";
        cin >> root->cnode[i]->chapters;
        for (j = 0; j < root->cnode[i]->chapters; j++)
        {
            root->cnode[i]->cnode[j] = new node;
            cout << "Enter Section" << j + 1 << "name-: ";
            cin >> root->cnode[i]->cnode[j]->lbl;
        }
    }
}
void book::displaytree(node *r)
{
    int i, j, k, chpcount;
    if (r != NULL)
    {
        cout << "\n -----BOOK HIERARCHY-----";
        cout << "\nBOOK TITLE: " << r->lbl;
        chpcount = r->chapters;
        for (i = 0; i < chpcount; i++)
        {
            cout << "\n CHAPTER" << i + 1 << " -: ";
            cout << " " << r->cnode[i]->lbl;
            cout << "\nSECTIONS";
            for (j = 0; j < r->cnode[i]->chapters; j++)
            {
                cout << "\n " << r->cnode[i]->cnode[j]->lbl << endl;
            }
        }
    }
}
int main()
{
    int choice;
    book bk;
    while (1)
    {
        cout << "-------------------" << endl;
        cout << "BOOK TREE CREATION" << endl;
        cout << "-------------------" << endl;
        cout << "1.CREATE" << endl;
        cout << "2.DISPLAY" << endl;
        cout << "3.EXIT" << endl;
        cout << "ENTER YOUR CHOICE-: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            bk.createtree();
            break;
        case 2:
            bk.displaytree(root);
            break;
        case 3:
            exit(1);
        
        default:
            cout<<"Wrong Input";
        }
    }

}