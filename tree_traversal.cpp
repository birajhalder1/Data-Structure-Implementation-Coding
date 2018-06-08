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
void preOrderWithoutRecursion(struct node* node){
    if(node == NULL)    return ;
    stack<struct node*> s;
    s.push(node);

    while(!s.empty())
    {
        struct node* t = s.top();
        s.pop();
        cout<<t->data<<" ";

        if(t->right)
            s.push(t->right);
        if(t->left)
            s.push(t->left);
    }
}
void reverseLevelOrderTraversal(struct node* node){
    if(node == NULL)    return ;
    struct node* t = NULL;
    queue<struct node*> q;
    stack<struct node*> s;
    q.push(node);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        s.push(t);
        if(t->right)
            q.push(t->right);
        if(t->left)
            q.push(t->left);
    }
    while(!s.empty())
    {
        t = s.top();
        s.pop();
        cout<<t->data<<" ";
    }

}
void levelByLevelPrintTree(struct node* node){
    if(node == NULL)    return ;
    struct node* t = NULL;
    queue<struct node* > q;
    q.push(node);
    q.push(NULL);
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        if(node!=NULL)
        {
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else
        {
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
            }
        }
    }
}
void spiralOrderTraversal(struct node* node){
    if(node == NULL)    return;
    stack<struct node*> s1,s2;
    s1.push(node);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            struct node* curr = s1.top();
            s1.pop();
            cout<<curr->data<<" ";
            if(curr->left != NULL)  s2.push(curr->left);
            if(curr->right != NULL) s2.push(curr->right);
        }
        while(!s2.empty())
        {
            struct node* curr = s2.top();
            s2.pop();
            cout<<curr->data<<" ";
            if(curr->right != NULL)  s1.push(curr->right);
            if(curr->left != NULL) s1.push(curr->left);
        }
    }
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



    cout<<"POst order Without Recursion"<<endl;
    postOrderWithoutRecursion(root);

    cout<<"Pre order Without Recursion"<<endl;
    preOrderWithoutRecursion(root);


    cout<<"Reverse Level order traversal"<<endl;
    reverseLevelOrderTraversal(root);

    cout<<"Level By Level Tree"<<endl;
    levelByLevelPrintTree(root);*/

    cout<<"Spiral Order Traversal"<<endl;
    spiralOrderTraversal(root);

    return 0;

}
