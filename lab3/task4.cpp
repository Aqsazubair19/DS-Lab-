#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
public:
    CircularList() {
        head = NULL;
    }

    void create(int n) {
        Node* temp = NULL;
      
        for(int i=1; i<=n; i++) {
          Node* newnode = new Node(i);
          
            if(head == NULL) {
              head = newnode;
              head->next = head;
              temp = head;
            } 
            else {
                temp->next = newnode;
               newnode->next = head;
              temp = newnode;
            }
        }
    }

    int josephus(int k) {
        Node* prev = head;
        Node* curr = head;
      
          while(prev->next != curr) prev = prev->next;
      
         while(curr->next != curr) {
            for(int i=1; i<k; i++) {
                prev = curr;
                curr = curr->next;
            }
           
            prev->next = curr->next;
            Node* del = curr;
            curr = curr->next;
            delete del;
        }
      
        int ans = curr->data;
        delete curr;
        return ans;
    }
};

int main() {
    int n = 7, k = 3;
    CircularList cl;
    cl.create(n);
    cout << "Survivor: " << cl.josephus(k) << endl;
}
