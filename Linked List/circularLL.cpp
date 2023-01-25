#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data=data;
        this->next=NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next !=NULL) {
            delete next;
            next = NULL;
        }
         cout<<"memory is free for node with data "<<value<<endl;
    }
};
void insertNode(Node* &tail, int element , int data ) {
    if(tail==NULL) {//which means linked list is empty 
    //so first create new node 
    Node* temp = new Node(data);
    tail = temp;
    temp ->next =temp;  // to make that node circular
    }
    else {//list empty nai hai
    Node* curr = tail;
    while(curr->data != element) {
        curr=curr->next;
    }
    Node* temp = new Node(data);
    temp ->next=curr->next;
    curr->next=temp;
    }
}
void print(Node* &tail) {
    Node* temp = tail;
    if(tail==NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    do {
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);

    cout<<endl;
}
void deletNode(Node* &tail,int value) {
    if(tail==NULL) {
        cout<<"List is empty please check again"<<endl;
        return;
    }
    else {
        Node*prev= tail;
        Node* curr = prev->next;
        while(curr->data != value ) {
            prev=curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if(curr==prev) {
            tail=NULL;
        }
        else if(tail ==curr ){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;

    }
}
int main() {
    Node* tail = NULL;
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

     insertNode(tail,5,7);
    print(tail);

    deletNode(tail,3);
    print(tail);
    return 0;
}