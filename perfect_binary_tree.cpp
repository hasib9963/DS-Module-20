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

int height(Node* root){
    if(root == NULL) return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight, rHeight) + 1;
}

int cNodes(Node* root)
{
    if(root == NULL)
        return 0;
    return (1 + cNodes(root->left) + cNodes(root->right));
}

bool perfect(Node* root, int height, int index){
    if(root == NULL)
        return true;
    if(root->left == NULL && root->right == NULL)
        return (height == index+1);
    if(root->left == NULL || root->right == NULL)
        return false;
    return perfect(root->left, height, index+1) && perfect(root->right, height, index+1);
}

bool cPerfect(Node* root)
{
    int h = height(root);
    int n = cNodes(root);
    return (n == pow(2,h)-1 && perfect(root,h,0));
}

int main()
{
    Node* root = input_tree();
    if(cPerfect(root))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}