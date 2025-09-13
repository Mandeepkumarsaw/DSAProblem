#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class List {     //class 1 
public:    
      Node *head;
      Node *tail;
 public:
      List() {            //    List() : head(NULL) {}
        head = tail =  NULL;
      }

public:
    Node* flatten(Node* head) {
        if(head == NULL) return nullptr;

        Node* curr = head;
        while(curr != NULL) {
            if(curr->child !=NULL){               //if this then we perform 3 steps ie
                //1 --Flatten the child node usng recursion
                Node* next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                //2 -- Find tail
                while(curr->next != NULL) {
                    curr = curr->next;
                }

                //3 --attach tal with next ptr
                if(next != NULL) {
                     curr->next = next;
                     next->prev  = curr;
                }
               
            }else{
                curr=curr->next;
            }
        }

     return head;
        
    }

     void printLL(Node* head) {
        Node* temp = head;
            while (temp != NULL) {
                cout << temp->val;
        
               
                if (temp->child != NULL) {                 // // If there's a child, print it recursively
                    cout << " -> [Child: "; 
                    printLL(temp->child);                  // Recursive call to print child list
                    cout << "]";
                }
        
                cout << " <=> ";
                temp = temp->next;
               }
           cout << "NULL" << endl;
   }    
    


};

int main() {
    List dll;

    // Level 1
    Node* node1 = new Node(); node1->val = 1;
    Node* node2 = new Node(); node2->val = 2;
    Node* node3 = new Node(); node3->val = 3;

    node1->next = node2; node2->prev = node1;
    node2->next = node3; node3->prev = node2;

    // Level 2 (child of node2)
    Node* child1 = new Node(); child1->val = 4;
    Node* child2 = new Node(); child2->val = 5;

    child1->next = child2; child2->prev = child1;
    node2->child = child1;

    // Level 3 (child of child2)
    Node* grandChild = new Node(); grandChild->val = 6;
    child2->child = grandChild;

    // Assign head to list
    dll.head = node1;

    cout << "Original Multilevel List:\n";
    dll.printLL(dll.head);  // Will print only level 1

    // Flatten the list
    dll.head = dll.flatten(dll.head);

    cout << "\nFlattened List:\n";
    dll.printLL(dll.head);  // Should print 1->2->4->5->6->3->NULL

    
    return 0;
}