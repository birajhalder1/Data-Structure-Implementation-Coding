#include<iostream>
#include<queue>
#include<stack>
using namespace std;

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
void printfLevelorder(struct node* node){
    queue<struct node*> q;
    struct node* temp = node;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        temp = q.front();
        q.pop();
    }
}
void printfPostorder(struct node* node){
    if(node == NULL)
        return;
    printfPostorder(node->left);
    printfPostorder(node->right);
    cout<<node->data<<" ";
}
void printfinorder(struct node* node){
    if(node == NULL)
        return;
    printfinorder(node->left);
    cout<<node->data<<" ";
    printfinorder(node->right);
}
void printfpreorder(struct node* node){
    if(node == NULL)
        return;
    cout<<node->data<<" ";
    printfpreorder(node->left);
    printfpreorder(node->right);
}
void inOrderWithoutRecursion(struct node* node){
    int done=0;
    stack<struct node *> s;
    struct node* curr = node;
    while(!done)
    {
        if(curr!=NULL )
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if(!s.empty())
            {
                curr = s.top();
                s.pop();
                cout<<curr->data<<" ";
                curr = curr->right;
            }
            else
                done = 1;
        }
    }

}

void postOrderWithoutRecursion(struct node* node){
    if(node == NULL)
        return;
    stack<struct node*> s1, s2;
    s1.push(node);
    while(!s1.empty())
    {
        node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->left!=NULL)
            s1.push(node->left);
        if(node->right!=NULL)
            s1.push(node->right);
    }
    while(!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout<<node->data<<" ";
    }
}


void reverseLevelOrderTraversal(struct node* node) //error
{

}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
/*
    cout<<"PreOrder is :"<<endl;
    printfpreorder(root);
    cout<<endl;

    cout<<"InOrder is :"<<endl;
    printfinorder(root);
    cout<<endl;

    cout<<"PostOrder is :"<<endl;
    printfPostorder(root);
    cout<<endl;

    cout<<"LevelOrder is :"<<endl;
    printfLevelorder(root);


    cout<<"Inorder Without Recursion"<<endl;
    inOrderWithoutRecursion(root);

    cout<<"Reverse Level order traversal"<<endl;
    reverseLevelOrderTraversal(root);*/

    cout<<"POst order Without Recursion"<<endl;
    postOrderWithoutRecursion(root);



    return 0;

}
