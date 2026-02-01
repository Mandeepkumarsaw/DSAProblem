#include<iostream>
#include<vector>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a,b;

        while(l1){
            a.push_back(l1->val);
            l1=l1->next;
        }

         while(l2){
            b.push_back(l2->val);
            l2=l2->next;
        }
        
        vector<int> res;
        int i=0, carry =0;

        while(i<a.size() || i<b.size()  || carry) {
            int sum = carry;
            if(i < a.size()) sum += a[i];
            if(i < b.size()) sum += b[i];

            res.push_back(sum%10);
            carry = sum/10;
            i++;
        }

        //convert vector to LL
        ListNode* head = new ListNode(res[0]);
        ListNode* curr = head;

        for(int k=1; k<res.size(); k++){
           curr->next = new ListNode(res[k]);
           curr=curr->next;
        }
        
        return head;

    }

     void printList(ListNode* head) {
    while (head != nullptr)
    {
        cout<< head->val << "->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
    }  
};

int main(){
    Solution obj;

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);       //1 -> 3 -> 5 

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(4);     //2 -> 4 -> 6

    ListNode* root = obj.addTwoNumbers(l1,l2);
    obj.printList(root);

    return 0;
}    