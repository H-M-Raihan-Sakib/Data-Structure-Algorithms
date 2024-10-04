#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node* right;
    struct node* left;

    node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

int sumAtKthLevel(node* root, int K){

    if(root==NULL){
        return -1;
    }

    int x = 0, sum = 0;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* node = q.front();
        q.pop();
        if(node!=NULL){
            if(x==K){
            sum += node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            x++;
        }

    }

    return sum ;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << sumAtKthLevel(root,2) <<endl;

    return 0;
}