#include<bits/stdc++.h>
using namespace std;

struct Node {
       int val;
       Node* next;
       Node* random;

       Node(int x):val(x),next(nullptr),random(nullptr) {}
    //    Node(int x , Node* next):val(x),next(next) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        unordered_map<Node* , Node* > map;

        Node* head2 = new Node(head->val);   //first node copied
        Node* newTemp = head2;            //pointer for newnode created
        Node* oldTemp = head->next;    //pointer st from 2nd node bcoz first copied

        map[head] = head2;

        while(oldTemp != NULL) {              //CREATE COPY w/o random connection
        Node* copyNode = new Node(oldTemp->val); 
         map[oldTemp] = copyNode;
            newTemp->next = copyNode;
               oldTemp = oldTemp->next;
               newTemp = newTemp->next;

        }

        oldTemp=head; //reinitialize
        newTemp=head2;

        while(oldTemp != NULL){
             
             newTemp->random  =  map[oldTemp->random];
               oldTemp = oldTemp->next;
               newTemp = newTemp->next;
            }

            return head2;  
    }
};

void printList(Node *head) {
    while(head != nullptr){
        cout<<head->val<<"--next--> ";
            if(head->random)
            cout<<", ---random--> "<<head->random->val;
            else 
              cout<<", Random point to : NULL";
            cout<<endl;
        head=head->next;  
    }
}

int main(){
    Solution obj;

    // Create original list: 1 -> 2 -> 3
    Node* node1 = new Node(11);  //pass as head while calling
    Node* node2 = new Node(22);
    Node* node3 = new Node(33);

    node1->next = node2;
    node2->next = node3;

    node1->random = node3; // 1's random -> 3
    node2->random = node1; // 2's random -> 1
    node3->random = node2; // 3's random -> 2

    Node* newhead = obj.copyRandomList(node1);

    cout<<"Original List\n";
    printList(node1);

    cout<<"Copied List\n";
    printList(newhead);

    return 0;
}

