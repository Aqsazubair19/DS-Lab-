#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int v){
        data = v;
        next = NULL;
    }

};

class stack{
    public:
   Node* top;

   stack(){
    top = NULL;
   }

    void  push(int x){ 
      
     Node* newnode = new Node(x); 
        newnode->next = top;
        top = newnode;
        
    }
       
    

    void pop(){
  
    if(top == NULL ){  // if no elements
     cout<<"underflow"<<endl;
     return;

    }else{
       Node* temp= top; 
       cout<<temp->data<<endl;
       top = top->next; 
        delete temp;  
    
    }
    }


    int peek(){

    if(top == NULL ){  // if no elements
     cout<<"underflow"<<endl;
     return -1;

    }else{
       return top->data;  
    }

  }

   bool isEmpty(){
       return top = NULL;
    }
   
  

};

int main(){
    stack ll;
    ll.push(6);
    ll.push(4);
    ll.push(3);
    ll.peek();
    ll.pop();
    ll.pop(); 
    ll.pop();

}
