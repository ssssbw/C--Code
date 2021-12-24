#include <iostream>
#include <cstdlib> 
#include <stack>
#include <queue>
using namespace std;

typedef struct Node
{
    char element;
    Node *lChild;
    Node *rChild;
}*BinTree;
void createBinTree(BinTree &root)
{
    stack<BinTree> s;
    BinTree p = NULL, q = NULL;
    char ch;
    int flag = 0;
    ch = getchar();
    while(ch != '#')
    {
        switch(ch)
        {
            case '(': s.push(p); flag = 1; break;
            case ',': flag = 0; break;
            case ')': s.pop();break;
            default: 
                p = (BinTree)malloc(sizeof(Node));
                p->lChild = p->rChild = NULL;
                p->element = ch;
                if(!root)
                {
                    root = p;
                }
                else
                {
                   q = s.top();
                   if (flag)
                   {
                       q->lChild = p;
                   }
                   else q->rChild = p;
                }
        }
        ch = getchar();
    }
} 

void levelOrder(BinTree root)
{
    cout << "levelOrder: ";
    if(root)
    {
        queue<BinTree> queue;
        BinTree p = NULL, r = NULL;
        p = root;
        queue.push(p);
        while(!queue.empty())
        {
        r =  queue.front();
        queue.pop();
        cout << r->element << " ";
        if(r->lChild)
            queue.push(r->lChild);
        if(r->rChild)
            queue.push(r->rChild);
        }
    }
    cout << endl;
}

int binTreeWidth(BinTree root)
{
    if(!root)   return 0; //空树返回0

    int width = 1, max = width;
    int i = 1, max_i = i; //二叉树层次i, 最大宽度max_i所在层次i;
    queue<BinTree> queue;
    BinTree p = NULL;
    queue.push(root);

    while(!queue.empty())
    {
        p = queue.front();
        queue.pop();
        width--;
        if (p->lChild)  queue.push(p->lChild);
        if (p->rChild)  queue.push(p->rChild);
        
        if(width == 0)
        {
            width = queue.size();
            i++;
            if(width > max)
            {
                max = width;
                max_i = i;
            }
        }
    }
    return max;
}

void locata_Elem(BinTree root, char elem, int floor, int *res)
{
    if (root)
    {
        if(root->element == elem) *res = floor;
        locata_Elem(root->lChild, elem, floor + 1, res);
        locata_Elem(root->rChild, elem, floor + 1, res);
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
    BinTree root = NULL;
    createBinTree(root);
    levelOrder(root);
    cout << "二叉树宽度为: " << binTreeWidth(root) << endl;
    char ch;
    int floor = 1, res = -1;
    cin >> ch;
    locata_Elem(root, ch, floor, &res);
    if(res <= 0) cout << "元素" << ch << "不在树上" << endl;
    else cout << "元素" << ch << "所在层次为: " << res << endl;
    // preOrderTraverse(root);
    // inOrderTraverse(root);
    // posOrderTraverse(root);
    return 0;
}
