
#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<stack>

using namespace std;

stack<struct node*> result;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node ->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
int count_halfnode(struct node* node){
    queue<struct node*> q;
    int count = 0;
    q.push(node);
    while(!q.empty())
    {
        struct node* temp = q.front();
        q.pop();
        if(!temp->left &&temp->right || temp->left && !temp->right)
            count++;
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
    return count;
}
int count_leafnode(struct node* node){
    queue<struct node*> q;
    int count = 0;
    q.push(node);
    while(!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
        if(!temp->left && !temp->right)
            count++;
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
    return count;
}
int count_fullnode(struct node* node){
    queue<struct node*> q;
    int count = 0;
    q.push(node);
    while(!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
        if(temp->left && temp->right)
            count++;
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
    return count;
}
int sizeof_tree(struct node* node){
    if(node == NULL)
        return 0;
    int leftSize = sizeof_tree(node->left);
    int rightSize = sizeof_tree(node->right);
    return(leftSize+rightSize+1);
}
int max_fun(int a, int b){
    if(a>=b)
        return a;
    else
        return b;
}
int heightof_tree(struct node* node){
    if(node == NULL)
        return 0;
    int heightLeftSubtree = heightof_tree(node->left);
    int heightRightSubtree = heightof_tree(node->right);
    return 1+ max_fun(heightLeftSubtree, heightRightSubtree);
}
bool pathfind_tree(struct node* node, int sum){//find path with given edge value sum
    if(node == NULL)    return false;
    if(node->left ==NULL && node->right == NULL)
    {
        if(node->data == sum){
            result.push(node);
            return true;
        } else  return false;
    }
    if(pathfind_tree(node->left,sum - node->data))
    {
        result.push(node);
        return true;
    }
    if(pathfind_tree(node->right,sum - node->data))
    {
        result.push(node);
        return true;
    }
    return false;
}
bool isbst(struct node* node,int min,int max){//check if it is bst or not
    if(node == NULL)
        return true;
    if(node->data <= min || node->data > max)   return false;
    return isbst(node->left,min,node->data) && isbst(node->right,node->data,max);
}
void heightOfTreeIterativeWay(struct node* node){
    if(node == NULL)    return;
    queue<struct node*> q;
    q.push(node);
    int height = 0;
    while(1){
        int node_count = q.size();
        if(node_count == 0) {
            cout<<height<<endl;
            return;
        }
        height++;
        while(node_count > 0){
            struct node* t = q.front();
            q.pop();
            if(t->left != NULL)
                q.push(t->left);
            if(t->right != NULL)
                q.push(t->right);
            node_count--;
        }
    }
}

struct node* lca(struct node* node, int n1, int n2){
    if(node == NULL)    return NULL;
    if(node->data == n1 || node->data == n2)    return node;
    struct node* left = lca(node->left,n1,n2);
    struct node* right = lca(node->right,n1,n2);
    if(left == NULL && right == NULL)   return NULL;
    if(left != NULL && right != NULL)   return node;
    return left != NULL?left:right;
}

int main()
{

    struct node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(8);
    /*cout<<"The Number of Half leaf Node is : "<<count_halfnode(root)<<endl;
    cout<<"The Number of Leaf Node is : "<<count_leafnode(root)<<endl;
    cout<<"The Number of Full Node is : "<<count_fullnode(root)<<endl;
    cout<<"The Size of the tree is : "<<sizeof_tree(root)<<endl;
    cout<<"The Height of the tree is : "<<heightof_tree(root)<<endl;

    bool r = pathfind_tree(root,18);
    if(r)
    {
        while(!result.empty())
        {
            struct node* t = result.top();
            cout<<t->data<<" ";
            result.pop();
        }
    }
    else
        cout<<"path not Found"<<endl;
    cout<<endl;

    if(isbst(root,INT_MIN, INT_MAX))
        cout<<"I am BST!!!"<<endl;
    else
        cout<<"I am NOT BST!!"<<endl;


    cout<<"Height:"<<endl;
    heightOfTreeIterativeWay(root);*/

    cout<<"LCA is"<<endl;
    root = lca(root,7,8);
    cout<<root->data<<endl;

    return 0;


}
