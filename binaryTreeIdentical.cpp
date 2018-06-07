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
bool isIdentical(struct node* r1, struct node* r2){
    queue<struct node*> q1,q2;
    q1.push(r1); q2.push(r2);

    while(!q1.empty() && !q2.empty())
    {
        struct node* n1 = q1.front();
        struct node* n2 = q2.front();
        if(n1->data != n2->data)
            return false;

        q1.pop();q2.pop();
        if(n1->left && n2->left){
            q1.push(n1->left);
            q2.push(n2->left);
        }
        else if (n1->left || n2->left)
            return false;
        if(n1->right && n2->right){
            q1.push(n1->right);
            q2.push(n2->right);
        }
        else if (n1->right || n2->right)
            return false;
    }
    return true;
}




int main()
{
    struct node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    struct node* root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);


    cout<<isIdentical(root1,root2)<<endl;



    return 0;

}

