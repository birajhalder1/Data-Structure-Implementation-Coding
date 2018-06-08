#include<iostream>
#include<queue>

using namespace std;

struct node
{
    struct node* left;
    struct node* right;
    int data;
};

struct node* CreateNewNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right =  NULL;
    return node;
}

void printfpreorder(struct node* node){
    if(node == NULL)
        return;
    cout<<node->data<<" ";
    printfpreorder(node->left);
    printfpreorder(node->right);
}

//Binary Search Tree Insertion function
struct node* insertNodeInBst(struct node* node, int data)
{
    struct node* temp = CreateNewNode(data);
    if(node == NULL)
        return temp;
    struct node* par=NULL;
    struct node* curr=node;
    while(curr!=NULL)
    {
        par = curr;
        if(curr->data > data)
            curr = curr->left;
        else
            curr = curr ->right;
    }
    if(par->data > data)
        par->left = temp;
    else
        par->right = temp;
    return node;
}

//Binary Search Tree Search Function
void searchNodeInBst(struct node* node, int data)
{
    if(node == NULL)
    {
        cout<<"Not Found"<<endl;
        return;
    }
    if(data == node->data){
        cout<<"Found"<<endl;
        return;
    }
    if(data > node->data)
        searchNodeInBst(node->right,data);
    else
        searchNodeInBst(node->left, data);
}

struct node* lca(struct node* node, int n1, int n2)
{
    if(node->data > max(n1,n2))   return lca(node->left,n1,n2);
    else if(node->data < min(n1, n2))   return lca(node->right,n1,n2);
    else    return node;
}


int main()
{
    struct node * root = CreateNewNode(10);
    root = insertNodeInBst(root,8);
    root = insertNodeInBst(root,15);
    root = insertNodeInBst(root,18);
    root = insertNodeInBst(root,13);
    root = insertNodeInBst(root,9);
    root = insertNodeInBst(root,3);
    root = insertNodeInBst(root,20);
    printfpreorder(root);
    cout<<endl;
    searchNodeInBst(root,23);
    root = lca(root,9,3);
    cout<<root->data<<" ";
}
