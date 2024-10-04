#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void inserAtHead(node* &head, int val){
    node* n = new node(val);

    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

node* reverse(node* &head){

    node* preptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = preptr;

        preptr = currptr;
        currptr = nextptr;
    }

    return preptr;

}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    
    node* newhead = reverse(head);
    display(newhead);

    return 0;
}
