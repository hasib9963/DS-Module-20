#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* input_tree()
{
    int val;
    cin>>val;
    Node* root;
    if(val==-1) root=NULL;
    else root=new Node(val);
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();

        int l,r;
        cin>>l>>r;
        Node* myLeft;
        Node* myRight;
        if(l==-1)
           myLeft=NULL;
        else 
           myLeft=new Node(l);
        if(r==-1)
           myRight=NULL;
        else
           myRight=new Node(r);
        p->left=myLeft;
        p->right=myRight;

        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}

void printLevel(Node* root, int x)
{
    if (root == NULL) return;
    if (x == 0)
        cout << root->val << " ";
    else if (x > 0)
    {
        bool found = false;
        queue<Node*> q;
        q.push(root);
        int lC = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node* tmp = q.front();
                q.pop();
                if (lC == x && tmp != NULL)
                {
                    cout << tmp->val << " ";
                    found = true;
                }
                if (tmp != NULL)
                {
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
            lC++;
        }
        if (!found)
            cout << "Invalid";
    }
}

int main()
{
    Node* root = input_tree();
    int x;
    cin>>x;
    printLevel(root, x);
    return 0;
}