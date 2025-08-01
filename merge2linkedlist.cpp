#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class merge2linkedlist {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) tail->next = l1, l1 = l1->next;
            else tail->next = l2, l2 = l2->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head) cout << head->val << " -> ", head = head->next;
    cout << "NULL\n";
}

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    merge2linkedlist m;
    ListNode* merged = m.mergeTwoLists(l1, l2);
    printList(merged);
    return 0;
}