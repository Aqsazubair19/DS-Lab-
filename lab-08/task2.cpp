#include <iostream>
using namespace std;

class Node {
public:
    string title;
    int playCount;
    Node* left;
    Node* right;

    Node(string t, int count) {
        title = t;
        playCount = count;
        left = right = NULL;
    }
};

Node* insertNode(Node* root, string title, int playCount) {
    if (root == NULL) {
        return new Node(title, playCount);
    }
    if (playCount < root->playCount) {
        root->left = insertNode(root->left, title, playCount);
    } else if (playCount > root->playCount) {
        root->right = insertNode(root->right, title, playCount);
    } else {
        cout << "Song with play count " << playCount << " already exists!\n";
    }
    return root;
}

Node* searchNode(Node* root, int playCount) {
    if (root == NULL || root->playCount == playCount)
        return root;
    if (playCount < root->playCount)
        return searchNode(root->left, playCount);
    else
        return searchNode(root->right, playCount);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->title << " (" << root->playCount << ") ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->title << " (" << root->playCount << ") ";
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int playCount) {
    if (root == NULL) return root;

    if (playCount < root->playCount)
        root->left = deleteNode(root->left, playCount);
    else if (playCount > root->playCount)
        root->right = deleteNode(root->right, playCount);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->title = temp->title;
        root->playCount = temp->playCount;
        root->right = deleteNode(root->right, temp->playCount);
    }
    return root;
}

int main() {
    Node* root = NULL;

    root = insertNode(root, "SongA", 50);
    root = insertNode(root, "SongB", 20);
    root = insertNode(root, "SongC", 70);
    root = insertNode(root, "SongD", 40);
    root = insertNode(root, "SongE", 60);
    root = insertNode(root, "SongF", 80);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout<<endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    cout<<endl;



    int searchCount = 40;
    Node* found = searchNode(root, searchCount);
    if (found != NULL)
    cout <<"Found song with play count" << searchCount << ": "<< found->title << endl;
    else
     cout << "Song with play count " << searchCount << " not found." << endl;


     cout<<endl;
    

    int deleteCount = 70;
    root = deleteNode(root, deleteCount);
    cout << "After deleting song with play count " << deleteCount << ": ";
    inorder(root);
    cout << endl;

    return 0;
}
