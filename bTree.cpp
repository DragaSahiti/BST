#include <iostream>
using namespace std;

class Node{
    public:
    // Data
    int data;
    // Pointer to left Node and right Node
    Node * left;
    Node * right;
    // Constructor that makes the ptrs to NULL
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
    
};

class BiSTree{
    public:
    Node * root;
    // Cunstructor that points the root to NULL
    BiSTree(){
       root = NULL;
    }
    void insert(int value){
        insertHelper(root, value);
    }
    void insertHelper(Node * curr, int value){
        // Base case if curr is NULL the insert data
        if(curr == NULL){
           curr = new Node(value);
          
           if (root == NULL) root = curr;
           return;
        }
        // else compare the curr data with val
        else if (value < curr->data){
            // If val < curr data -> move to left and insert
            if(curr->left == NULL) curr->left = new Node(value);
            else insertHelper(curr->left, value);
           
        }
        else {    
            // If val > curr data -> move to right and insert 
            if(curr->right == NULL) curr->right = new Node(value);
            else insertHelper(curr->right, value);
            
        }    
    }
    void display(){display2(root);}
    
    void display2(Node * curr){
        // Base condition
        if (curr == NULL) return;
        // Display left
        display2(curr->left);
        // Display curr
        cout << curr->data << ",";
        // Display right
        display2(curr->right);
        // Display curr
        //cout << curr->data << ",";
    }
   
    Node * search(int value){
        return searchHelper(root, value);
    }
    Node * searchHelper(Node * curr, int value){
        // Are you the value?
        if (curr->data == value || curr == NULL) return curr;
        // else search on left or right
        // left
        else if(value < curr->data) return searchHelper(curr->left, value);
        // Right
        else return searchHelper(curr->right, value);
    }
    void height();
    void delet();
    
};

int main(){
    BiSTree b1;
    b1.insert(3);
    b1.insert(5);
    b1.insert(1);
    b1.insert(7);
    b1.display();
    cout << endl << b1.search(7)->data << endl;
    return 0;
}
