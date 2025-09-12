#include<bits/stdc++.h>
using namespace std;

struct ListNode {   //class 1 
    int val;
    ListNode * next;

    //Type - 1(Member Initialize List)                                                     Type-2(Assignment inside Constructor Body)
    ListNode(int x):val(x),next(nullptr) {}                       //ListNode(int x) {
                                                                  //val = x;    next = nullptr; }
    ListNode(int x,ListNode * next):val(x),next(next) {}
};

class List {     //class 1 
public:    
      ListNode *head;
      ListNode *tail;
 public:
      List() {            //    List() : head(NULL) {}
        head = tail =  NULL;
      }
 
   void push_front(int val){    //O(n)
            ListNode* newnode = new ListNode(val);   //Dynamic -we use new keyword bcoz data is present in memory after call ie get outside .
           
            // ListNode node1(val); //static method (drawback--when we get back(outside) from func call the val is get deleted ie no node created ),hence don't use it now.
            if(head ==  NULL) {
                head = tail = newnode;
                return;
            } else {
                newnode->next = head;    //(*node2).next = head
                head=newnode;
            }
      }

      ListNode* removeElements(ListNode* head, int def) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;

        ListNode* curr = dummy;

        while(curr->next != NULL) {
            if(curr->next->val == def) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
        
    }

      void printLL() {    //O(n) 
           ListNode *temp = head;
           while(temp != NULL) {
               cout<<temp->val<<"->";
               temp = temp->next;
           }
           cout<<"NULL"<<endl;
         }

};  

int main(){
     List ll;

   ll.push_front(2);
   ll.push_front(3);
   ll.push_front(2);
   ll.push_front(1);   

    
   ll.printLL();     //1->2->3->NULL

   ll.removeElements(ll.head,2);
   ll.printLL();


   return 0;
}


    

