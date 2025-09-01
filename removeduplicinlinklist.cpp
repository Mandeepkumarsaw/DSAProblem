#include<bits/stdc++.h>
using namespace std;

struct ListNode   // Node structure for singly linked list

{
    int val;
    ListNode* next;

    ListNode(int x) : val(x),next(nullptr) {}   //Singe constructor
    ListNode(int x , ListNode* next ) : val(x),next(next) {}         //Multiple constructor
};




class Solution {
public:    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
     

        while(curr != nullptr && curr->next != nullptr){
         if(curr->val == curr->next->val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
          } else {
              curr = curr->next;
            }

        }
        return  head;
    }


    void PrintLL(ListNode* head) {
        cout<<"Unique Linked List: ";
        while(head != nullptr) {
             cout<<head->val<<"->";
             head=head->next;
        }
        cout<<"NULL\n";
        

    }
    
}; 



int main(){
    Solution obj;

    ListNode* node4 = new ListNode(3);
    ListNode* node3 = new ListNode(3,node4);
    ListNode* node2 = new ListNode(2,node3);
    ListNode* node1 = new ListNode(1,node2);
    ListNode* head = new ListNode(1,node1);

    cout<<"Original List : ";
    obj.PrintLL(head);

    ListNode* unique = obj.deleteDuplicates(head);


     cout<<"Reversed List : ";
     obj.PrintLL(unique);

    return 0;
}






//IMPORTANT
// 🔁 Variable Name Mapping and Descriptions


//1-STRUCT
// Old: val           → New: value
// Description: Integer value stored in each node of the linked list

// Old: next          → New: nextNode
// Description: Pointer to the next node in the linked list

// Old: x             → New: valInput / nodeValue
// Description: Constructor parameter used to initialize node value


//2-IN FUNC(deleteduplicates)
// Old: head          → New: listHead / originalHead
// Description: Head pointer of the linked list (entry point)

// Old: curr          → New: currentNode
// Description: Pointer used to traverse the linked list during duplicate removal

// Old: temp          → New: duplicateNode
// Description: Temporary pointer to hold and delete duplicate node


//3-INSIDE MAIN FUNC
// Old: unique        → New: deduplicatedHead
// Description: Head pointer of the list after duplicates are removed

// Old: PrintLL       → New: printLinkedList
// Description: Function to print the linked list in readable format

// Old: deleteDuplicates → New: removeDuplicates
// Description: Function to remove consecutive duplicate nodes from a sorted list

// Old: obj           → New: solutionInstance
// Description: Instance of the Solution class used to invoke methods

// Optional: node1, node2, ... → nodeA, nodeB, ...
// Description: Individual nodes used to manually construct the sample linked list