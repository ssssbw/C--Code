#include <iostream>
#include <stack>
using namespace std;

typedef struct Node
{
    char element;
    Node *lChild;
    Node *rChild;
}*BinTree;

void createBinTree(BinTree &root)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#') root = NULL;
    else
    {
        if(!(root = (BinTree)malloc(sizeof(BinTree)))) exit(0);
        root->element = ch;
        root->lChild = NULL;
        root->rChild = NULL;
        createBinTree(root->lChild);
        createBinTree(root->rChild);
    }
} 

void preOrderTraverse(BinTree root)
{
    cout << "preOrderTraverse: ";
    if(root)
    {
        stack<BinTree> s;
        s.push(root);
        while (!s.empty())
        {
            root = s.top();
            s.pop();
            cout << root->element << " ";
            if (root->rChild)
            {
                s.push(root->rChild);
            }
            if (root->lChild)
            {
                s.push(root->lChild);
            }
        }
    }
    cout << endl;
}

void inOrderTraverse(BinTree root)
{
    cout << "inOrderTraverse: ";
    if (root)
    {
        stack<BinTree> s;
        while (!s.empty() || root)
        {
            if(root)
            {
                s.push(root);
                root = root->lChild;
            }
            else
            {
                root = s.top();
                s.pop();
                cout << root->element << " ";
                root = root->rChild;
            }
        }
    }
    cout << endl;
}

void posOrderTraverse(BinTree root)
{
    cout << "posOrderTraverse: ";
    if (root)
    {
        stack<BinTree> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            root = s1.top();
            s1.pop();
            s2.push(root);
            if (root->lChild)
            {
                s1.push(root->lChild);
            }
            if (root->rChild)
            {
                s1.push(root->rChild);
            }            
        }
        while (!s2.empty())
        {
            cout << s2.top()->element << " ";
            s2.pop();
        }
    }
    cout << endl;
}

int main()
{
    BinTree root;
    createBinTree(root);
    preOrderTraverse(root);
    inOrderTraverse(root);
    posOrderTraverse(root);
    return 0;
}