#include<iostream>
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

int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<= end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

node* buildtree(int preorder[], int inorder[], int start, int end){
    static int idx = 0;
    if(start>end){
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    node* Node = new node(curr);
    if(start==end){
        return Node;
    }
    int pos = search(inorder, start, end, curr);
    Node->left = buildtree(preorder, inorder, start, pos-1);
    Node->right = buildtree(preorder, inorder, pos+1, end);

    return Node;
}

void inorderPrint(node* root){
    if(root == NULL){
        return ;
    }

    inorderPrint(root->left);
    cout << root->data<<" ";
    inorderPrint(root->right);
}


int main(){
    int preorder[]={1, 2, 4, 3, 5};
    int inorder[]={4, 2, 1, 5, 3};

    node* root = buildtree(preorder, inorder, 0, 4);
    inorderPrint(root);

}