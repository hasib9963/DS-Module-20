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

int sumVal(Node* root)
{
    if(root==NULL) return 0;
    else 
    return root->val+sumVal(root->left)+sumVal(root->right);
}

int main(){
    int n;
    cin>>n;
    Node* root=new Node(n);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* tmp=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        if(l!=-1){
            tmp->left=new Node(l);
            q.push(tmp->left);
        }
        if(r!=-1){
            tmp->right=new Node(r);
            q.push(tmp->right);
        }
    }
    cout<<sumVal(root)<<endl;
}
