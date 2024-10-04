//Floyd's Algorithm
//hear and tortoise Algorithm

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

void InsertAtTail(node* &head, int value){
    node* n = new node(value);
    if(head==NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = n;
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp = temp ->next;
    }
    cout << endl;
}

void makeCycle(node* head, int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next!=NULL){
        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count ++;
    }
    temp->next = startNode;
    
}

bool detectCycle(node* &head){

    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;

    }while(slow!=fast);

    fast = head;
    while(slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}


int main(){
    node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);

    makeCycle(head, 3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);

    cout<< detectCycle(head)<<endl;
    display(head);
    

}