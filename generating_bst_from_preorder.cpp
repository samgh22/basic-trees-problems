#include<bits/stdc++.h>
using namespace std;

class Node
{public:
    Node* lchild;
    Node* rchild;
    int data;
};

class BST
{private:
    Node* root;
public:
    BST(){root = nullptr;}
    Node* getRoot(){return root;}
    Node* create_from_preorder(int pre[], int n);
};

Node* BST::create_from_preorder(int *pre, int n)
{
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = nullptr;
    root->rchild = nullptr;
    Node* t;
    Node* p = root;
    stack<Node*> stk;
    while(i < n)
    {
        if(pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p =t;
        }
        else
        {
            if(pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data)
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
    return p;
}

int main()
{
    return 0;
}
