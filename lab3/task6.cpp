#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    Node(int val){
        data = val;
        next = NULL;
        child = NULL;
    }

};

// class list{
//     Node* head ;
//     Node* tail;

//     public:
//     list(){
//         head = tail = NULL;

//     }

    // insert at first:
    // void push_front(int val){
    //     Node* newnode = new Node(val);

    //     if(head == NULL){
    //         head = tail = newnode;
    //         return;
    //     }
    //     else{
    //         newnode->next = head;
    //         head = newnode;

    //     }
    // }

    void print(Node* head){
       
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void flatten(Node* head){
       // Node* tail = NULL;

        Node* temp = head;
       
        while(temp != NULL){
            
            if(temp->child != NULL){
                Node* curr = temp->next;  //3
                temp->next = temp->child;  //2->4
            
                Node* tail = temp->next;

                while(tail->next != NULL){
                tail = tail->next;
            }
                tail->next = curr; // 5->3 
            }
            temp = temp->next;
        }
        

    }


int main(){
  Node* head = new Node(1);
  Node *second = new Node(2);
  Node *third = new Node(3);
 
  head->next = second;
  second->next = third;
  third->next =NULL;

  

  Node* child1 = new Node(4);
  Node* child2 = new Node(5);

  child1->next = child2;
  child2->next = NULL;

  // now joing child to any one node:
  second->child = child1;
   
   cout << "Original Multilevel List:" << endl;
    cout << "1 -> 2 -> 3" << endl;
    cout << "     |" << endl;
    cout << "     4 -> 5" << endl << endl;


  cout<<"flatten linked list: "<<endl;
   flatten(head);
   print(head);

  

}




