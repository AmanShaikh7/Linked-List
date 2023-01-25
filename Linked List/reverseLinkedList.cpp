//input : 30->40->50->60->NULL
//output : 60->50->40->30->NULL

// the following solution is done in iterative way the same can be done in recurssive way

#include<iostream>
using namespace std;
class Node{
    public:
  // 1) //propreties
    int data;
    Node* next;
    // 3)  creating a constructor
    Node (int data) {
        this->data=data;
        this->next=NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next!=NULL) {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for data :"<<value<<endl;;
    }

};
void insertAtHead(Node* &head,int d) {
        //5) create new node 
        Node* temp =new Node(d);
        // initally this is pointing to null so change it and point it to head
        temp->next=head;
        head=temp;        
    }
   // 6 creating print function to travel linked list and print data in it 
    void print(Node* &head){
        Node* temp =head;
        while(temp != NULL) {
            cout<<temp->data <<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void insertAtTail(Node* &tail,int d){
        //create new node to insert at tail
        Node* temp = new Node(d);
        tail->next=temp;
        tail=tail->next;

    }
    void insertAtAnyPosition(Node* &tail,Node* & head,int position,int d) {
        if(position==1) {
            insertAtHead(head,d);
            return;
        }
        
        Node* temp=head;//for travelling till position -1 
        int cnt=1;
        
        while(cnt < position-1){
            if(temp->next==NULL) {
            insertAtTail(tail,d);
            return;
        }
            temp=temp->next;
            cnt++;
        }
        //create new node for d
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next=temp->next;
        temp->next=nodeToInsert;
    }
     void reverseList(Node* &head) {
        Node* curr=head;
        Node* prev =NULL;
        
        while(curr!=NULL) {
            Node* forward = curr->next;
            curr->next=prev;
            prev= curr;
            curr=forward;
        }
            head=prev;
    }
int main() {
    Node* n1 = new Node(50);
    Node* head =n1;
    Node*  tail =n1;
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtTail(tail,60);
    print(head);
    reverseList(head);
    print(head);


}