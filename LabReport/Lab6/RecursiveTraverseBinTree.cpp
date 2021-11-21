#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct Node
{
    char element;
    Node *lChild;
    Node *rChild;
   // Node(char val):element(val), lChild(NULL), rChild(NULL){}
}*BinTree;

void createBinTree(BinTree &root)
{
    char ch;
    //scanf("%c", &ch); //用scanf第二棵树会有问题
    cin >> ch;
    if (ch == '#') root = NULL;
    else
    {
        //root = new Node(ch);
        root = (BinTree)malloc(sizeof(Node));
        root->element = ch;
        createBinTree(root->lChild);
        createBinTree(root->rChild);
    }
}

void preOrderTraverse(BinTree root)
{
    if(root)
    {
        printf("%c ", root->element);
        preOrderTraverse(root->lChild);
        preOrderTraverse(root->rChild);
    }
}

void inOrderTraverse(BinTree root)
{
    if(root)
    {
        inOrderTraverse(root->lChild);
        printf("%c ", root->element);
        inOrderTraverse(root->rChild);
    }
}

void posOrderTraverse(BinTree root)
{
    if(root)
    {
        posOrderTraverse(root->lChild);
        posOrderTraverse(root->rChild);
        printf("%c ", root->element);
    }
}

int treeDepthIs(BinTree root)
{
    if(!root) return 0;
    else
    {
        int left = treeDepthIs(root->lChild);
        int right = treeDepthIs(root->rChild);
        return max(left, right) + 1;
    }
}

int leaveNumberIs(BinTree root)
{
    if (!root) return 0;
    else
    {
        if (!root->lChild && !root->rChild) return 1;
        return leaveNumberIs(root->lChild) + leaveNumberIs(root->rChild);
    }
}

int totalNumberIs(BinTree root)
{
    if (!root) return 0;
    else
    {
        int num1 = totalNumberIs(root->lChild);
        int num2 = totalNumberIs(root->rChild);
        return (num1 + num2 + 1);
    }
}

int isSameTree(BinTree root1, BinTree root2)
{
    if(root1 && root2)
    {
        if(root1->element != root2->element) return 0;
        return isSameTree(root1->lChild, root2->lChild) && isSameTree(root1->rChild, root2->rChild);
    }
    return 1;
}

void menu(BinTree root1, BinTree root2)
{
    cout << "***Please select********" << endl;
    cout << "1. PreOrderTraverse" << endl;
    cout << "2. InOrderTraverse" << endl;
    cout << "3. PosOrderTraverse" << endl;
    cout << "4. TreeDepth" << endl;
    cout << "5. LeaveNumber" << endl;
    cout << "6. TotalNumber" << endl;
    cout << "7. IsSameTree" << endl;
    cout << "0. Exit" << endl;
    int select;
    cin >> select;
    switch (select)
    {
    case 1: cout << "PreOrderTraverse: "; 
            preOrderTraverse(root1);
            cout << endl << "PreOrderTraverse: "; 
            preOrderTraverse(root2);
            cout << endl << endl;
            break;
    case 2: cout << "InOrderTraverse: "; 
            inOrderTraverse(root1);
            cout << endl << "InOrderTraverse: "; 
            inOrderTraverse(root2);
            cout << endl << endl;
            break;
    case 3: cout << "PosOrderTraverse: "; 
            posOrderTraverse(root1);
            cout << endl << "PosOrderTraverse: "; 
            posOrderTraverse(root2);
            cout << endl << endl;
            break;
    case 4: cout << "Tree1DepthIs: " << treeDepthIs(root1) << endl;
            cout << "Tree2DepthIs: " << treeDepthIs(root2) << endl << endl;
            break;
    case 5: cout << "Tree1LeaveNumberIs: " << leaveNumberIs(root1) << endl; 
            cout << "Tree2LeaveNumberIs: " << leaveNumberIs(root2) << endl << endl; 
            break;
    case 6: cout << "Tree1TotalNumberIs: " << totalNumberIs(root1) << endl << endl; 
            cout << "Tree2TotalNumberIs: " << totalNumberIs(root2) << endl << endl; 
            break;
    case 7: cout << "IsSameTree: "; 
            if(isSameTree(root1, root2)) cout << "Yes" << endl;
            else cout << "No" << endl << endl;
            break; 
    default:exit(0);
            break;
    }
}

int main()
{
    BinTree root1 = NULL;  
    cout << "To Create BinTree, Please Input PreOrder with '#' :";
    createBinTree(root1);

    BinTree root2 = NULL;
    cout << "To Create BinTree, Please Input PreOrder with '#' :";
    createBinTree(root2);
    while (true) menu(root1, root2);  
    return 0;
}
