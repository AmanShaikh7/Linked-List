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
    // 4) create insert at head function 
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
    void deleteNode(int position,Node* &head) {
        if(position==1) {
            Node* temp = head;
            head=head->next;

            //nullifying the node to be deleteed
            temp->next=NULL;
            //freee krre memory jo node delete hua 
            delete temp;

        }
        else {
            Node* curr=head;
            Node* prev=NULL;
            int cnt=1;
            while( cnt < position) {
                prev=curr;
                curr=curr->next;
                cnt++;
            }
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;


        }
    }
int main() {
   //2) //object in heap memory 
    Node* n1=new Node(8);
    //cout<< n1->data<<endl;
    //cout<< n1->next<<endl;
    
    //head pointing to new node 
    Node* head=n1;
    Node* tail=n1;
   // print(head);
    insertAtTail(tail,9);
    insertAtTail(tail,11);
    insertAtAnyPosition(tail,head,5,12);
    insertAtAnyPosition(tail,head,3,10);
    insertAtAnyPosition(tail,head,1,7);
    insertAtAnyPosition(tail,head,3,10);
    print(head);
    cout<<"Head "<<head ->data<<endl;
    cout<<"tail "<<tail ->data<<endl;
    deleteNode(7,head);
    print(head);
    cout<<"Head "<<head ->data<<endl;
    cout<<"tail "<<tail ->data<<endl;

    return 0;
    

}