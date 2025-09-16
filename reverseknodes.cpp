#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // Check if k nodes exist
        while (cnt < k) {
            if (temp == NULL) return head;
            temp = temp->next;
            cnt++;
        }

        // Recursively call for the rest of the list
        ListNode* prevNode = reverseKGroup(temp, k);

        // Reverse current group
        temp = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }

        return prevNode;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Manually creating the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    int k = 3;

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* reversed = sol.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(reversed);

    return 0;
}