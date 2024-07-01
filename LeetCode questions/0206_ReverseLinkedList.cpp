#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            
        }
        return prev;
    }
};

int main(void) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution sol;
    ListNode* reversed = sol.reverseList(head);

    while(reversed != nullptr) {
        std::cout << reversed->val << " ";
        reversed = reversed->next;
    }

    return 0;
}