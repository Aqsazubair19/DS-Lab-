#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    string data;
    Node* mother;  // left child
    Node* father;  // right childd
public:

    Node(string st){
        data = st;
        mother= father = NULL;
    }
};


void printLeafNodes(Node* root) {
    if (root == NULL) return;
    if (root->mother == NULL && root->father == NULL) {
        cout << root->data << " ";
        return;
    }
    printLeafNodes(root->mother);
    printLeafNodes(root->father);
}

int height(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->mother), height(root->father));
}


void levelorder_traversal_level_by_level(Node* root){
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);

     int level = 0;
    cout <<"level "<< level << ": ";

    while(q.size()>0 ){

       Node* curr = q.front();
       q.pop();

       if(curr == NULL){
        if(!q.empty()){
            cout<<endl;
             level++;
            cout << "level " << level << ": ";
            q.push(NULL);
            continue;
        }
        else{  // if queue is empty - all elments are traverse 
            break;
        }
       }

       cout<<curr->data<<" ";

       if(curr->mother != NULL){
       q.push(curr->mother);
       }

       if(curr->father != NULL){
       q.push(curr->father);
    } 

}

   
}

int main(){
  Node* root = new Node("yongest");
 
  root->mother   = new Node("mother");
  root->father   =  new Node("father");
  root->father->mother = new Node("dadi");
  root->father->father = new Node("dada");
  root->mother->mother = new Node("nani");
  root->mother->father = new Node("nana");

  levelorder_traversal_level_by_level(root);
   cout<<endl;
   cout<<"ROOT OF BT TREE: "<<root->data<<endl;
   cout<<endl;
   cout<<"height of trre: "<<height(root)<<endl;;
     cout<<endl;
   cout<<"leaf nodes:";
   printLeafNodes(root);

}
